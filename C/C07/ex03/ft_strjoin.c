/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:46:00 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/19 22:05:26 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	int		i;
	int		j;
	char	*dest;

	i = -1;
	j = 0;
	while (++i < size && strs[i])
		j = j + ft_strlen(strs[i]);
	dest = malloc(sizeof(char) * (j + 1 + ((size - 1) * ft_strlen(sep))));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < size)
	{
		ft_strcpy(&dest[j], strs[i]);
		j = j + ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(&dest[j], sep);
			j = j + ft_strlen(sep);
		}
	}
	dest[j] = '\0';
	return (dest);
}
