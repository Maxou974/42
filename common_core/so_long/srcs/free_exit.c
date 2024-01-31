/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:07:59 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/21 15:35:40 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_struct *g)
{
	ft_free_split(g->map);
	if (g->mario)
		mlx_destroy_image(g->mlx, g->mario);
	if (g->wall)
		mlx_destroy_image(g->mlx, g->wall);
	if (g->col)
		mlx_destroy_image(g->mlx, g->col);
	if (g->exit)
		mlx_destroy_image(g->mlx, g->exit);
	if (g->ground)
		mlx_destroy_image(g->mlx, g->ground);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free(g);
}

int	ft_clean_exit(t_struct *g, int exi, int win)
{
	if (exi == 1)
	{
		ft_free(g);
		perror("Error");
		return (1);
	}
	else if (win == 1)
	{
		ft_putstr_fd("You win with ", 1);
		ft_putnbr_fd(g->move + 1, 1);
		ft_putstr_fd(" moves.", 1);
		ft_putchar_fd('\n', 1);
	}
	else if (win == 0 && exi == 0)
		ft_putstr_fd("Game Over\n", 1);
	ft_free(g);
	exit(0);
}

int	ft_click_exit(t_struct *g)
{
	ft_free(g);
	ft_putstr_fd("Game Quit\n", 1);
	exit(0);
}
