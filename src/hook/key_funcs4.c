/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:13:38 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/19 16:22:43 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keys_nums(t_fractol *f)
{
	if (f->flag & INTERACTIVE)
		key_i(f);
	if (f->keyhook == KEY_NUM_0)
		f->nfrac = 0;
	if (f->keyhook == KEY_NUM_1)
		f->nfrac = 1;
	if (f->keyhook == KEY_NUM_2)
		f->nfrac = 2;
	if (f->keyhook == KEY_NUM_3)
		f->nfrac = 3;
	if (f->keyhook == KEY_NUM_4)
		f->nfrac = 4;
	if (f->keyhook == KEY_NUM_5)
		f->nfrac = 5;
	if (f->keyhook == KEY_NUM_6)
		f->nfrac = 6;
	if (f->keyhook == KEY_NUM_7)
		f->nfrac = 7;
	if (f->keyhook == KEY_NUM_8)
		f->nfrac = 8;
	if (f->keyhook == KEY_NUM_9)
		f->nfrac = 9;
	launch_threads(f);
	print_params(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	key_h(t_fractol *f)
{
	if (!(f->flag & (KEY_ACTIVE | INTERACTIVE)))
	{
		f->flag ^= AFFPARAMS;
		f->flag |= KEY_ACTIVE;
		reinit_back(f);
		print_params(f);
	}
}

void	key_i(t_fractol *f)
{
	if (f->nfrac != JULIA)
		return ;
	if (!(f->flag & KEY_ACTIVE))
	{
		f->flag ^= INTERACTIVE;
		f->flag |= KEY_ACTIVE;
		if (f->flag & INTERACTIVE)
		{
			interactive_affmandel(f);
			mlx_put_image_to_window(f->mlx, f->win, f->imgmand, WIDTH, 0);
		}
		else
			print_all(f);
	}
}

void	key_space(t_fractol *f)
{
	if (!(f->flag & KEY_ACTIVE))
	{
		f->flag ^= PAUSE;
		f->flag |= KEY_ACTIVE;
	}
}
