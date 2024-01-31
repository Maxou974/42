/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 21:41:53 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/25 22:40:48 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	tmp;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	tmp = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp * 10 + str[i] - '0';
		i++;
	}
	return (sign * tmp);
}

#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = -nb;
	}
	else
		n = nb;
	while (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	n += '0';
	write(1, &n, 1);
}
	
int main(int argc, char **argv)
{
	
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			ft_putnbr(ft_atoi(argv[1]) + ft_atoi(argv[3]));
		if (*argv[2] == '-')
			ft_putnbr(ft_atoi(argv[1]) - ft_atoi(argv[3]));
		if (*argv[2] == '/')
			ft_putnbr(ft_atoi(argv[1]) / ft_atoi(argv[3]));
		if (*argv[2] == '%')
			ft_putnbr(ft_atoi(argv[1]) % ft_atoi(argv[3]));
		if (*argv[2] == '*')
			ft_putnbr(ft_atoi(argv[1]) * ft_atoi(argv[3]));
	}
	write(1, "\n", 1);
}
