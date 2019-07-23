/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:34:15 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 14:34:32 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isint(char *s, int start, int end)
{
	int			i;
	intmax_t	n;

	i = start;
	if (!s || !*s)
		return (0);
	if (s[i] == '-')
	{
		i++;
		if (i > end)
			return (0);
	}
	while (i <= end)
	{
		if (!ft_isdigit((int)s[i]))
			return (0);
		i++;
	}
	n = ft_atoimax(s + start);
	if (n != (int)n)
		return (0);
	return (1);
}
