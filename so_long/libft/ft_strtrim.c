/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:19:15 by mabriel           #+#    #+#             */
/*   Updated: 2021/11/27 22:20:32 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t			len;
	unsigned int	start;

	if (!s || !set)
		return (NULL);
	len = ft_strlen(s);
	if (!ft_isset(*s, set) && !ft_isset(s[len - 1], set))
		return (ft_substr(s, 0, len));
	start = 0;
	while (ft_isset(s[start], set))
		start++;
	while (start < len && ft_isset(s[len - 1], set))
		len--;
	if (len == 0)
		return (ft_strdup("\0"));
	len = len - (size_t)start;
	return (ft_substr(s, start, len));
}
