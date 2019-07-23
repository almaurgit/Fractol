/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:21:46 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 14:24:53 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check whether c is a space or not
**
** input :	c	- the character to check
**
** output :	(int) 1 if c is a space, 0 if not
*/

int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v')
		return (1);
	else if (c == ' ' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
