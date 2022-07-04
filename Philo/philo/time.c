/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:47:10 by mabriel           #+#    #+#             */
/*   Updated: 2022/06/16 17:47:13 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_time(void *arg)
{
	struct timeval	tv;
	struct timeval	af;
	long long int	start;
	long long int	ret;

	tv = *(struct timeval *)arg;
	gettimeofday(&af, NULL);
	start = (size_t)tv.tv_sec * 1000 + (size_t)tv.tv_usec / 1000;
	ret = (size_t)af.tv_sec * 1000 + (size_t)af.tv_usec / 1000;
	ret -= start;
	return (ret);
}

void	ft_usleep(long long int us_sleep, t_info *info)
{
	struct timeval star;
	(void)info;

	gettimeofday(&star, NULL);
	while ((us_sleep - 100) / 1001 >= get_time(&star))
	{
		usleep(500);
		gettimeofday(&star, NULL);
	}
}
