/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:29:24 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 20:03:00 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		quit(t_fractol *f)
{
	free_mlx(f);
	exit(EXIT_SUCCESS);
	return (1);
}

int		mouse_move(int x, int y, t_fractol *f)
{
	if ((f->nfrac == JULIA || f->nfrac == BURNINGJULIA)
		&& !(f->flag & MOUSE_PRESS))
	{
		if (!(f->flag & PAUSE))
			mouse_move_julia(f, x, y);
	}
	else
	{
		f->move[0] = x;
		f->move[1] = y;
	}
	return (1);
}

int		mouse_press(int button, int x, int y, t_fractol *f)
{
	f->x = x;
	f->y = y;
	f->move[0] = x;
	f->move[1] = y;
	f->flag |= MOUSE_PRESS;
	f->button = button;
	return (1);
}

int		mouse_release(int button, int x, int y, t_fractol *f)
{
	if (x || y || button)
		;
	f->flag &= ~MOUSE_PRESS;
	return (1);
}

void	init_mouse(t_fractol *f)
{
	f->mouse[SCROLLUP] = scrollup;
	f->mouse[SCROLLDOWN] = scrolldown;
	f->mouse[BUT1] = but1;
}
