/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:11:38 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:18:16 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_palette1(t_fractol *f)
{
	int i;

	i = 0;
	f->palettes[0].pal[i] = (66 << 16) | (30 << 8) | 15;
	f->palettes[0].pal[i + 1] = (25 << 16) | (7 << 8) | 6;
	f->palettes[0].pal[i + 2] = (9 << 16) | (1 << 8) | 47;
	f->palettes[0].pal[i + 3] = (4 << 16) | (4 << 8) | 73;
	f->palettes[0].pal[i + 4] = (0 << 16) | (7 << 8) | 100;
	f->palettes[0].pal[i + 5] = (12 << 16) | (44 << 8) | 138;
	f->palettes[0].pal[i + 6] = (24 << 16) | (82 << 8) | 177;
	f->palettes[0].pal[i + 7] = (57 << 16) | (125 << 8) | 209;
	f->palettes[0].pal[i + 8] = (34 << 16) | (181 << 8) | 229;
	f->palettes[0].pal[i + 9] = (211 << 16) | (236 << 8) | 248;
	f->palettes[0].pal[i + 10] = (241 << 16) | (233 << 8) | 191;
	f->palettes[0].pal[i + 11] = (248 << 16) | (201 << 8) | 95;
	f->palettes[0].pal[i + 12] = (255 << 16) | (170 << 8) | 0;
	f->palettes[0].pal[i + 13] = (204 << 16) | (128 << 8) | 0;
	f->palettes[0].pal[i + 14] = (153 << 16) | (87 << 8) | 0;
	f->palettes[0].pal[i + 15] = (106 << 16) | (52 << 8) | 3;
	f->palettes[0].ncol = 16;
}

static void	init_palette2(t_fractol *f)
{
	int		i;
	double	fq[3];

	i = 0;
	fq[0] = (1. / 100.) * 2 * PI;
	fq[1] = (1. / 100.) * 2 * PI;
	fq[2] = (1. / 100.) * 2 * PI;
	while (i < 1000)
	{
		f->palettes[1].pal[i] = (int)(cos(fq[0] * i) * 127 + 127) << 16;
		f->palettes[1].pal[i] |= ((int)(cos(fq[1] * i + 2.1) * 127 + 127) << 8);
		f->palettes[1].pal[i] |= (int)(cos(fq[2] * i + 4.2) * 127 + 127);
		++i;
	}
	f->palettes[1].ncol = 1000;
}

static void	init_palette3(t_fractol *f)
{
	int		i;
	double	freq;

	i = 0;
	freq = 2 * PI * 1. / 16.;
	while (i < 1000)
	{
		f->palettes[2].pal[i] = (int)(cos(freq * i) * 127 + 127) << 16;
		f->palettes[2].pal[i] |= ((int)(cos(freq * i + 0.6) * 127 + 127) << 8);
		f->palettes[2].pal[i] |= (int)(cos(freq * i + 1.2) * 127 + 127);
		++i;
	}
	f->palettes[2].ncol = 1000;
}

static void	init_palette4(t_fractol *f)
{
	int		i;
	double	freq;

	i = 0;
	freq = 1. / 50.;
	while (i < 50)
	{
		f->palettes[3].pal[i] = (int)(cos(2 * PI * (freq * i)) * 127
			+ 127) << 16;
		f->palettes[3].pal[i] |= ((int)(cos(2 * PI * (freq * i)) * 127
			+ 127) << 8);
		f->palettes[3].pal[i] |= (int)(cos(2 * PI * (freq * i)) * 127 + 127);
		f->palettes[3].pal[98 - i] = f->palettes[3].pal[i];
		++i;
	}
	f->palettes[3].ncol = 99;
}

void		init_palettes(t_fractol *f)
{
	init_palette1(f);
	init_palette2(f);
	init_palette3(f);
	init_palette4(f);
	init_palette5(f);
	init_palette6(f);
	init_palette7(f);
	init_palette8(f);
	init_palette_chaos(f);
}
