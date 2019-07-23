/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:34:30 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:30:20 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_key_ter(t_fractol *f)
{
	f->key[KEY_0] = key_0;
	f->key[KEY_1] = keys_pals;
	f->key[KEY_2] = keys_pals;
	f->key[KEY_3] = keys_pals;
	f->key[KEY_4] = keys_pals;
	f->key[KEY_5] = keys_pals;
	f->key[KEY_6] = keys_pals;
	f->key[KEY_7] = keys_pals;
	f->key[KEY_8] = keys_pals;
	f->key[KEY_9] = keys_pals;
	f->key[KEY_NUM_0] = keys_nums;
	f->key[KEY_NUM_1] = keys_nums;
	f->key[KEY_NUM_2] = keys_nums;
	f->key[KEY_NUM_3] = keys_nums;
	f->key[KEY_NUM_4] = keys_nums;
	f->key[KEY_NUM_5] = keys_nums;
	f->key[KEY_NUM_6] = keys_nums;
	f->key[KEY_NUM_7] = keys_nums;
	f->key[KEY_NUM_8] = keys_nums;
	f->key[KEY_NUM_9] = keys_nums;
}

static void	init_key_bis(t_fractol *f)
{
	f->key[KEY_DEL] = keys_cols;
	f->key[KEY_ANTISLASH] = keys_cols;
	f->key[KEY_EQUALS] = keys_cols;
	f->key[KEY_CLOSE_BRACKET] = keys_cols;
	f->key[KEY_DASH] = keys_cols;
	f->key[KEY_OPEN_BRACKET] = keys_cols;
	f->key[KEY_SHIFT_2] = keys_cols;
	f->key[KEY_RETURN] = keys_cols;
	f->key[KEY_SLASH] = keys_cols;
	f->key[KEY_APOSTROPHE] = keys_cols;
	f->key[KEY_POINT] = keys_cols;
	f->key[KEY_SEMICOLON] = keys_cols;
}

void		init_key(t_fractol *f)
{
	f->key[KEY_PAGE_UP] = key_page_up;
	f->key[KEY_PAGE_DOWN] = key_page_down;
	f->key[KEY_UP] = key_up;
	f->key[KEY_DOWN] = key_down;
	f->key[KEY_P] = key_p;
	f->key[KEY_S] = key_s;
	f->key[KEY_G] = key_g;
	f->key[KEY_F] = key_f;
	f->key[KEY_R] = key_r;
	f->key[KEY_I] = key_i;
	f->key[KEY_X] = key_x;
	f->key[KEY_H] = key_h;
	f->key[KEY_SPACE] = key_space;
	f->key[KEY_ESC] = key_esc;
	init_key_bis(f);
	init_key_ter(f);
}

int			key_press(int keyhook, t_fractol *f)
{
	f->flag |= KEY_PRESS;
	f->keyhook = keyhook;
	return (1);
}

int			key_release(int keyhook, t_fractol *f)
{
	if (keyhook)
		;
	f->flag &= ~KEY_PRESS & ~KEY_ACTIVE;
	return (1);
}
