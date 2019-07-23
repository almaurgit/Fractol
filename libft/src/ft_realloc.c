/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:14:16 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 14:25:46 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ap, size_t size, size_t new_size)
{
	void	*tmp;

	if (!ap)
		return (ft_memalloc(new_size));
	else
	{
		if (!(tmp = ft_memalloc(new_size)))
			return (NULL);
		ft_memmove(tmp, ap, size);
		free(ap);
		return (tmp);
	}
}
