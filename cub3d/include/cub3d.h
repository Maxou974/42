/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:15:07 by kychoi            #+#    #+#             */
/*   Updated: 2022/07/09 03:17:33 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YEL "\033[0;33m"
# define BLU "\033[0;34m"
# define MAG "\033[0;35m" //purple
# define CYN "\033[0;36m" //emerald
# define WHT "\033[0;37m"
# define DFT "\033[0m"

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

/* libft */
# include "libft.h"
/* mlx */
# include "mlx.h"

/* Pointer size */
# define P_SIZE 8
# define OFFMAP -16
# define ERROR_LINE 1
# define ERROR_MAP 2

typedef enum e_bool { FALSE, TRUE }	t_bool;
typedef enum e_error { ERR_PARSE = -42, ERR_MAP = 1, ERR_LINE = 2 }	t_error;
typedef enum e_event { EVENT_EXIT_WIN = 17 }	t_event;

//TODO: parler avec Max pour des variables dans s_player et t_game
typedef struct s_player {
	int		x;
	int		y;
}	t_player;

//Principal struct
typedef struct s_game {
	void		*mlx;
	void		*win;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	//FIXME: int[3] or char * for t
	char		*f_color;
	//FIXME: int[3] or char * for t
	char		*c_color;
	char		**map;
	t_player	*player;
	int			count;
	int			line;
	int			err;
}	t_game;

/* *********************************************************************** */
/*                               PARSING                                   */
/* *********************************************************************** */
/* parse.c */
int		parse(char **av, t_game *game);
int		check_place(t_game *game, int place);
int		validate_line(char *line, t_game *game);
void	init_parse(t_game *game);

/* check_map.c */
void	check_map(t_game *game);

/* parse_error.c */
void	error_parsing(t_error err_code, char *msg, t_game *game);
void	exit_error_file(t_game *game, int err_code);
int		forest_help(t_game *game, int code);
int		open_file(char *s, t_game *game);

/* tokenize_map.c */
char	**tokenize(t_game *game, char **src);

/* tokenize_map_help.c */
int		get_horizontal_size(char **s);
int		get_vertical_size(char **s);

/* *********************************************************************** */
/*                             RAY-CASTING                                 */
/* *********************************************************************** */
/* painter.c */
void	put_header(void);
void	print_game(t_game *game);

/* free.c */
void	free_game(t_game *game);

#endif
