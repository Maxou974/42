/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:19:17 by maxime            #+#    #+#             */
/*   Updated: 2022/06/16 01:19:19 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	t_philo	*tmp;

	tmp = (t_philo *)p;
	if ((tmp->n) % 2 == 0)
		usleep(tmp->info->t_eat * 1000);
	while (1)
	{
		pthread_mutex_lock(&tmp->info->print);
		if (!tmp->info->dead && !tmp->dead)
		{
			pthread_mutex_unlock(&tmp->info->print);
		}
		else
		{
			pthread_mutex_unlock(&tmp->info->print);
			return (NULL);
		}
		philo_routine(tmp);
	}
}

int	th(t_info *i)
{
	int	j;

	j = -1;
	while (++j < i->nbr_philo)
		if (pthread_create(&(i->all[j].th_id), NULL, &routine, &(i->all[j])))
			return (1);
	if (pthread_create(&(i->watch_id), NULL, &verify, i))
		return (1);
	j = -1;
	while (++j < i->nbr_philo)
		pthread_join(i->all[j].th_id, NULL);
	pthread_join(i->watch_id, NULL);
	return (0);
}

void	clear_exit(t_info *i)
{
	int	j;

	j = -1;
	while (++j < i->nbr_philo)
		pthread_mutex_destroy(&i->forks[j]);
	pthread_mutex_destroy(&i->print);
	free(i->all);
	free(i->forks);
	free(i);
}

int	main(int argc, char **argv)
{
	t_info	*i;

	if (checkarg(argc, argv) || info_init(argc, argv, &i)
		|| init_forks_print(i) || init_philos(i))
		return (args_error());
	gettimeofday(&(i->start), NULL);
	if (th(i))
		write(2, "THREADS ERROR\n", 14);
	clear_exit(i);
	return (0);
}
