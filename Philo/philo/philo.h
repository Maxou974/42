/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:46:52 by mabriel           #+#    #+#             */
/*   Updated: 2022/07/15 19:36:15 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo{
	int				n;
	pthread_t		th_id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	long long int	last_eat;
	int				dead;
	int				eat_times;
	struct s_info	*info;
}				t_philo;

typedef struct s_info{
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				dead;
	struct timeval	start;
	t_philo			*all;
	pthread_t		watch_id;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}			t_info;

int				info_init(int argc, char **argv, t_info **ptr);
int				checkarg(int argc, char **argv);
int				args_error(void);
long long int	get_time(void *arg);
int				error_threads(t_info *i, int k, int j);
int				init_forks_print(t_info *in);
int				init_philos(t_info *in);
void			philo_routine(t_philo *phi);
void			*verify(void *in);
char			*print_dead(t_info *info, int i);
void			ft_usleep(long long int us_sleep, t_info *info);
int				ft_atoi(char *str);
size_t			ft_strlen(const char *s);
char			*ft_itoa(int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
