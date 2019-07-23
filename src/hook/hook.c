/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:16:16 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/19 16:29:02 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fct_hook(t_fractol *f)
{
	if (f->keyhook < 0 || f->keyhook > 261
		|| f->button < 0 || f->button > 7)
		return (0);
	if (f->flag & KEY_PRESS && f->key[f->keyhook])
		f->key[f->keyhook](f);
	if (f->flag & MOUSE_PRESS && f->mouse[f->button] && f->nfrac != BUDDHABROT)
		f->mouse[f->button](f);
	return (1);
}

void	mlx_hook_fractol(t_fractol *f)
{
	mlx_hook(f->win, 4, 1L << 2, mouse_press, f);
	mlx_hook(f->win, 5, 1L << 3, mouse_release, f);
	mlx_hook(f->win, 2, 1L << 0, key_press, f);
	mlx_hook(f->win, 3, 1L << 1, key_release, f);
	mlx_hook(f->win, 6, 1L << 8, mouse_move, f);
	mlx_hook(f->win, 17, 1L << 5, quit, f);
	mlx_loop_hook(f->mlx, fct_hook, f);
	mlx_loop(f->mlx);
}
