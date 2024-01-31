/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:41:47 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/07 15:22:47 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
void	ft_putchar(char c);

void	ft_top_and_bot_line(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar('A');
		if (i < x - 2)
			ft_putchar('B');
		if (i == x - 1 && x >= 2)
			ft_putchar('C');
		i++;
	}
	ft_putchar('\n');
}

void	ft_mid_line(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (y > 2)
	{
		while (j < y - 2)
		{
			while (i < x)
			{
				if (i == 0)
					ft_putchar('B');
				if (i < x - 2)
					ft_putchar(' ');
				if (i == x - 1 && x > 2)
					ft_putchar('B');
				i++;
			}
			ft_putchar('\n');
			j++;
			i = 0;
		}
	}
}

void	rush(int x, int y)
{
	if (x == 0 || y == 0)
	{
		write(1, "Please enter x > 0 AND y > 0, Thanks ;P\n", 40);
		return ;
	}
	ft_top_and_bot_line(x);
	if (y != 1)
	{
		ft_mid_line(x, y);
		ft_top_and_bot_line(x);
	}
}
