/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nindex_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:14:40 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 14:25:33 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** gives the index of the first occurence of c in s
**
** input :	s	- the string to search in
**			c	- the character to search
**
** output :	(int) the index of first occurence of c in s
*/

int	ft_nindex_of(const char *s, char c, int max)
{
	return (ft_nindex_of_nth(s, c, 0, max));
}
