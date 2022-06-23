/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:01:08 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/11 12:55:43 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	i;

	if (nb < 0)
	{
		i = -nb;
		ft_putchar('-');
	}
	else
		i = nb;
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		i = i % 10;
	}
	ft_putchar(i + 48);
}
