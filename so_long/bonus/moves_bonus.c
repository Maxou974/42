/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:23:19 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/24 00:06:14 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_str(t_struct *g)
{
	char	*n;
	char	*dest;

	n = ft_itoa(g->move);
	dest = ft_strjoin("MOVES : ", n);
	mlx_string_put(g->mlx, g->win, 25, 25, 0777, dest);
	free(n);
	free(dest);
}

void	move_down(t_struct *g)
{
	if (g->map[g->p_y + 1][g->p_x] == 'V')
		ft_clean_exit(g, 0, 0);
	if (g->map[g->p_y + 1][g->p_x] == 'E' && g->c)
		g->map[g->p_y][g->p_x] = 'P';
	if (g->map[g->p_y + 1][g->p_x] == 'E' && !g->c)
		ft_clean_exit(g, 0, 1);
	if (g->map[g->p_y + 1][g->p_x] != '1' && g->map[g->p_y + 1][g->p_x] != 'E')
	{
		g->map[g->p_y][g->p_x] = '0';
		g->map[g->p_y + 1][g->p_x] = 'P';
		g->move += 1;
	}
	else if (g->map[g->p_y + 1][g->p_x] == '1')
		g->map[g->p_y][g->p_x] = 'P';
	build_img(g);
}

void	move_up(t_struct *g)
{
	if (g->map[g->p_y - 1][g->p_x] == 'V')
		ft_clean_exit(g, 0, 0);
	if (g->map[g->p_y - 1][g->p_x] == 'E' && g->c)
		g->map[g->p_y][g->p_x] = 'U';
	if (g->map[g->p_y - 1][g->p_x] == 'E' && !g->c)
		ft_clean_exit(g, 0, 1);
	if (g->map[g->p_y - 1][g->p_x] != '1' && g->map[g->p_y - 1][g->p_x] != 'E')
	{
		g->map[g->p_y][g->p_x] = '0';
		g->map[g->p_y - 1][g->p_x] = 'U';
		g->move += 1;
	}
	else if (g->map[g->p_y - 1][g->p_x] == '1')
		g->map[g->p_y][g->p_x] = 'U';
	build_img(g);
}

void	move_right(t_struct *g)
{
	if (g->map[g->p_y][g->p_x + 1] == 'V')
		ft_clean_exit(g, 0, 0);
	if (g->map[g->p_y][g->p_x + 1] == 'E' && g->c)
		g->map[g->p_y][g->p_x] = 'R';
	if (g->map[g->p_y][g->p_x + 1] == 'E' && !g->c)
		ft_clean_exit(g, 0, 1);
	if (g->map[g->p_y][g->p_x + 1] != '1' && g->map[g->p_y][g->p_x + 1] != 'E')
	{
		g->map[g->p_y][g->p_x] = '0';
		g->map[g->p_y][g->p_x + 1] = 'R';
		g->move += 1;
	}
	else if (g->map[g->p_y][g->p_x + 1] == '1')
		g->map[g->p_y][g->p_x] = 'R';
	build_img(g);
}

void	move_left(t_struct *g)
{
	if (g->map[g->p_y][g->p_x - 1] == 'V')
		ft_clean_exit(g, 0, 0);
	if (g->map[g->p_y][g->p_x - 1] == 'E' && g->c)
		g->map[g->p_y][g->p_x] = 'L';
	if (g->map[g->p_y][g->p_x - 1] == 'E' && !g->c)
		ft_clean_exit(g, 0, 1);
	if (g->map[g->p_y][g->p_x - 1] != '1' && g->map[g->p_y][g->p_x - 1] != 'E')
	{
		g->map[g->p_y][g->p_x] = '0';
		g->map[g->p_y][g->p_x - 1] = 'L';
		g->move += 1;
	}
	else if (g->map[g->p_y][g->p_x - 1] == '1')
		g->map[g->p_y][g->p_x] = 'L';
	build_img(g);
}
