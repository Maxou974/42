/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_four.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 14:32:02 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/15 15:36:33 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	find_one_put_four(char **argv, char **tab)
{
	int		i;
	char	k;

	i = 0;
	k = 4;
	while (i <= 30)
	{
		if (argv[1][i] == '1')
		{
			if (i >= 0 && i <= 6)
				tab[0][i / 2] = k;
			if (i >= 8 && i <= 14)
				tab[3][(i - 8) / 2] = k;
			if (i >= 16 && i <= 22)
				tab[(i - 16) / 2][0] = k;
			if (i >= 24 && i <= 30)
				tab[(i - 24) / 2][3] = k;
		}
		i += 2;
	}
}

void	ft_put_three_four(int i, char **tab)
{
	if (i >= 0 && i <= 6)
	{
		tab[1][i / 2] = 3;
		tab[2][i / 2] = 4;
	}
	if (i >= 8 && i <= 14)
	{
		tab[2][(i - 8) / 2] = 3;
		tab[1][(i - 8) / 2] = 4;
	}
	if (i >= 16 && i <= 22)
	{
		tab[(i - 16) / 2][1] = 3;
		tab[(i - 16) / 2][2] = 4;
	}
	if (i >= 24 && i <= 30)
	{	
		tab[(i - 24) / 2][2] = 3;
		tab[(i - 24) / 2][1] = 4;
	}
}

void	find_two_three(char **argv, char **tab)
{
	int	i;

	i = 0;
	while (i <= 30)
	{
		if (argv[1][i] == '3' && argv[1][i + 8] == '2')
		{
			ft_put_three_four(i, tab);
		}
		i += 2;
	}
}
