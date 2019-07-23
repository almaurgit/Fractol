/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:56:46 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/20 18:11:11 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "fractol_types.h"
# include "fractol_macros.h"
# include "keys_code.h"
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <fcntl.h>

/*
** fractol.c
*/
void	free_mlx(t_fractol *f);

/*
** COLORS/
*/

/*
** colors.c
*/
int		get_color(t_fractol *f, int i, int ind, double z_sq[2]);
int		get_color_newton(t_fractol *f, int i, double z[2]);

/*
** palettes1.c
*/
void	init_palettes(t_fractol *f);

/*
** palettes2.c
*/
void	init_palette5(t_fractol *f);
void	init_palette6(t_fractol *f);
void	init_palette7(t_fractol *f);
void	init_palette8(t_fractol *f);
void	init_palette_chaos(t_fractol *f);

/*
** FRACTALS/
*/

/*
** buddha.c
*/
int		buddhabrot(t_fractol *f);

/*
** fractales.c
*/
int		mandelbrot(t_fractol *f, int x, int y, int ind);
int		julia(t_fractol *f, int x, int y, int ind);
int		burningship(t_fractol *f, int x, int y, int ind);
int		burningjulia(t_fractol *f, int x, int y, int ind);

/*
** fractales2.c
*/
int		mandel4(t_fractol *f, int x, int y, int ind);
int		glynn(t_fractol *f, int x, int y, int ind);
int		newton(t_fractol *f, int x, int y);

/*
** fractales_chaos.c
*/
int		barnsley(t_fractol *f);
int		sierpinski(t_fractol *f);

/*
** HOOK/
*/

/*
** hook.c
*/
int		fct_hook(t_fractol *f);
void	mlx_hook_fractol(t_fractol *f);

/*
** key_funcs*.c
*/
void	keys_cols(t_fractol *f);
void	keys_pals(t_fractol *f);
void	key_x(t_fractol *f);
void	key_s(t_fractol *f);
void	key_0(t_fractol *f);
void	key_p(t_fractol *f);
void	key_page_up(t_fractol *f);
void	key_page_down(t_fractol *f);
void	key_up(t_fractol *f);
void	key_down(t_fractol *f);
void	keys_nums(t_fractol *f);
void	key_h(t_fractol *f);
void	key_i(t_fractol *f);
void	key_space(t_fractol *f);
void	key_f(t_fractol *f);
void	key_g(t_fractol *f);
void	key_r(t_fractol *f);
void	key_esc(t_fractol *f);

/*
** key_hook.c
*/
void	init_key(t_fractol *f);
int		key_press(int keyhook, t_fractol *f);
int		key_release(int keyhook, t_fractol *f);

/*
** mouse_buttons.c
*/
void	but1(t_fractol *f);
void	scrollup(t_fractol *f);
void	scrolldown(t_fractol *f);
void	mouse_move_julia(t_fractol *f, int x, int y);

/*
** mouse_hook.c
*/
int		quit(t_fractol *f);
int		mouse_move(int x, int y, t_fractol *f);
int		mouse_press(int button, int x, int y, t_fractol *f);
int		mouse_release(int button, int x, int y, t_fractol *f);
void	init_mouse(t_fractol *f);

/*
** HUD/
*/

/*
** hud_infos.c
*/
void	reinit_back(t_fractol *f);
void	print_params(t_fractol *f);
void	print_all(t_fractol *f);

/*
** hud_menu.c
*/
void	print_hud(t_fractol *f);

/*
** mlx_string.c
*/
void	mlx_str1(t_fractol *f, int x, int y, char *str);
void	mlx_str2(t_fractol *f, int x, int y, char *str);
void	mlx3(t_fractol *f, int x, int y, char *str);

/*
** RUN/
*/

/*
** init.c
*/
void	init_fractales(t_fractol *f);
int		init_mlx(t_fractol *f, char *av);

/*
** threads.c
*/
void	fill_pixel(char *img_str, int x, int y, int color);
void	interactive_affmandel(t_fractol *f);
int		launch_threads(t_fractol *f);

#endif
