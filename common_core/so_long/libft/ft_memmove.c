/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:26:45 by mabriel           #+#    #+#             */
/*   Updated: 2021/11/23 16:09:13 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*source;
	char		*desti;

	source = (const char *)src;
	desti = (char *)dst;
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			desti[i] = source[i];
			i++;
		}
	}
	else if (src < dst)
	{
		i = len + 1;
		while (--i)
			desti[i - 1] = source[i - 1];
	}
	return (dst);
}
