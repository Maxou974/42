/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 01:55:41 by mabriel           #+#    #+#             */
/*   Updated: 2022/04/28 19:36:08 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_in(int *fd, char *s)
{
	*fd = open(s, O_RDONLY, 0777);
	if (*fd == -1)
	{
		perror(s);
	}
}
