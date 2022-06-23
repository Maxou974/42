/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:51:12 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/25 18:00:50 by mabriel          ###   ########.fr       */
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

int	ft_nbr_of_words(char *str, char *sep)
{
	int	nb_words;

	nb_words = !ft_is_charset(*str, sep) && *str != 0;
	while (*(++str))
		nb_words += ft_is_charset(str[-1], sep) && !ft_is_charset(*str, sep);
	return (nb_words);
}

char	**empty(void)
{
	char	**words;

	words = malloc(sizeof(char *));
	if (words)
		*words = 0;
	return (words);
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
	while (j < ft_nbr_of_words(str, charset))
	{
		while (ft_is_charset(str[i], charset))
			i++;
		start = i;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
		tab[j] = ft_ultimate_strdup(str, start, i - 1);
		if (!tab[j])
			return (empty());
		j++;
	}
	tab[j] = 0;
	return (tab);
}
