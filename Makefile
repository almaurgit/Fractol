# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 11:17:50 by amaurel           #+#    #+#              #
#    Updated: 2019/07/21 12:51:12 by amaurel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_PURPLE=\x1b[35m
_RED=\x1b[31m
_GREEN=\x1b[32m
_BOLD=\x1b[1m
_DEFAULT=\x1b[0m

CC=cc

MAKE=make

RM=rm

override CFLAGS += -Wall -Werror -Wextra -Iincludes -Ilibft/includes -Imlx/minilibx_macos/

override LDFLAGS += -Llibft -lft -L mlx/minilibx_macos -lmlx

override FRMFLAGS += -framework OpenGL -framework AppKit

NAME=	fractol

SRC = 	fractol.c \
		run/init.c \
		run/threads.c \
		hook/hook.c \
		hook/mouse_hook.c \
		hook/mouse_buttons.c \
		hook/key_hook.c \
		hook/key_funcs1.c \
		hook/key_funcs2.c \
		hook/key_funcs3.c \
		hook/key_funcs4.c \
		hook/key_funcs5.c \
		fractals/fractales.c \
		fractals/fractales2.c \
		fractals/fractales_chaos.c \
		fractals/buddha.c \
		colors/colors.c \
		colors/palettes1.c \
		colors/palettes2.c \
		hud/hud_infos.c \
		hud/hud_menu.c \
		hud/mlx_string.c

SRC:=$(addprefix src/, ${SRC})


HEADER= keys_code.h fractol.h fractol_macros.h fractol_types.h
HEADER:=$(addprefix includes/, ${HEADER})

LIBS=libft/libft.a mlx/minilibx_macos/libmlx.a

OBJ=${SRC:.c=.o}

.PHONY: all libft mlx clean fclean re

all: $(NAME)
	@printf "$(_BOLD)$(_GREEN)[fractol ok]$(_DEFAULT)\n"

debug: CFLAGS += -g
debug: RULE=debug
debug: $(NAME)

asan: CFLAGS += -fsanitize=address -g3
asan: RULE=asan
asan: $(NAME)

opti: CFLAGS += -O2
opti: RULE = opti
opti: $(NAME)

ofast: CFLAGS += -Ofast
ofast: RULE = ofast
ofast: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	@printf "${_BOLD}${_GREEN}[ fractol]${_DEFAULT} $(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(FRMFLAGS)\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(FRMFLAGS)

%.o: %.c $(HEADER)
	@printf "${_BOLD}${_GREEN}[ fractol]${_DEFAULT} $(CC) $(CFLAGS) -c $< -o $@\n"
	@$(CC) $(CFLAGS) -c $< -o $@

libft: libft/libft.a

libft/libft.a:
	@printf "${_BOLD}${_PURPLE}[   libft]${_DEFAULT} $(MAKE) -C libft $(RULE)\n"
	@$(MAKE) -C libft $(RULE)

mlx: mlx/minilibx_macos/libmlx.a

mlx/minilibx_macos/libmlx.a:
	@printf "${_BOLD}${_RED}[     mlx]${_DEFAULT} $(MAKE) -C mlx/minilibx_macos $(RULE)\n"
	@$(MAKE) -C mlx/minilibx_macos $(RULE)

clean:
	@$(RM) -f $(OBJ)
	@$(MAKE) -C libft clean
	@$(MAKE) -C mlx/minilibx_macos clean

fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -rf $(NAME).dSYM
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx/minilibx_macos fclean


re: fclean all
