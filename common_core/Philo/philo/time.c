/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:47:10 by mabriel           #+#    #+#             */
/*   Updated: 2022/07/15 19:33:53 by mabriel          ###   ########.fr       */
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
	long long int	actual;

	actual = get_time(&info->start);
	while (get_time(&info->start) < actual + (us_sleep / 1000))
	{
		pthread_mutex_lock(&info->print);
		if (info->dead)
		{
			pthread_mutex_unlock(&info->print);
			break ;
		}
		pthread_mutex_unlock(&info->print);
		usleep(128);
	}
}

int	error_threads(t_info *i, int k, int j)
{
	pthread_mutex_lock(&i->print);
	i->dead = 1;
	pthread_mutex_unlock(&i->print);
	while (++k < j)
		pthread_join(i->all[k].th_id, NULL);
	return (1);
}
