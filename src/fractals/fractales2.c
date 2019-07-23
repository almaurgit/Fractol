/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:29:51 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:25:20 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandel4(t_fractol *f, int x, int y, int ind)
{
	double	c[3];
	double	z[2];
	double	z_sq[2];
	int		i;
	int		bailout;

	c[0] = (f->frac[4].range_x * ((double)x / WIDTH)) + f->frac[4].x[0];
	c[1] = f->frac[4].y[1] - (f->frac[4].range_y * ((double)y / HEIGHT));
	ft_bzero(z, 2 * sizeof(*z));
	ft_bzero(z_sq, 2 * sizeof(*z_sq));
	i = 0;
	bailout = (f->flag & COLOR_SMOOTHING ? 1 << 24 : 4);
	while (i < f->frac[4].max_it && (z_sq[0] + z_sq[1]) < bailout)
	{
		c[2] = z_sq[0] - z_sq[1];
		z[1] = 4 * c[2] * z[0] * z[1] + c[1];
		z[0] = c[2] * c[2] - 4 * z_sq[0] * z_sq[1] + c[0];
		z_sq[0] = z[0] * z[0];
		z_sq[1] = z[1] * z[1];
		++i;
	}
	if (z_sq[0] + z_sq[1] >= 4)
		return (get_color(f, i, ind, z_sq));
	return (0);
}

static void	glynn_loop(double z[2], double z_sq[2])
{
	double mod;
	double r;
	double theta;

	mod = sqrt(z_sq[0] + z_sq[1]);
	r = sqrt(mod * mod * mod);
	theta = 1.5 * atan2(z[1], z[0]);
	z[0] = r * cos(theta) - 0.2;
	z[1] = r * sin(theta);
	z_sq[0] = z[0] * z[0];
	z_sq[1] = z[1] * z[1];
}

int			glynn(t_fractol *f, int x, int y, int ind)
{
	double	z[2];
	double	z_sq[2];
	int		i;
	int		bailout;

	z[0] = (f->frac[5].range_x * ((double)x / WIDTH)) + f->frac[5].x[0];
	z[1] = f->frac[5].y[1] - (f->frac[5].range_y * ((double)y / HEIGHT));
	z_sq[0] = z[0] * z[0];
	z_sq[1] = z[1] * z[1];
	i = 0;
	bailout = (f->flag & COLOR_SMOOTHING ? 1 << 8 : 4);
	while (i++ < f->frac[5].max_it && z_sq[0] + z_sq[1] < bailout)
		glynn_loop(z, z_sq);
	if (z_sq[0] + z_sq[1] >= 4)
		return (get_color(f, i, ind, z_sq));
	return (0);
}

int			newton(t_fractol *f, int x, int y)
{
	double	z[2];
	int		i;
	double	tmp;
	double	old[2];

	z[0] = (f->frac[6].range_x * ((double)x / WIDTH)) + f->frac[6].x[0];
	z[1] = f->frac[6].y[1] - (f->frac[6].range_y * ((double)y / HEIGHT));
	i = 0;
	while (i < f->frac[6].max_it)
	{
		old[0] = z[0];
		old[1] = z[1];
		tmp = (z[0] * z[0] + z[1] * z[1]) * (z[0] * z[0] + z[1] * z[1]);
		z[0] = (2 * z[0] * tmp - z[0] * z[0] + z[1] * z[1]) / (3 * tmp);
		z[1] = (2 * z[1] * (tmp + old[0])) / (3 * tmp);
		tmp = (z[0] - old[0]) * (z[0] - old[0]);
		tmp += (z[1] - old[1]) * (z[1] - old[1]);
		if (tmp < 0.000001)
			return (get_color_newton(f, i, z));
		++i;
	}
	return (0);
}
