/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:51:12 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/24 19:25:47 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_ultimate_strdup(char *src, int start, int end)
{
	int		len;
	int		i;
	char	*dest;

	len = end - start + 1;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		dest[i] = src[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_nbr_of_words(char *str, char *charset)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		while (ft_is_charset(str[i], charset))
			i++;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
		nbr++;
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
	}
	return (nbr);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		start;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_nbr_of_words(str, charset) + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (ft_is_charset(str[i], charset))
			i++;
		start = i;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
		tab[j] = malloc(sizeof(char *) * (i - start + 2));
		tab[j] = ft_ultimate_strdup(str, start, i - 1);
		j++;
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
	}
	tab[j] = 0;
	return (tab);
}
