/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:46:35 by mabriel           #+#    #+#             */
/*   Updated: 2022/07/05 15:18:00 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks_print(t_info *in)
{
	int	i;

	i = -1;
	in->forks = malloc(sizeof(pthread_mutex_t) * in->nbr_philo);
	if (!in->forks)
		return (1);
	i = -1;
	while (++i < in->nbr_philo)
		pthread_mutex_init(&(in->forks[i]), NULL);
	pthread_mutex_init(&(in->print), NULL);
	return (0);
}

int	init_philos(t_info *in)
{
	int	i;

	in->all = malloc(sizeof(t_philo) * in->nbr_philo);
	if (!in->all)
		return (1);
	i = -1;
	while (++i < in->nbr_philo)
	{
		in->all[i].n = i + 1;
		in->all[i].info = in;
		in->all[i].last_eat = 0;
		in->all[i].eat_times = 0;
		in->all[i].dead = 0;
		in->all[i].r_fork = &in->forks[i];
		in->all[i].l_fork = &in->forks[((i + 1) % in->nbr_philo)];
	}
	return (0);
}
