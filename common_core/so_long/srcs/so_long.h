/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:23:58 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/21 14:46:33 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIX 40
# define W 119
# define A 97
# define S 115
# define D 100
# define DOWN  65364
# define RIGHT 65363
# define UP 65362
# define LEFT 65361

# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <errno.h>
# include <stdio.h>

typedef struct s_struct{
	char	**map;
	void	*exit;
	void	*ground;
	void	*col;
	void	*mario;
	void	*wall;
	void	*win;
	void	*mlx;
	int		move;
	int		p_x;
	int		p_y;
	int		p;
	int		e;
	int		c;
}		t_struct;

char	**get_tab(char *argv);
int		check_tab(char **tab, t_struct *base);
void	check_arg(int argc, char **argv);

void	ft_free(t_struct *g);
int		count_line(char *argv, char **tab);
int		check_top_and_bot_line(char **tab, int *tab_len);
int		check_midline(char **tab, int *tab_len, t_struct *base);
void	print_map_error(int *tab_len, char **tab, t_struct *base);
int		check_base(t_struct *base);
void	set_struct(t_struct *base);
void	move_down(t_struct *g);
void	move_up(t_struct *g);
void	move_right(t_struct *g);
void	move_left(t_struct *g);
void	build_window(t_struct *g);
void	ft_print_moves(t_struct *g);
int		key_hook(int keycode, t_struct *g);
void	get_img(t_struct *g);
void	*choose_img(char c, t_struct *g);
void	build_img(t_struct *g);
int		ft_clean_exit(t_struct *g, int exi, int win);
int		ft_click_exit(t_struct *g);

#endif
