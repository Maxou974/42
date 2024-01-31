/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:46:49 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/15 20:27:02 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	is_numeric(char c)
{
	if (c >= '1' && c <= '4')
		return (1);
	return (0);
}

int	verif_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		if ((i % 2 == 0 && is_numeric(argv[1][i]))
				|| (i % 2 == 1 && argv[1][i] == ' '))
			i++;
		else
			return (0);
		if (i == 31 && argv[1][i] == '\0')
			return (1);
	}
	return (0);
}

int	verif_sum(char **argv)
{
	int	i;
	int	res;
	int	j;
	int	check;

	i = 0;
	while (i <= 30)
	{
		j = -1;
		res = 0;
		check = 0;
		while (++j < 4)
		{
			res = res + (argv[1][i] - '0');
			if (argv[1][i] == '1')
				check++;
			i = i + 2;
		}
		if (check != 1)
			return (0);
		if (!(res >= 7 && res <= 10))
			return (0);
	}
	return (1);
}
