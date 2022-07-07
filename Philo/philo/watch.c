/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:47:18 by mabriel           #+#    #+#             */
/*   Updated: 2022/07/07 15:38:04 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_dead(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{
		info->all[i].dead = 1;
		i++;
	}
}

int	check_meal(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->eat_times == philo->info->must_eat)
		philo->dead = 1;
	while (i < philo->info->nbr_philo)
	{
		if (philo->info->all[i].dead == 0)
			return (0);
		i++;
	}
	philo->info->dead = 1;
	return (1);
}

char	*print_dead(t_info *info, int i)
{
	all_dead(info);
	info->dead = 1;
	printf("%lld %d died\n", get_time(&info->start), info->all[i].n);
	pthread_mutex_unlock(&info->print);
	return (NULL);
}

void	*verify(void *in)
{
	int		i;
	t_info	*info;

	info = in;
	while (1)
	{
		i = -1;
		while (++i < info->nbr_philo)
		{
			pthread_mutex_lock(&info->print);
			if (get_time(&info->start) - info->all[i].last_eat >= info->t_die
				&& !info->all[i].dead && info->nbr_philo != 1)
				return (print_dead(info, i));
			else if (check_meal(&info->all[i]))
			{
				printf("Everyone ate their meal.\n");
				pthread_mutex_unlock(&info->print);
				return (NULL);
			}
			pthread_mutex_unlock(&info->print);
		}
		usleep(2500);
	}
}
