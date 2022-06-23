/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:34:37 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/07 03:39:34 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned long	*clean_array(long long *ar, unsigned int n)
{
	unsigned long	*save;
	unsigned int	i;
	unsigned int	j;
	unsigned int	tmp;

	i = 0;
	tmp = 0;
	save = (unsigned long *)malloc(sizeof(unsigned long) * n);
	if (!save)
		return (NULL);
	while (i < n)
	{
		j = 0;
		tmp = 0;
		while (j < n)
		{
			if (ar[i] > ar[j])
				tmp++;
			j++;
		}
		save[i] = tmp + 1;
		i++;
	}
	free(ar);
	return (save);
}

static void	free_split(char **d)
{
	unsigned int	i;

	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
}

static unsigned long	*spl(char **a, unsigned int *s, t_dlist *A, t_dlist *B)
{
	char			**dest;
	long long		*tab;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	dest = ft_split(a[1], ' ');
	while (dest[i])
		i++;
	tab = (long long *)malloc(sizeof(long long) * i);
	if (!tab)
		return (NULL);
	j = -1;
	while (++j < i)
		tab[j] = ft_atoll(dest[j]);
	*s = i;
	free_split(dest);
	j = -1;
	while (++j < i)
		if (tab[j] > 2147483647 || tab[j] < -2147483648)
			exit_prog(A, B);
	return (clean_array(tab, i));
}

static unsigned long	*bliblou(int argc, char **argv, t_dlist *A, t_dlist *B)
{
	long long	*tab;
	int			i;

	tab = (long long *)malloc(sizeof(long long) * argc - 1);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < argc - 1)
	{
		if (!ft_strncmp(argv[i + 1], "", 1))
			exit_prog(A, B);
		tab[i] = ft_atoll(argv[i + 1]);
	}
	i = -1;
	while (++i < argc - 1)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
		{
			free(tab);
			exit_prog(A, B);
		}
	}
	return (clean_array(tab, argc - 1));
}

void	start(t_dlist *A, t_dlist *B, int argc, char **argv)
{
	unsigned long	*dest;
	unsigned int	size;
	unsigned int	i;

	check_arg(argc, argv, A, B);
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "", 1))
			exit_prog(A, B);
		dest = spl(argv, &size, A, B);
	}
	else if (argc > 2)
	{
		size = argc - 1;
		dest = bliblou(argc, argv, A, B);
	}
	else
		exit_prog(A, B);
	if (!dest)
		exit_prog(A, B);
	i = -1;
	while (++i < size)
		push_back(A, dest[i]);
	free(dest);
	check_duplicate(A, B);
}
