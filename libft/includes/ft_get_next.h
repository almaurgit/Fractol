/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:17:50 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/05 11:18:53 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_H
# define FT_GET_NEXT_H
# define BUFF_SIZE 1024

enum			e_ret
{
	ok = 1,
	done = 0,
	fail = -1
};

typedef struct	s_gnlfile
{
	int			fd;
	char		**line;
}				t_gnlfile;

int				get_next(int fd, char **line, char sep);
int				get_next_line(int fd, char **line);

#endif
