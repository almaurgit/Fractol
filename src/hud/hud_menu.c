/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:45:10 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 19:55:56 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	back_hud(t_fractol *f)
{
	int x;
	int endx;
	int starty;
	int endy;
	int y;

	x = WIDTH;
	endx = 2 * WIDTH;
	starty = HEIGHT / 3;
	endy = HEIGHT;
	y = starty;
	while (x < endx)
	{
		y = starty;
		while (y < endy)
		{
			if (x < WIDTH + 4 || x > endx - 5
				|| y < starty + 4 || y > endy - 5)
				mlx_pixel_put(f->mlx, f->win, x, y, 0x8080A0);
			else
				mlx_pixel_put(f->mlx, f->win, x, y, 0x161630);
			++y;
		}
		++x;
	}
}

static void	hud1(t_fractol *f)
{
	int x;
	int y;

	x = WIDTH - 5;
	y = HEIGHT / 3 + 15;
	mlx_str1(f, x + 20, y + 5, "Colors :");
	mlx_str2(f, x + 20, y + 25, "0 - 9");
	mlx_str2(f, x + 20, y + 45, "S (smooth)");
	mlx_str2(f, x + 20, y + 65, "X (palettes)");
	mlx_str1(f, x + 180, y + 5, "Fractals :");
	mlx_str2(f, x + 180, y + 25, "Num. 0 - 9");
	mlx_str1(f, x + 180, y + 45, "Psychedelic mode");
	mlx_str2(f, x + 180, y + 65, "P (with color 8)");
	mlx_str1(f, x + 380, y + 5, "Iterations :");
	mlx_str2(f, x + 380, y + 25, "Page up / Page down");
	mlx_str2(f, x + 380, y + 45, "Arrows Up / Down");
	mlx_str1(f, x + 20, y + 105, "Hide params");
	mlx_str2(f, x + 20, y + 125, "H (for better perfomances)");
	mlx_str1(f, x + 300, y + 105, "Pause (Julia/Burningjulia)");
	mlx_str2(f, x + 300, y + 125, "Space bar");
}

static void	hud2(t_fractol *f)
{
	int x;
	int y;

	x = WIDTH - 5;
	y = HEIGHT / 3 + 15;
	mlx_str1(f, x + 20, y + 165, "Interactive mode (Julia only)");
	mlx_str2(f, x + 20, y + 185, "I (Mandelbrot/Julia interaction)");
	mlx_str1(f, x + 20, y + 225, "Generate fdf format file :");
	mlx_str2(f, x + 20, y + 245, "F (no colors)");
	mlx_str2(f, x + 20, y + 265, "G (with hexadecimal colors)");
	mlx_str1(f, x + 380, y + 165, "Reset params");
	mlx_str2(f, x + 380, y + 185, "R");
	mlx_str1(f, x + 380, y + 225, "Quit");
	mlx_str2(f, x + 380, y + 245, "Esc");
}

static void	hud3(t_fractol *f)
{
	int x;
	int y;

	x = WIDTH - 5;
	y = HEIGHT / 3 + 15;
	mlx_str1(f, x + 20, y + 305, "Zoom");
	mlx_str2(f, x + 20, y + 325, "Mouse scroll");
	mlx_str1(f, x + 150, y + 305, "Move");
	mlx_str2(f, x + 150, y + 325, "Left click");
	mlx_str1(f, x + 260, y + 305, "Modify param (Julia/Burningjulia)");
	mlx_str2(f, x + 260, y + 325, "Mouse move");
}

void		print_hud(t_fractol *f)
{
	int x;
	int y;

	x = WIDTH;
	y = 0;
	back_hud(f);
	hud1(f);
	hud2(f);
	hud3(f);
}
