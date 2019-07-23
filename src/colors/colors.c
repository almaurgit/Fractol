/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:24:40 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 19:08:29 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	interpolate(int start, int end, double percent)
{
	return ((int)(start + percent * (end - start)));
}

static int	color_interpolate(int color1, int color2, double percent)
{
	int red;
	int green;
	int blue;

	red = interpolate((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, percent);
	green = interpolate((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, percent);
	blue = interpolate((color1) & 0xFF, (color2) & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

static int	color_smoothing(t_fractol *f, int it, double z_sq[2])
{
	double	nu;
	int		color2;
	int		color;
	double	i;

	i = (double)it;
	if (it <= 2)
		return (f->palettes[f->npal].pal[1]);
	if (i <= f->frac[f->nfrac].max_it)
	{
		nu = log((log(z_sq[0] + z_sq[1]) / 2) * INV_LOG_2) * INV_LOG_2;
		i = i + 1 - nu;
	}
	color = f->palettes[f->npal].pal[(int)i % f->palettes[f->npal].ncol];
	color2 = f->palettes[f->npal].pal[((int)i + 1) % f->palettes[f->npal].ncol];
	color = color_interpolate(color, color2, i - (int)i);
	return (color);
}

int			get_color(t_fractol *f, int i, int ind, double z_sq[2])
{
	int color;

	color = 0xFFFFFF;
	if (f->flag & NOCOLOR)
		color = 0xFFFFFF;
	else if (f->flag & COLOR_PALETTE || f->nfrac > BURNINGJULIA)
		color = f->palettes[f->npal].pal[i % f->palettes[f->npal].ncol];
	else if (f->flag & COLOR_SMOOTHING && f->nfrac <= BURNINGJULIA)
		color = color_smoothing(f, i, z_sq);
	if (f->flag & GENFILE)
	{
		f->file[ind][0] = i;
		f->file[ind][1] = color;
	}
	return (color);
}

int			get_color_newton(t_fractol *f, int i, double z[2])
{
	int					color;
	double				ampl;
	int					j;

	ampl = sin(1. / 50. * PI * (i % 255)) * 127.5 + 127.5;
	if (z[1] < -0.5)
		j = 2;
	else if (z[1] > 0.5)
		j = 1;
	else
		j = 0;
	color = f->palettes[8].pal[j];
	color = ((color >> (j * 8)) * (int)ampl) << (j * 8);
	return (color);
}
