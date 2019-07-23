/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:10:06 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 21:34:03 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	back_params(t_fractol *f)
{
	int x;
	int endx;
	int endy;
	int y;

	x = WIDTH;
	endx = 2 * WIDTH;
	y = 0;
	endy = HEIGHT / 3;
	while (x < endx)
	{
		y = 0;
		while (y < endy)
		{
			if (x < WIDTH + 4 || x > endx - 5 || y < 5)
				mlx_pixel_put(f->mlx, f->win, x, y, 0x8080A0);
			else
				mlx_pixel_put(f->mlx, f->win, x, y, 0x161630);
			++y;
		}
		++x;
	}
}

void		reinit_back(t_fractol *f)
{
	int x;
	int y;
	int endx;
	int endy;

	x = WIDTH + 5;
	y = 5;
	endx = 2 * WIDTH - 5;
	endy = HEIGHT / 3;
	while (x < endx)
	{
		y = 4;
		while (++y < endy)
			mlx_pixel_put(f->mlx, f->win, x, y, 0x161630);
		++x;
	}
	if (!(f->flag & AFFPARAMS))
	{
		mlx3(f, 668, 65, "   ____ ___   ___   _____ ______ _  ____   __ ");
		mlx3(f, 670, 80, "  / __// _ \\ / _ | / ___//_  __/( )/ __ \\ / / ");
		mlx3(f, 672, 95, " / _/ / , _// __ |/ /__   / /   |// /_/ // /__");
		mlx3(f, 674, 110, "/_/  /_/|_|/_/ |_|\\___/  /_/      \\____//____/");
	}
}

static void	params2(t_fractol *f)
{
	t_fractale	*fr;
	int			x;
	int			y;
	char		str[32];

	fr = &(f->frac[f->nfrac]);
	x = WIDTH;
	y = 0;
	sprintf(str, "%.9g", fr->x[0]);
	mlx_str2(f, x + 288, y + 60, str);
	sprintf(str, "%.9g", fr->x[1]);
	mlx_str2(f, x + 450, y + 60, str);
	mlx_str1(f, x + 250, y + 80, "y :");
	sprintf(str, "%.9g", fr->y[0]);
	mlx_str2(f, x + 288, y + 80, str);
	sprintf(str, "%.9g", fr->y[1]);
	mlx_str2(f, x + 450, y + 80, str);
	if (f->nfrac != JULIA && f->nfrac != BURNINGJULIA)
		return ;
	sprintf(str, "%.5g", f->c_julia[0]);
	mlx_str1(f, x + 10, y + 120, "c = ");
	mlx_str2(f, x + 50, y + 120, str);
	sprintf(str, "%.5g", f->c_julia[1]);
	mlx_str2(f, x + 140, y + 120, " + i * ");
	mlx_str2(f, x + 210, y + 120, str);
}

void		print_params(t_fractol *f)
{
	t_fractale	*fr;
	int			x;
	int			y;
	char		str[32];

	if (!(f->flag & AFFPARAMS) || f->flag & INTERACTIVE)
		return ;
	else
	{
		fr = &(f->frac[f->nfrac]);
		x = WIDTH;
		y = 0;
		reinit_back(f);
		sprintf(str, "%.9g", fr->zoom);
		mlx_str1(f, x + 270, y + 10, fr->name);
		mlx_str1(f, x + 10, y + 60, "Zoom :");
		mlx_str2(f, x + 80, y + 60, "x");
		mlx_str2(f, x + 90, y + 60, str);
		sprintf(str, "%-10d", fr->max_it);
		mlx_str1(f, x + 10, y + 80, "Iterations :");
		mlx_str2(f, x + 140, y + 80, str);
		mlx_str1(f, x + 250, y + 60, "x :");
		params2(f);
	}
}

void		print_all(t_fractol *f)
{
	back_params(f);
	reinit_back(f);
	print_params(f);
	print_hud(f);
}
