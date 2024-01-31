/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:48:52 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/15 20:26:04 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

void	print_error(void)
{
	ft_putstr("Error\n");
}

void	vertical_line(int j, int **tab)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	if (j >= 0 && j <= 6)
	{
		while (i < 4)
		{
			tab[i][j / 2] = k;
			i++;
			k++;
		}
	}
	k = 4;
	if (j >= 8 && j <= 14)
	{
		while (i < 4)
		{
			tab[i][(j - 8) / 2] = k;
			i++;
			k--;
		}
	}
}

void	horizontal_line(int i, int **tab)
{
	int	j;
	int	k;

	j = 0;
	k = 1;
	if (i >= 16 && i <= 22)
	{
		while (j < 4)
		{
			tab[(i - 16) / 2][j] = k;
			j++;
			k++;
		}
	}
	k = 4;
	if (i >= 24 && i <= 30)
	{
		while (j < 4)
		{
			tab[(i - 24) / 2][j] = k;
			j++;
			k--;
		}
	}
}

void	find_the_four(char **argv, int **tab)
{
	int	pos;

	pos = 0;
	while (argv[1][pos])
	{
		if (argv[1][pos] == '4')
		{
			vertical_line(pos, tab);
			horizontal_line(pos, tab);
		}
		pos++;
	}
}
