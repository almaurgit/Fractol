/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:27:07 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 21:16:44 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_fractale(t_fractol *f, char *str)
{
	int i;

	i = 0;
	while (i < NFRACTALES && ft_strcmp(str, f->frac[i].name))
		++i;
	if (i >= NFRACTALES)
		return (0);
	f->nfrac = i;
	return (1);
}

void		init_fractales(t_fractol *f)
{
	f->frac[0] = (t_fractale){"mandelbrot",
	0, 100, 1, {-2, 0.75}, {-1.375, 1.375}, 2.75, 2.75, mandelbrot};
	f->frac[1] = (t_fractale){"julia",
	0, 100, 1, {-1.5, 1.5}, {-1.5, 1.5}, 3, 3, julia};
	f->frac[2] = (t_fractale){"burningship",
	0, 100, 1, {-2.5, 1.5}, {-1.5, 2.5}, 4, 4, burningship};
	f->frac[3] = (t_fractale){"burningjulia",
	0, 100, 1, {-1.5, 1.5}, {-1.5, 1.5}, 3, 3, burningjulia};
	f->frac[4] = (t_fractale){"mandel4",
	0, 100, 1, {-1.5, 1.5}, {-1.5, 1.5}, 3, 3, mandel4};
	f->frac[5] = (t_fractale){"glynn",
	0, 100, 1, {-1.5, 1.5}, {-1.5, 1.5}, 3, 3, glynn};
	f->frac[6] = (t_fractale){"newton",
	0, 100, 1, {-1.5, 1.5}, {-1.5, 1.5}, 3, 3, newton};
	f->frac[7] = (t_fractale){"buddhabrot",
	1, 10000, 1, {-2, 0.75}, {-1.375, 1.375}, 2.75, 2.75, buddhabrot};
	f->frac[8] = (t_fractale){"barnsley",
	1, 50000, 1, {-4, 4}, {0, 10.5}, 8, 10.5, barnsley};
	f->frac[9] = (t_fractale){"sierpinski",
	1, 50000, 1, {-1.25, 1.25}, {-0.25, 2.25}, 2.5, 2.5, sierpinski};
}

int			init_mlx(t_fractol *f, char *av)
{
	int bpp;
	int s_l;
	int endian;

	ft_bzero(f, sizeof(t_fractol));
	init_fractales(f);
	init_mouse(f);
	init_key(f);
	init_palettes(f);
	if (!get_fractale(f, av))
		return (0);
	f->flag |= COLOR_SMOOTHING | AFFPARAMS;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH * 2, HEIGHT, "fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->strimg = mlx_get_data_addr(f->img, &(bpp), &(s_l), &(endian));
	f->imgmand = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->strimgmand = mlx_get_data_addr(f->imgmand, &(bpp), &(s_l), &(endian));
	return (1);
}
