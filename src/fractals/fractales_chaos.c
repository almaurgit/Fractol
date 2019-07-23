/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales_chaos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:30:35 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 19:08:00 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	barnsley2(int randp, double z[2])
{
	double tmp;

	if (randp < 860)
	{
		tmp = -0.04 * z[0] + 0.85 * z[1] + 1.6;
		z[0] = 0.85 * z[0] + 0.04 * z[1];
		z[1] = tmp;
	}
	else if (randp < 930)
	{
		tmp = 0.23 * z[0] + 0.22 * z[1] + 1.6;
		z[0] = 0.2 * z[0] - 0.26 * z[1];
		z[1] = tmp;
	}
	else
	{
		tmp = 0.26 * z[0] + 0.24 * z[1] + 0.44;
		z[0] = -0.15 * z[0] + 0.28 * z[1];
		z[1] = tmp;
	}
}

int			barnsley(t_fractol *f)
{
	int		p[2];
	int		i;
	double	z[2];
	int		randp;

	ft_bzero(&z, sizeof(*z));
	ft_bzero(f->strimg, sizeof(int) * WIDTH * HEIGHT);
	i = 0;
	while (i < f->frac[8].max_it)
	{
		p[0] = (int)((z[0] - f->frac[8].x[0]) * WIDTH / f->frac[8].range_x);
		p[1] = (int)((-z[1] + f->frac[8].y[1]) * WIDTH / f->frac[8].range_y);
		if (p[0] >= 0 && p[0] < WIDTH && p[1] >= 0 && p[1] < HEIGHT)
			fill_pixel(f->strimg, p[0], p[1], f->palettes[6].pal[f->npal]);
		randp = rand() % 1000;
		if (randp < 10)
		{
			z[0] = 0;
			z[1] = 0.16 * z[1];
		}
		else
			barnsley2(randp, z);
		++i;
	}
	return (1);
}

int			sierpinski(t_fractol *f)
{
	double				p[2];
	int					pix[2];
	int					i;
	int					rand_edge;
	static const double	edge[3][2] = {{-1, 0}, {1, 0}, {0, SQRT_3}};

	ft_bzero(f->strimg, sizeof(int) * WIDTH * HEIGHT);
	p[0] = rand() % 2000 / (double)1000 - 1;
	p[1] = rand() % 1732 / (double)1000;
	i = 0;
	while (i < f->frac[9].max_it)
	{
		pix[0] = (int)((p[0] - f->frac[9].x[0]) * WIDTH / f->frac[9].range_x);
		pix[1] = (int)((-p[1] + f->frac[9].y[1]) * WIDTH / f->frac[9].range_y);
		if (pix[0] >= 0 && pix[0] < WIDTH && pix[1] >= 0 && pix[1] < HEIGHT)
			fill_pixel(f->strimg, pix[0], pix[1], f->palettes[6].pal[f->npal]);
		rand_edge = rand() % 3;
		p[0] = (p[0] + edge[rand_edge][0]) / 2;
		p[1] = (p[1] + edge[rand_edge][1]) / 2;
		++i;
	}
	return (1);
}
