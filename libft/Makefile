# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 21:01:03 by amaurel           #+#    #+#              #
#    Updated: 2019/07/20 20:18:30 by amaurel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_PURPLE=\x1b[35m
_BOLD=\x1b[1m
_DEFAULT=\x1b[0m

NAME = libft.a
SRC_NAME = 	putchar putstr memset bzero memcpy memccpy memmove memchr memcmp \
			strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr \
			strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum isascii \
			isprint toupper tolower putendl putnbr putchar_fd putstr_fd \
		  	putendl_fd putnbr_fd memalloc memdel strnew strdel strclr striter \
		  	striteri strmap strmapi strequ strnequ strsub strjoin strrev \
			strtrim strsplit itoa lstnew lstdelone lstdel lstadd lstiter lstmap \
		 	atoi_base itoa_base convert_base convert_base_int pow sqrt \
		 	factorial is_prime strcapitalize get_next realloc nindex_of \
		 	nindex_of_nth atoimax isspace max next_space skip_spaces isint \
		 	ishexa isdigithexa abs
SRC = $(addsuffix .c, $(SRC_NAME))
SRC := $(addprefix src/ft_, $(SRC))
OBJ = $(SRC:.c=.o)
HD = libft.h
HD := $(addprefix includes/, $(HD))
CC = cc
override CFLAGS += -Wall -Wextra -Werror -Iincludes

all: $(NAME)
	@printf "${_BOLD}${_PURPLE}[libft ok]${_DEFAULT}\n"

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

$(NAME): $(OBJ)
	@printf "${_BOLD}${_PURPLE}[   libft]${_DEFAULT} ar rcs $(NAME) $(OBJ)\n"
	@ar rcs $(NAME) $(OBJ)
	@printf "${_BOLD}${_PURPLE}[   libft]${_DEFAULT} ranlib $(NAME)\n"
	@ranlib $(NAME)

%.o: %.c $(HD)
	@printf "${_BOLD}${_PURPLE}[   libft]${_DEFAULT} $(CC) $(CFLAGS) -c -o $@ $<\n"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
