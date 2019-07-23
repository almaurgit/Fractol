/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:33:55 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 16:19:23 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishexa(char *s, int start, int end)
{
	int		i;

	i = start;
	if (!s || !*s || (end - start > 7))
		return (0);
	while (i <= end)
	{
		if (!ft_isdigithexa((int)s[i]))
			return (0);
		i++;
	}
	return (1);
}
