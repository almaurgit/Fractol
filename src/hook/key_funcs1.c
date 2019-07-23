/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:53:01 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:27:46 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reinit_pal(t_fractol *f)
{
	int i;

	i = 0;
	while (i < 3)
		f->p.freq[i++] = 1.;
	i = 0;
	while (i < 3)
		f->p.phase[i++] = 1.;
}

static void	keys_cols_bis(t_fractol *f)
{
	if (f->keyhook == KEY_RETURN && f->p.phase[0] < 3.)
		f->p.phase[0] += 0.01;
	else if (f->keyhook == KEY_SHIFT_2 && f->p.phase[0] > 0)
		f->p.phase[0] -= 0.01;
	else if (f->keyhook == KEY_APOSTROPHE && f->p.phase[1] < 3.)
		f->p.phase[1] += 0.01;
	else if (f->keyhook == KEY_SLASH && f->p.phase[1] > 0)
		f->p.phase[1] -= 0.01;
	else if (f->keyhook == KEY_SEMICOLON && f->p.phase[2] < 3.)
		f->p.phase[2] += 0.01;
	else if (f->keyhook == KEY_POINT && f->p.phase[2] > 0)
		f->p.phase[2] -= 0.01;
}

void		keys_cols(t_fractol *f)
{
	if (f->npal != 7)
		return ;
	if (f->keyhook == KEY_DEL && f->p.freq[0] < 3.)
		f->p.freq[0] += 0.01;
	else if (f->keyhook == KEY_ANTISLASH && f->p.freq[0] > 0)
		f->p.freq[0] -= 0.01;
	else if (f->keyhook == KEY_EQUALS && f->p.freq[1] < 3.)
		f->p.freq[1] += 0.01;
	else if (f->keyhook == KEY_CLOSE_BRACKET && f->p.freq[1] > 0)
		f->p.freq[1] -= 0.01;
	else if (f->keyhook == KEY_DASH && f->p.freq[2] < 3.)
		f->p.freq[2] += 0.01;
	else if (f->keyhook == KEY_OPEN_BRACKET && f->p.freq[2] > 0)
		f->p.freq[2] -= 0.01;
	else
		keys_cols_bis(f);
	if (f->keyhook == KEY_Y)
		reinit_pal(f);
	init_palette8(f);
	launch_threads(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void		keys_pals(t_fractol *f)
{
	if (f->flag & NOCOLOR)
	{
		f->flag &= ~NOCOLOR;
		f->flag |= COLOR_SMOOTHING;
	}
	if (f->keyhook == KEY_1)
		f->npal = 0;
	if (f->keyhook == KEY_2)
		f->npal = 1;
	if (f->keyhook == KEY_3)
		f->npal = 2;
	if (f->keyhook == KEY_4)
		f->npal = 3;
	if (f->keyhook == KEY_5)
		f->npal = 4;
	if (f->keyhook == KEY_6)
		f->npal = 5;
	if (f->keyhook == KEY_7)
		f->npal = 6;
	if (f->keyhook == KEY_8)
		f->npal = 7;
	if (f->keyhook == KEY_9)
		f->npal = 8;
	launch_threads(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
