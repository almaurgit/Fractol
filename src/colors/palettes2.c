/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:13:34 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:18:39 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_palette5(t_fractol *f)
{
	int		i;
	double	freq;

	i = 0;
	freq = 1. / 200.;
	while (i < 200)
	{
		f->palettes[4].pal[i] = (int)(cos(2 * PI * (freq * 2.55 * i
			+ 1.7)) * 127 + 127) << 16;
		f->palettes[4].pal[i] |= ((int)(cos(2 * PI * (freq * 1.56 * i
			+ 1.4)) * 127 + 127) << 8);
		f->palettes[4].pal[i] |= (int)(cos(2 * PI * (freq * 2.9 * i
			+ 1.35)) * 127 + 127);
		f->palettes[4].pal[399 - i] = f->palettes[4].pal[i];
		++i;
	}
	f->palettes[4].ncol = 400;
}

void	init_palette6(t_fractol *f)
{
	int		i;
	double	freq;

	i = 0;
	freq = 1. / 500.;
	while (i < 500)
	{
		f->palettes[5].pal[i] = (int)(cos(2 * PI * (freq * 0.17 * i
			+ 0.37)) * 127 + 127) << 16;
		f->palettes[5].pal[i] |= ((int)(cos(2 * PI * (freq * 2.74 * i
			+ 0.39)) * 127 + 127) << 8);
		f->palettes[5].pal[i] |= (int)(cos(2 * PI * (freq * 2. * i
			+ 2.29)) * 127 + 127);
		f->palettes[5].pal[999 - i] = f->palettes[5].pal[i];
		++i;
	}
	f->palettes[5].ncol = 1000;
}

void	init_palette7(t_fractol *f)
{
	f->palettes[6].pal[0] = 0xAA77BB;
	f->palettes[6].pal[1] = 0xCC77BB;
	f->palettes[6].pal[2] = 0xBB5599;
	f->palettes[6].pal[3] = 0x88AA99;
	f->palettes[6].pal[4] = 0x433494;
	f->palettes[6].pal[5] = 0x5e16fb;
	f->palettes[6].pal[6] = 0x57eef5;
	f->palettes[6].pal[7] = 0xBCc64b;
	f->palettes[6].pal[8] = 0xFFFFFF;
	f->palettes[6].pal[9] = 0xFFFFFF;
	f->palettes[6].ncol = 10;
}

void	init_palette8(t_fractol *f)
{
	int		i;
	double	freq;

	i = 0;
	freq = 1. / 200.;
	while (i < 200)
	{
		f->palettes[7].pal[i] = (int)(cos(2 * PI * (freq * f->p.freq[0] * i
			+ f->p.phase[0])) * 127 + 127) << 16;
		f->palettes[7].pal[i] |= ((int)(cos(2 * PI * (freq * f->p.freq[1] * i
			+ f->p.phase[1])) * 127 + 127) << 8);
		f->palettes[7].pal[i] |= (int)(cos(2 * PI * (freq * f->p.freq[2] * i
			+ f->p.phase[2])) * 127 + 127);
		f->palettes[7].pal[399 - i] = f->palettes[7].pal[i];
		++i;
	}
	f->palettes[7].ncol = 400;
}

void	init_palette_chaos(t_fractol *f)
{
	f->palettes[8].ncol = 3;
	f->palettes[8].pal[0] = 0x000001;
	f->palettes[8].pal[1] = 0x000100;
	f->palettes[8].pal[2] = 0x010000;
}
