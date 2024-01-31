/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:36:56 by mabriel           #+#    #+#             */
/*   Updated: 2021/12/07 00:37:56 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	return (s);
}

static int	ft_count(unsigned int n, int base)
{
	long	nbr;
	int		i;

	i = 0;
	nbr = n;
	while (nbr >= (unsigned int)base)
	{
		nbr = nbr / base;
		i++;
	}
	return (++i);
}

static int	ft_base(int n, int maj)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	if (n >= 10 && n <= 15 && maj)
		return (n + 'A' - 10);
	if (n >= 10 && n <= 15 && !maj)
		return (n + 'a' - 10);
	else
		return (n);
}
/* maj == 0 for abcdef */
/* maj != 0 for ABDCEF */

char	*ft_uitoa_base_maj(unsigned int n, int base, int maj)
{
	char		*s;
	long		nbr;
	int			i;

	s = (char *)malloc(sizeof(char) * ft_count(n, base) + 1);
	if (!s)
		return (NULL);
	nbr = n;
	i = 0;
	s[i] = (char)ft_base((unsigned int)nbr % base, maj);
	while (nbr >= (unsigned int)base)
	{
		i++;
		nbr = nbr / base;
		s[i] = (char)ft_base((unsigned int)nbr % base, maj);
	}
	s[i + 1] = '\0';
	return (ft_strrev(s));
}
