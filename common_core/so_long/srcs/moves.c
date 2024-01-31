/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:23:19 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/21 01:23:20 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_struct *g)
{
	if (g->map[g->p_y + 1][g->p_x] == 'E' && g->c)
		return ;
	if (g->map[g->p_y + 1][g->p_x] == 'E' && !g->c)
		ft_clean_exit(g, 0, 1);
	if (g->map[g->p_y + 1][g->p_x] != '1')
	{
		g->map[g->p_y][g->p_x] = '0';
		g->map[g->p_y + 1][g->p_x] = 'P';
		g->move += 1;
		ft_print_moves(g);
	}
	build_img(g);
}

void	move_up(t_struct *g)
{
	if (g->map[g->p_y - 1][g->p_x] == 'E' && g->c)
		return ;
	if (g->map[g->p_y - 1][g->p_x] == 'E' && !g->c)
		ft_clean_exit(g, 0, 1);
	if (g->map[g->p_y - 1][g->p_x] != '1')
	{
		g->map[g->p_y][g->p_x] = '0';
		g->map[g->p_y - 1][g->p_x] = 'P';
		g->move += 1;
		ft_print_moves(g);
	}
	build_img(g);
}

void	move_right(t_struct *g)
{
	if (g->map[g->p_y][g->p_x + 1] == 'E' && g->c)
		return ;
	if (g->map[g->p_y][g->p_x + 1] == 'E' && !g->c)
		ft_clean_exit(g, 0, 1);
	if (g->map[g->p_y][g->p_x + 1] != '1')
	{
		g->map[g->p_y][g->p_x] = '0';
		g->map[g->p_y][g->p_x + 1] = 'P';
		g->move += 1;
		ft_print_moves(g);
	}
	build_img(g);
}

void	move_left(t_struct *g)
{
	if (g->map[g->p_y][g->p_x - 1] == 'E' && g->c)
		return ;
	if (g->map[g->p_y][g->p_x - 1] == 'E' && !g->c)
		ft_clean_exit(g, 0, 1);
	if (g->map[g->p_y][g->p_x - 1] != '1')
	{
		g->map[g->p_y][g->p_x] = '0';
		g->map[g->p_y][g->p_x - 1] = 'P';
		g->move += 1;
		ft_print_moves(g);
	}
	build_img(g);
}
