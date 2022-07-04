/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:46:15 by mabriel           #+#    #+#             */
/*   Updated: 2022/06/16 17:46:20 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	if (philo->n % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	pthread_mutex_lock(&philo->info->print);
	if (philo->dead != 1)
	{
		printf("%lld %d has taken a fork\n", \
			get_time(&philo->info->start), philo->n);
		printf("%lld %d has taken a fork\n", \
			get_time(&philo->info->start), philo->n);
	}
	pthread_mutex_unlock(&philo->info->print);
	return (1);
}

void	eat(t_philo *phi)
{
	pthread_mutex_lock(&(phi->info->print));
	if (!phi->dead)
	{
		printf("%lld %d is eating\n", get_time(&(phi->info->start)), phi->n);
	}
	phi->eat_times += 1;
	phi->last_eat = get_time(&(phi->info->start));
	pthread_mutex_unlock(&(phi->info->print));
	ft_usleep(phi->info->t_eat * 1000, phi->info);
	pthread_mutex_unlock(phi->l_fork);
	pthread_mutex_unlock(phi->r_fork);
}

void	do_sleep(t_philo *phi)
{
	pthread_mutex_lock(&(phi->info->print));
	if (!phi->dead)
	{
		printf("%lld %d is sleeping\n", get_time(&(phi->info->start)), phi->n);
	}
	pthread_mutex_unlock(&(phi->info->print));
	ft_usleep(phi->info->t_sleep * 1000, phi->info);
}

void	think(t_philo *phi)
{
	pthread_mutex_lock(&(phi->info->print));
	if (!phi->dead)
	{
		printf("%lld %d is thinking\n", get_time(&(phi->info->start)), phi->n);
	}
	pthread_mutex_unlock(&(phi->info->print));
}

void	philo_routine(t_philo *phi)
{
	if (take_fork(phi))
	{
		eat(phi);
		do_sleep(phi);
		think(phi);
	}
}
