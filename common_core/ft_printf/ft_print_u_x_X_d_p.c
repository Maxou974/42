/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_x_X_d_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:25:58 by mabriel           #+#    #+#             */
/*   Updated: 2021/12/07 00:47:22 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x(unsigned int n, int *char_numbers)
{
	char	*tmp;

	tmp = ft_uitoa_base_maj(n, 16, 0);
	ft_putstr_fd(tmp, 1);
	*char_numbers = *char_numbers + ft_strlen(tmp);
	free(tmp);
}

void	ft_print_xmaj(unsigned int n, int *char_numbers)
{
	char	*tmp;

	tmp = ft_uitoa_base_maj(n, 16, 1);
	ft_putstr_fd(tmp, 1);
	*char_numbers = *char_numbers + ft_strlen(tmp);
	free(tmp);
}

void	ft_print_d(int n, int *char_numbers)
{
	unsigned int	nbr;
	int				i;

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
		nbr = nbr / 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	*char_numbers += i;
}

void	ft_print_u(unsigned int n, int *char_numbers)
{
	char	*tmp;

	tmp = ft_uitoa_base_maj(n, 10, 0);
	ft_putstr_fd(tmp, 1);
	*char_numbers += ft_strlen(tmp);
	free(tmp);
}

void	ft_print_p(void *p, int *char_numbers)
{
	char	*tmp;

	tmp = ft_ulltoa((unsigned long long)p, 16, 0);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(tmp, 1);
	*char_numbers += ft_strlen(tmp) + 2;
	free(tmp);
}	
