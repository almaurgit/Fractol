/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:54:49 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/21 14:39:09 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_pixel(char *img_str, int x, int y, int color)
{
	t_color tmp;

	tmp = *(t_color *)&color;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	img_str[0 + 4 * x + 4 * WIDTH * y] = color;
	img_str[1 + 4 * x + 4 * WIDTH * y] = color >> 8;
	img_str[2 + 4 * x + 4 * WIDTH * y] = color >> 16;
	img_str[3 + 4 * x + 4 * WIDTH * y] = color >> 24;
}

void		interactive_affmandel(t_fractol *f)
{
	int x;
	int y;
	int i;
	int size;

	i = 0;
	size = WIDTH * HEIGHT;
	while (i < size)
	{
		x = i % WIDTH;
		y = i / WIDTH;
		fill_pixel(f->strimgmand, x, y, f->frac[0].f(f, x, y));
		++i;
	}
}

static void	fractale_foreach(t_fractol *f, int thr)
{
	int x;
	int y;
	int i;
	int size;
	int	color;

	i = thr;
	size = WIDTH * HEIGHT;
	while (i < size)
	{
		x = i % WIDTH;
		y = i / WIDTH;
		color = f->frac[f->nfrac].f(f, x, y, i);
		fill_pixel(f->strimg, x, y, color);
		i += NTHREADS;
	}
}

static void	*thread_func(void *arg)
{
	t_fractol	*f;
	pthread_t	current_thread;
	int			i;

	f = (t_fractol *)arg;
	i = 0;
	current_thread = pthread_self();
	while (i < NTHREADS && f->threads[i] != current_thread)
		++i;
	if (i != NTHREADS)
		fractale_foreach(f, i);
	pthread_exit(0);
}

int			launch_threads(t_fractol *f)
{
	int i;
	int ret;

	i = 0;
	if (f->frac[f->nfrac].type % 2)
		return (f->frac[f->nfrac].f(f));
	while (i < NTHREADS)
	{
		ret = pthread_create(&(f->threads[i]), NULL, thread_func, f);
		if (ret)
		{
			free_mlx(f);
			exit(EXIT_FAILURE);
		}
		++i;
	}
	i = 0;
	while (i < NTHREADS)
	{
		pthread_join((f->threads[i]), NULL);
		++i;
	}
	return (1);
}
