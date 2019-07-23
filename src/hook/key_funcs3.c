/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:04:09 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 19:57:17 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_page_up(t_fractol *f)
{
	char	type;

	type = f->frac[f->nfrac].type;
	if (f->frac[f->nfrac].max_it < MAX_IT - (10 + type * 10000))
		f->frac[f->nfrac].max_it += (10 + type * 10000);
	else
		f->frac[f->nfrac].max_it = MAX_IT;
	launch_threads(f);
	print_params(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	key_page_down(t_fractol *f)
{
	char	type;

	type = f->frac[f->nfrac].type;
	if (f->frac[f->nfrac].max_it > (10 + type * 10000))
		f->frac[f->nfrac].max_it -= (10 + type * 10000);
	else
		f->frac[f->nfrac].max_it = 1;
	launch_threads(f);
	print_params(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	key_up(t_fractol *f)
{
	if (!(f->flag & KEY_ACTIVE))
	{
		if (f->frac[f->nfrac].max_it < MAX_IT)
			f->frac[f->nfrac].max_it++;
		f->flag |= KEY_ACTIVE;
	}
	else
		return ;
	launch_threads(f);
	print_params(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	key_down(t_fractol *f)
{
	if (!(f->flag & KEY_ACTIVE))
	{
		if (f->frac[f->nfrac].max_it > 1)
			f->frac[f->nfrac].max_it--;
		f->flag |= KEY_ACTIVE;
	}
	else
		return ;
	launch_threads(f);
	print_params(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
