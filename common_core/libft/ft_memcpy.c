/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:35:39 by mabriel           #+#    #+#             */
/*   Updated: 2021/11/23 16:12:53 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr1;
	const char	*ptr2;

	i = -1;
	if (!dst && !src)
		return (NULL);
	ptr1 = (char *)dst;
	ptr2 = (const char *)src;
	while (++i < n)
		ptr1[i] = ptr2[i];
	return (dst);
}
