/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:46:42 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/19 16:47:16 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_str1(t_fractol *f, int x, int y, char *str)
{
	mlx_string_put(f->mlx, f->win, x, y, 0xCBBAC8, str);
}

void	mlx_str2(t_fractol *f, int x, int y, char *str)
{
	mlx_string_put(f->mlx, f->win, x, y, 0x7070B0, str);
}

void	mlx3(t_fractol *f, int x, int y, char *str)
{
	mlx_string_put(f->mlx, f->win, x, y, 0xA05050, str);
}
