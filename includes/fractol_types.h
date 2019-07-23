/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:56:04 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 21:04:50 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_TYPES_H
# define FRACTOL_TYPES_H

# include "fractol_macros.h"
# include <pthread.h>

typedef void	(*t_key)();
typedef void	(*t_mouse)();
typedef int		t_point[2];

typedef struct	s_color
{
	unsigned int		blue : 8;
	unsigned int		green : 8;
	unsigned int		red : 8;
	unsigned int		alpha : 8;
}				t_color;

typedef struct	s_psyche
{
	double		freq[3];
	double		phase[3];
}				t_psyche;

typedef struct	s_palette
{
	int			pal[1000];
	int			ncol;

}				t_palette;

typedef struct	s_fractale
{
	char		*name;
	char		type;
	int			max_it;
	double		zoom;
	double		x[2];
	double		y[2];
	double		range_x;
	double		range_y;
	int			(*f)();
}				t_fractale;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*strimg;
	void		*imgmand;
	char		*strimgmand;

	t_fractale	frac[NFRACTALES];
	int			nfrac;
	int			flag;

	pthread_t	threads[NTHREADS];

	t_mouse		mouse[8];
	int			button;
	t_point		mouse_move[2];

	t_key		key[280];
	int			keyhook;

	t_palette	palettes[NPALETTES];
	int			npal;

	double		x;
	double		y;
	double		move[2];
	double		c_julia[2];
	int			buddha[WIDTH][HEIGHT];

	t_psyche	p;
	int			file[WIDTH * HEIGHT][2];
}				t_fractol;

#endif
