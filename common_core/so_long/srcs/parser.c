/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:51:37 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/20 21:46:33 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map_error(int *tab_len, char **tab, t_struct *base)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	if (tab_len)
		free(tab_len);
	if (base)
		free(base);
	ft_putstr_fd("Error: Map not valid\n", 2);
	exit(1);
}

int	check_base(t_struct *base)
{
	if (base->p != 1)
		return (1);
	if (base->c < 1)
		return (1);
	if (base->e < 1)
		return (1);
	return (0);
}

int	check_tab(char **tab, t_struct *base)
{
	int	*tab_len;
	int	i;
	int	tmp;

	tab_len = malloc(sizeof(int) * count_line(NULL, tab));
	if (!tab_len)
	{
		ft_free_split(tab);
		free(base);
		ft_putstr_fd("Malloc Error\n", 2);
		exit(1);
	}
	if (check_top_and_bot_line(tab, tab_len)
		|| check_midline(tab, tab_len, base) || check_base(base))
		print_map_error(tab_len, tab, base);
	i = 0;
	tmp = tab_len[i];
	while (i < count_line(NULL, tab))
	{
		if (tmp != tab_len[i])
			print_map_error(tab_len, tab, base);
		i++;
	}
	free(tab_len);
	return (0);
}

void	set_struct(t_struct *base)
{
	base->map = NULL;
	base->p = 0;
	base->e = 0;
	base->c = 0;
	base->p_x = 0;
	base->p_y = 0;
	base->exit = NULL;
	base->mlx = NULL;
	base->win = NULL;
	base->wall = NULL;
	base->mario = NULL;
	base->ground = NULL;
	base->col = NULL;
	base->move = 0;
}
