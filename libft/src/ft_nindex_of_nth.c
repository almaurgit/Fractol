/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nindex_of_nth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:16:19 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 14:16:36 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** gives the index of the n-th occurence of c in s
**
** input :	s	- the string to search in
**			c	- the character to search
**			n	- the occurence of c to search in s
**
** output :	(int) the index of the n-th occurence of c in s
*/

int	ft_nindex_of_nth(const char *s, char c, int n, int max)
{
	int	k;
	int	nth;

	k = 0;
	nth = 0;
	if (!s)
		return (-1);
	while (k < max && s[k])
	{
		if (s[k] == c)
		{
			if (n == nth)
				return (k);
			else
				nth++;
		}
		k++;
	}
	return (-1);
}
