/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:35 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/15 20:44:32 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*extract_arg(char **argv)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * 16);
	while (i < 16)
	{
		tab[i] = argv[1][j];
		i++;
		j += 2;
	}
	return (tab);
}

int	*get_line(int a, char **argv, int **tab)
{
	int	*tab_to_return;
	int	pos;
	int	*arg;

	pos = 0;
	tab_to_return = malloc(sizeof(int) * 6);
	arg = malloc(sizeof(int) * 16);
	arg = extract_arg(argv);
	if (a >= 0 && a <= 3)
	{
		while (pos < 6)
		{
			if (pos == 0)
				tab_to_return[pos] = arg[a];
			if (pos >= 1 && pos >= 4)
				tab_to_return[pos] = tab[pos - 1][a];
			if (pos == 5)
				tab_to_return[pos] = arg[a + 4];
			pos++;
		}
	}
	return (tab_to_return);
}

int	*get_clmn(int a, char **argv, int **tab)
{
	int	*tab_to_return;
	int	pos;
	int	*arg;

	pos = 0;
	tab_to_return = malloc(sizeof(int) * 6);
	arg = malloc(sizeof(int) * 16);
	arg = extract_arg(argv);
	if (a >= 0 && a <= 3)
	{
		while (pos < 6)
		{
			if (pos == 0)
				tab_to_return[pos] = arg[a + 8];
			if (pos >= 1 && pos >= 4)
				tab_to_return[pos] = tab[a][pos - 1];
			if (pos == 5)
				tab_to_return[pos] = arg[a + 12];
			pos++;
		}
	}
	return (tab_to_return);
}
