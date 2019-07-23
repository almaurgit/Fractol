/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:13:21 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 20:03:08 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	write_file(t_fractol *f, int fd)
{
	int i;
	int size;

	i = 0;
	size = WIDTH * HEIGHT;
	while (i < size)
	{
		dprintf(fd, "%d", f->file[i][0]);
		if (f->flag & GENCOLOR)
			dprintf(fd, ",0x%X", f->file[i][1]);
		if (i % WIDTH == WIDTH - 1)
			dprintf(fd, "\n");
		else
			dprintf(fd, " ");
		++i;
	}
}

void		key_f(t_fractol *f)
{
	int		fd;
	char	*name;

	name = f->frac[f->nfrac].name;
	if (!(f->flag & KEY_ACTIVE) && f->nfrac <= GLYNN)
	{
		ft_putendl("Generating fdf format file from current fractal.");
		if ((fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
		{
			free_mlx(f);
			exit(EXIT_FAILURE);
		}
		f->flag |= GENFILE | KEY_ACTIVE;
		launch_threads(f);
		write_file(f, fd);
		close(fd);
		ft_putstr("File : \"");
		ft_putstr(name);
		ft_putendl("\" generated.");
		f->flag &= ~GENFILE;
	}
}

void		key_g(t_fractol *f)
{
	f->flag |= GENCOLOR;
	key_f(f);
	f->flag &= ~GENCOLOR;
}

void		key_r(t_fractol *f)
{
	f->flag &= ~INTERACTIVE;
	f->flag |= AFFPARAMS;
	init_fractales(f);
	launch_threads(f);
	print_all(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void		key_esc(t_fractol *f)
{
	free_mlx(f);
	exit(EXIT_SUCCESS);
}
