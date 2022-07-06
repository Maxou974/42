/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:46:28 by mabriel           #+#    #+#             */
/*   Updated: 2022/07/06 19:40:28 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int_max(char *s)
{
	char	*tmp;

	tmp = ft_itoa(ft_atoi(s));
	if (ft_strncmp(tmp, s, ft_strlen(tmp)))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int	checkarg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc <= 4 || argc > 6)
		return (1);
	while (j < argc)
	{
		i = 0;
		if (!(argv[j]) || argv[j][0] == 0)
			return (1);
		while (argv[j][i])
		{
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9'))
				return (1);
			i++;
		}
		if (check_int_max(argv[j]))
			return (1);
		j++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		ret = (ret * 10) + (str[i] - 48);
		i++;
	}
	return (ret);
}

int	info_init(int argc, char **argv, t_info **ptr)
{
	t_info	*ret;

	ret = (t_info *)malloc(sizeof(t_info));
	if (!ret)
		return (1);
	ret->t_eat = ft_atoi(argv[3]);
	ret->nbr_philo = ft_atoi(argv[1]);
	ret->t_die = ft_atoi(argv[2]);
	ret->t_sleep = ft_atoi(argv[4]);
	ret->dead = 0;
	if (argc == 6)
		ret->must_eat = ft_atoi(argv[5]);
	else
		ret->must_eat = -1;
	if (ret->t_eat == 0 || ret->t_die == 0 || ret->nbr_philo == 0
		|| ret->t_sleep == 0 || ret->must_eat == 0)
	{
		free(ret);
		return (1);
	}
	*ptr = ret;
	return (0);
}

int	args_error(void)
{
	write(2, "Error\nArgs must be int and :", 28);
	write(2, " ./philo nbr_philo t_die t_eat t_sleep [must_eat]\n", 50);
	return (1);
}

/*
int main(int argc, char **argv)
{
	t_info *i;

	if (checkarg(argc, argv) || phi_init(argc, argv, &i))
		return (args_error());
}*/
