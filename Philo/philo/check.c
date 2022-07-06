/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:22:02 by mabriel           #+#    #+#             */
/*   Updated: 2022/07/06 19:19:19 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_count(int n)
{
	int				i;
	unsigned int	nbr;

	i = 1;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	else
		nbr = n;
	while (nbr >= 10)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = ft_strlen(str) - 1;
	j = 0;
	while (i > j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i--;
		j++;
	}
	return (str);
}

static void	ft_magic(char *dst, int n, int sign)
{
	int	i;

	i = 0;
	dst[i] = n % 10 + '0';
	while (n >= 10)
	{
		i++;
		n = n / 10;
		dst[i] = n % 10 + '0';
	}
	if (sign == -1)
	{
		dst[i + 1] = '-';
		dst[i + 2] = '\0';
	}
	else
		dst[i + 1] = '\0';
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*dst;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	dst = (char *)malloc(sizeof(char) * ft_count(n) + 1);
	if (!dst)
		return (NULL);
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	ft_magic(dst, n, sign);
	return (ft_strrev(dst));
}
