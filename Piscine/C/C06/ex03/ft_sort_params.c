/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:21:37 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/17 16:53:06 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (j < argc - 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				ft_swap_str(&argv[i], &argv[i + 1]);
			}
			i++;
		}
		j++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = argc;
	j = 1;
	k = 0;
	ft_sort_params(argc, argv);
	while (i - 1)
	{
		k = 0;
		while (argv[j][k])
		{
			ft_putchar(argv[j][k]);
			k++;
		}
		ft_putchar('\n');
		i--;
		j++;
	}
	return (0);
}
