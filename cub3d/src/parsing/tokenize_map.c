/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 02:17:09 by mabriel           #+#    #+#             */
/*   Updated: 2022/07/09 04:16:21 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	malloc_err(t_game *game, int code, int i, char **dst)
{
	ft_putstr_fd("Error\nMalloc couldn't allocate more memory\n", 2);
	if (code == 1)
	{
		while (i >= 0)
		{
			free(dst[i]);
			i--;
		}
		free(dst);
	}	
	free_game(game);
	exit(1);
}

static char	**malloc_dst(t_game *game, char **src, int *v_size, int *h_size)
{
	char	**dst;
	int		i;

	*v_size = get_vertical_size(src);
	dst = (char **)malloc(sizeof(char*) * ((*v_size) + 3));
	if (!dst)
		malloc_err(game, 0, 0, NULL);
	i = 0;
	*h_size = get_horizontal_size(src);
	printf("v:%d h:%d\n", *v_size, *h_size);
	while (i < *v_size + 2)
	{
		dst[i] = (char *)malloc(sizeof(char) * (*h_size + 3));
		if (!dst[i])
			malloc_err(game, 1, i, dst);
		i++;
	}
	return (dst);
}

static void	fill_edges(char **dst, int v_size, int h_size)
{
	int	i;

	i = 0;
	while (i < h_size + 2)
	{
		dst[0][i] = 'A';
		dst[v_size + 1][i] = 'A';
		i++;
	}
	i = 0;
	while (i < v_size + 2)
	{
		dst[i][0] = 'A';
		if (i > 0 && i < v_size + 1)
		{
			for(int j = 1; j < h_size + 1; j++)
			dst[i][j] = 'B';
		}
		dst[i][h_size + 1] = 'A';
		dst[i][h_size + 2] = 0;
		i++;
	}
	dst[i] = 0;
}

char **tokenize(t_game *game, char **src)
{
	char	**dst;
	int		v_size;
	int		h_size;

	dst = malloc_dst(game, src, &v_size, &h_size);
	fill_edges(dst, v_size, h_size);
	return (dst);
}