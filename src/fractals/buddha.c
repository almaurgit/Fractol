/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:06:39 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:54:15 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	buddha_color(t_fractol *f)
{
	int i;
	int x;
	int y;
	int color;
	int size;

	i = 0;
	size = WIDTH * HEIGHT;
	while (i < size)
	{
		x = i % WIDTH;
		y = i / WIDTH;
		color = f->buddha[x][y];
		if (color > 4)
		{
			color = f->palettes[f->npal].pal[color % f->palettes[f->npal].ncol];
			fill_pixel(f->strimg, y, x, color);
		}
		else
			fill_pixel(f->strimg, y, x, 0);
		++i;
	}
}

static int	escape(t_fractol *f, double c[2])
{
	double	z[2];
	double	z_sq[2];
	int		i;

	i = 0;
	ft_bzero(z_sq, 2 * sizeof(*z_sq));
	ft_bzero(z, 2 * sizeof(*z));
	while (i < f->frac[7].max_it && (z_sq[0] + z_sq[1]) < 4)
	{
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = z_sq[0] - z_sq[1] + c[0];
		z_sq[0] = z[0] * z[0];
		z_sq[1] = z[1] * z[1];
		++i;
	}
	if ((z_sq[0] + z_sq[1]) < 4)
		return (0);
	return (1);
}

static void	compute_buddha(t_fractol *f, double c[2])
{
	double	z[2];
	double	z_sq[2];
	int		x;
	int		y;
	int		i;

	i = 0;
	ft_bzero(z_sq, 2 * sizeof(*z_sq));
	ft_bzero(z, 2 * sizeof(*z));
	while (i < f->frac[7].max_it && z_sq[0] + z_sq[1] < 4)
	{
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = z_sq[0] - z_sq[1] + c[0];
		z_sq[0] = z[0] * z[0];
		z_sq[1] = z[1] * z[1];
		x = (int)((z[0] - f->frac[7].x[0]) * WIDTH / f->frac[7].range_x);
		y = (int)((z[1] - f->frac[7].y[0]) * HEIGHT / f->frac[7].range_y);
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && i > 15)
			f->buddha[x][y]++;
		++i;
	}
}

int			buddhabrot(t_fractol *f)
{
	int			i;
	int			size;
	double		c[2];
	t_fractale	*fr;

	i = 0;
	size = WIDTH * HEIGHT;
	fr = &f->frac[BUDDHABROT];
	if (!(f->flag & BUDDHACALC))
	{
		while (i < size)
		{
			i++;
			c[0] = fr->range_x * ((double)(i % WIDTH) / WIDTH) + fr->x[0];
			c[1] = fr->range_y * ((double)(i / WIDTH) / HEIGHT) + fr->y[0];
			if (!escape(f, c))
				continue ;
			compute_buddha(f, c);
		}
		f->flag |= BUDDHACALC;
	}
	buddha_color(f);
	return (0);
}
