/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_macros.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:57:28 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/21 14:39:07 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_MACROS_H
# define FRACTOL_MACROS_H

# define PI					3.14159265358979323846
# define LOG_2				0.69314718055994528623
# define INV_LOG_2			1.44269504089
# define LOG_4				0.60205999132
# define INV_LOG_4			1.66096404744
# define SQRT3_2			0.86602540378
# define SQRT_3				1.73205080757

# define WIDTH				600
# define HEIGHT				600

# define X					0
# define Y					1
# define RE					0
# define IM					1

# define MANDELBROT			0
# define JULIA				1
# define BURNINGSHIP		2
# define BURNINGJULIA		3
# define MANDEL4			4
# define GLYNN				5
# define NEWTON				6
# define BUDDHABROT			7
# define BARNSLEY			8
# define SIERPINSKI			9

# define MOUSE_PRESS		0x1
# define MOUSE_RELEASE		0x2
# define KEY_PRESS			0x4
# define KEY_ACTIVE			0x8
# define NOCOLOR			0x10
# define COLOR_PALETTE		0x20
# define COLOR_SMOOTHING	0x40
# define PAUSE				0x80
# define INTERACTIVE		0x100
# define AFFPARAMS			0x200
# define GENFILE			0x400
# define GENCOLOR			0x800
# define BUDDHACALC			0x1000

# define NTHREADS			4
# define NFRACTALES			10
# define NPALETTES			9

# define MAX_IT				50000000

#endif
