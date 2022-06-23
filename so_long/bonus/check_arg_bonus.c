/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:30:24 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/19 16:05:41 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

void	check_arg(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_error("Error: numbers of args must be 2\n");
	else if (!ft_strcmp(ft_strchr(argv[1], '.'), ".ber"))
		ft_error("Error: Extension must me  .ber");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error map");
			exit(1);
		}
		close (fd);
	}
}
