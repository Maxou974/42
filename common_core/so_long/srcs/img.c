/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:06:05 by mabriel           #+#    #+#             */
/*   Updated: 2022/03/01 14:38:42 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_struct *g)
{
	int		s0;
	int		s2;
	char	*p;

	p = "textures/mario.xpm";
	g->mario = mlx_xpm_file_to_image(g->mlx, p, &s0, &s2);
	p = "textures/ground.xpm";
	g->ground = mlx_xpm_file_to_image(g->mlx, p, &s0, &s2);
	p = "textures/col.xpm";
	g->col = mlx_xpm_file_to_image(g->mlx, p, &s0, &s2);
	p = "textures/wall.xpm";
	g->wall = mlx_xpm_file_to_image(g->mlx, p, &s0, &s2);
	p = "textures/exit.xpm";
	g->exit = mlx_xpm_file_to_image(g->mlx, p, &s0, &s2);
	if (!g->exit || !g->wall || !g->col || !g->ground || !g->mario)
	{
		ft_free(g);
		ft_putstr_fd("Error finding textures\n", 2);
		exit(1);
	}
}

void	*choose_img(char c, t_struct *g)
{
	if (c == '1' && g->wall)
		return (g->wall);
	if (c == '0' && g->ground)
		return (g->ground);
	if (c == 'P' && g->mario)
		return (g->mario);
	if (c == 'C' && g->col)
		return (g->col);
	if (c == 'E' && g->exit)
		return (g->exit);
	ft_free(g);
	ft_putstr_fd("Error finding textures\n", 2);
	exit(1);
}

void	build_img(t_struct *g)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	g->c = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
				g->p_x = x;
			if (g->map[y][x] == 'P')
				g->p_y = y;
			if (g->map[y][x] == 'C')
				g->c += 1;
			img = choose_img(g->map[y][x], g);
			mlx_put_image_to_window(g->mlx, g->win, img, x * PIX, y * PIX);
			x++;
		}
		y++;
	}
}
