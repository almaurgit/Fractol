/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:04:44 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 21:16:37 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(t_fractol *f, char *av)
{
	int i;

	i = 0;
	ft_putstr("usage: ");
	ft_putstr(av);
	ft_putendl(" [fractal]");
	write(1, "\t\t [fractal] = [", 17);
	while (i < NFRACTALES)
	{
		ft_putstr(f->frac[i].name);
		if (i < NFRACTALES - 1)
			write(1, " | ", 3);
		++i;
	}
	write(1, "]\n", 2);
}

void		free_mlx(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->imgmand)
		mlx_destroy_image(f->mlx, f->imgmand);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
		mlx_del(f->mlx);
	free(f);
	f = NULL;
}

int			main(int ac, char **av)
{
	t_fractol *f;

	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
		return (0);
	if (init_mlx(f, av[ac - 1]) && ac == 2)
	{
		launch_threads(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		print_all(f);
		mlx_hook_fractol(f);
	}
	else
		usage(f, av[0]);
	free_mlx(f);
	return (0);
}
