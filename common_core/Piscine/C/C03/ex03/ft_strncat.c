/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:49:03 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/09 17:21:54 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	lengh_dest;

	i = 0;
	lengh_dest = ft_strlen(dest);
	while (i < nb && src[i])
	{
		dest[lengh_dest + i] = src[i];
		i++;
	}
	dest[lengh_dest + i] = '\0';
	return (dest);
}
