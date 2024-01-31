/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:38:45 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/18 17:30:09 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *argv, char **tab)
{
	int		fd;
	int		ret;
	int		i;
	char	cha[2];

	ret = 1;
	i = 0;
	if (tab && argv == NULL)
	{
		while (tab[i])
			i++;
		return (i);
	}
	fd = open(argv, O_RDONLY);
	while (ret)
	{
		ret = read(fd, cha, 1);
		cha[ret] = 0;
		if (*cha == '\n')
			i++;
	}
	close(fd);
	return (i + 1);
}

char	**get_tab(char *argv)
{
	char	**tab;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		print_map_error(NULL, NULL, NULL);
	i = 0;
	tab = malloc(sizeof(char *) * count_line(argv, NULL) + 1);
	if (!tab)
		return (NULL);
	tab[i] = get_next_line(fd);
	while (tab[i])
	{
		if (tab[i][ft_strlen(tab[i]) - 1] == '\n')
			tab[i][ft_strlen(tab[i]) - 1] = '\0';
		i++;
		tab[i] = get_next_line(fd);
	}
	close(fd);
	return (tab);
}

int	check_top_and_bot_line(char **tab, int *tab_len)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		if (i == 0 || i == count_line(NULL, tab) - 1)
		{
			j = 0;
			while (tab[i][j] != '\0' && tab[i][j] != '\n')
			{
				if (tab[i][j] != '1')
					return (1);
				j++;
			}
			tab_len[i] = j;
		}
		i++;
	}
	return (0);
}

int	check_midline(char **tab, int *tab_len, t_struct *base)
{
	int	i;
	int	j;

	i = 0;
	while (++i < count_line(NULL, tab) - 1)
	{
		j = 1;
		while (tab[i][j + 1])
		{
			if (tab[i][j] != 'P' && tab[i][j] != 'C' && tab[i][j] != 'E'
				&& tab[i][j] != '0' && tab[i][j] != '1')
				return (1);
			if (tab[i][j] == 'P')
				base->p += 1;
			else if (tab[i][j] == 'C')
				base->c += 1;
			else if (tab[i][j] == 'E')
				base->e += 1;
			j++;
		}
		if (tab[i][0] != '1' || tab[i][j] != '1')
			return (1);
		tab_len[i] = j + 1;
	}
	return (0);
}
