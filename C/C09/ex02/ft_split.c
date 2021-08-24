/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:51:12 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/24 15:29:50 by mabriel          ###   ########.fr       */
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
	int	len;
	int	i;
	char *dest;

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
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
		if (!ft_is_charset(str[i])
			nbr++;
		while (str[i] && ft_is_charset(str[i],charset))
			i++;
	}
	return (nbr);		
}


#include <stdio.h>
int main()
{
	char *str = "  suis    pas   tres   beau   mais   tres con au revoir    ";
	char *charset = " ";
	printf("%d", ft_nbr_of_words(str, charset));
}


/*
char **ft_split(char *str, char *charset)
{
	
}*/
