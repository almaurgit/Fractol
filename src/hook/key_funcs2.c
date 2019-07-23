/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:59:40 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:27:15 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_x(t_fractol *f)
{
	if (f->frac[f->nfrac].type)
		return ;
	f->flag &= ~NOCOLOR;
	f->flag |= COLOR_PALETTE;
	f->flag &= ~COLOR_SMOOTHING;
	launch_threads(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	key_s(t_fractol *f)
{
	if (f->frac[f->nfrac].type)
		return ;
	f->flag &= ~NOCOLOR;
	f->flag &= ~COLOR_PALETTE;
	f->flag |= COLOR_SMOOTHING;
	launch_threads(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	key_0(t_fractol *f)
{
	if (f->frac[f->nfrac].type)
		return ;
	f->flag |= NOCOLOR;
	f->flag &= ~COLOR_PALETTE;
	f->flag &= ~COLOR_SMOOTHING;
	launch_threads(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	key_p(t_fractol *f)
{
	int i;

	i = -1;
	if (f->npal != 7)
		return ;
	while (++i < 3)
		f->p.freq[i] = rand() % 3000 / (double)1000;
	i = -1;
	while (++i < 3)
		f->p.phase[i] = rand() % 3000 / (double)1000;
	init_palette8(f);
	launch_threads(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
