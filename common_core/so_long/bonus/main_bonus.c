/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 01:06:49 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/21 15:18:29 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	build_window(t_struct *g)
{
	int	size_x;
	int	size_y;

	g->mlx = mlx_init();
	if (!g->mlx)
		ft_clean_exit(g, 1, 0);
	size_x = ft_strlen(g->map[0]) * PIX;
	size_y = 0;
	get_img(g);
	while (g->map[size_y])
		size_y++;
	size_y *= PIX;
	g->win = mlx_new_window(g->mlx, size_x, size_y, "so_long");
	if (!g->win)
		ft_clean_exit(g, 1, 0);
	build_img(g);
}

void	ft_print_moves(t_struct *g)
{
	ft_putstr_fd("Moves : ", 1);
	ft_putnbr_fd(g->move, 1);
	ft_putchar_fd('\n', 1);
}

int	key_hook(int keycode, t_struct *g)
{
	if (keycode == 65307)
		ft_click_exit(g);
	if (keycode == W || keycode == UP)
		move_up(g);
	if (keycode == D || keycode == RIGHT)
		move_right(g);
	if (keycode == A || keycode == LEFT)
		move_left(g);
	if (keycode == S || keycode == DOWN)
		move_down(g);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	*g;

	check_arg(argc, argv);
	g = (t_struct *)malloc(sizeof(t_struct));
	set_struct(g);
	g->map = get_tab(argv[1]);
	check_tab(g->map, g);
	build_window(g);
	mlx_key_hook(g->win, &key_hook, g);
	mlx_hook(g->win, 17, 0, &ft_click_exit, g);
	mlx_loop(g->mlx);
	return (0);
}
