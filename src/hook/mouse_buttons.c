/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_buttons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:32:16 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:29:01 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	but1(t_fractol *f)
{
	t_fractale	*frac;

	frac = &f->frac[f->nfrac];
	frac->x[0] = frac->x[0] - ((f->move[0] - f->x) / WIDTH) * frac->range_x;
	frac->x[1] = frac->x[0] + frac->range_x;
	frac->y[1] = frac->y[1] + ((f->move[1] - f->y) / HEIGHT) * frac->range_y;
	frac->y[0] = frac->y[1] - frac->range_y;
	f->x = f->move[0];
	f->y = f->move[1];
	print_params(f);
	launch_threads(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	scrollup(t_fractol *f)
{
	double		lastrange_x;
	double		lastrange_y;
	t_fractale	*fr;

	fr = &f->frac[f->nfrac];
	if (f->flag & INTERACTIVE || fr->zoom >= 1e+15)
	{
		f->flag &= ~MOUSE_PRESS;
		return ;
	}
	lastrange_x = fr->range_x;
	lastrange_y = fr->range_y;
	fr->range_x *= 1. / 1.25;
	fr->range_y *= 1. / 1.25;
	fr->x[0] += (f->x / WIDTH) * (lastrange_x - fr->range_x);
	fr->x[1] = fr->x[0] + fr->range_x;
	fr->y[1] -= (f->y / HEIGHT) * (lastrange_y - fr->range_y);
	fr->y[0] = fr->y[1] - fr->range_y;
	fr->zoom *= 1.25;
	f->flag &= ~MOUSE_PRESS;
	launch_threads(f);
	print_params(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	scrolldown(t_fractol *f)
{
	double		lastrange_x;
	double		lastrange_y;
	t_fractale	*fr;

	fr = &f->frac[f->nfrac];
	if (f->flag & INTERACTIVE || fr->zoom <= 1.e-15)
	{
		f->flag &= ~MOUSE_PRESS;
		return ;
	}
	lastrange_x = fr->range_x;
	lastrange_y = fr->range_y;
	fr->range_x *= 1.25 / 1.;
	fr->range_y *= 1.25 / 1.;
	fr->x[0] -= (f->x / WIDTH) * (fr->range_x - lastrange_x);
	fr->x[1] = fr->x[0] + fr->range_x;
	fr->y[1] += (f->y / HEIGHT) * (fr->range_y - lastrange_y);
	fr->y[0] = fr->y[1] - fr->range_y;
	fr->zoom /= 1.25;
	f->flag &= ~MOUSE_PRESS;
	launch_threads(f);
	print_params(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	mouse_move_julia(t_fractol *f, int x, int y)
{
	if (f->flag & INTERACTIVE)
	{
		f->c_julia[0] = f->frac[0].range_x * ((double)(x - WIDTH) / WIDTH);
		f->c_julia[0] += f->frac[0].x[0];
		f->c_julia[1] = -(f->frac[0].range_y * ((double)y / HEIGHT));
		f->c_julia[1] += f->frac[0].y[1];
	}
	else
	{
		f->c_julia[0] = f->frac[f->nfrac].range_x * ((double)x / WIDTH);
		f->c_julia[0] += f->frac[f->nfrac].x[0];
		f->c_julia[1] = -(f->frac[f->nfrac].range_y * ((double)y / HEIGHT));
		f->c_julia[1] += f->frac[f->nfrac].y[1];
	}
	launch_threads(f);
	print_params(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
