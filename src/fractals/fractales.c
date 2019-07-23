/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:17:07 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:20:23 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_fractol *f, int x, int y, int ind)
{
	double	c[2];
	double	z[2];
	double	z_sq[2];
	int		i;
	int		bailout;

	c[0] = (f->frac[0].range_x * ((double)x / WIDTH)) + f->frac[0].x[0];
	c[1] = f->frac[0].y[1] - (f->frac[0].range_y * ((double)y / HEIGHT));
	ft_bzero(z, 2 * sizeof(*z));
	ft_bzero(z_sq, 2 * sizeof(*z_sq));
	i = 0;
	bailout = (f->flag & COLOR_SMOOTHING ? 1 << 8 : 4);
	while (i < f->frac[0].max_it && (z_sq[0] + z_sq[1]) < bailout)
	{
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = z_sq[0] - z_sq[1] + c[0];
		z_sq[0] = z[0] * z[0];
		z_sq[1] = z[1] * z[1];
		++i;
	}
	if (z_sq[0] + z_sq[1] >= 4)
		return (get_color(f, i, ind, z_sq));
	return (0);
}

int		julia(t_fractol *f, int x, int y, int ind)
{
	double	c[2];
	double	z[2];
	double	z_sq[2];
	int		i;
	int		bailout;

	c[0] = f->c_julia[0];
	c[1] = f->c_julia[1];
	z[0] = (f->frac[1].range_x * ((double)x / WIDTH)) + f->frac[1].x[0];
	z[1] = f->frac[1].y[1] - (f->frac[1].range_y * ((double)y / HEIGHT));
	z_sq[0] = z[0] * z[0];
	z_sq[1] = z[1] * z[1];
	i = 0;
	bailout = (f->flag & COLOR_SMOOTHING ? 1 << 8 : 4);
	while (i < f->frac[1].max_it && (z_sq[0] + z_sq[1]) < bailout)
	{
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = z_sq[0] - z_sq[1] + c[0];
		z_sq[0] = z[0] * z[0];
		z_sq[1] = z[1] * z[1];
		++i;
	}
	if (z_sq[0] + z_sq[1] >= 4)
		return (get_color(f, i, ind, z_sq));
	return (0);
}

int		burningship(t_fractol *f, int x, int y, int ind)
{
	double	c[2];
	double	z[2];
	double	z_sq[2];
	int		i;
	int		bailout;

	c[0] = (f->frac[2].range_x * ((double)x / WIDTH)) + f->frac[2].x[0];
	c[1] = -(f->frac[2].y[1] - (f->frac[2].range_y * ((double)y / HEIGHT)));
	ft_bzero(z, 2 * sizeof(*z));
	ft_bzero(z_sq, 2 * sizeof(*z_sq));
	i = 0;
	bailout = (f->flag & COLOR_SMOOTHING ? 1 << 8 : 4);
	while (i < f->frac[2].max_it && (z_sq[0] + z_sq[1]) < bailout)
	{
		z[1] = 2 * ft_abs(z[0] * z[1]) + c[1];
		z[0] = z_sq[0] - z_sq[1] + c[0];
		z_sq[0] = z[0] * z[0];
		z_sq[1] = z[1] * z[1];
		++i;
	}
	if (z_sq[0] + z_sq[1] >= 4)
		return (get_color(f, i, ind, z_sq));
	return (0);
}

int		burningjulia(t_fractol *f, int x, int y, int ind)
{
	double	c[2];
	double	z[2];
	double	z_sq[2];
	int		i;
	int		bailout;

	c[0] = f->c_julia[0];
	c[1] = f->c_julia[1];
	z[0] = (f->frac[3].range_x * ((double)x / WIDTH)) + f->frac[3].x[0];
	z[1] = f->frac[3].y[1] - (f->frac[3].range_y * ((double)y / HEIGHT));
	z_sq[0] = z[0] * z[0];
	z_sq[1] = z[1] * z[1];
	i = 0;
	bailout = (f->flag & COLOR_SMOOTHING ? 1 << 8 : 4);
	while (i < f->frac[3].max_it && (z_sq[0] + z_sq[1]) < bailout)
	{
		z[1] = 2 * ft_abs(z[0] * z[1]) + c[1];
		z[0] = z_sq[0] - z_sq[1] + c[0];
		z_sq[0] = z[0] * z[0];
		z_sq[1] = z[1] * z[1];
		++i;
	}
	if (z_sq[0] + z_sq[1] >= 4)
		return (get_color(f, i, ind, z_sq));
	return (0);
}
