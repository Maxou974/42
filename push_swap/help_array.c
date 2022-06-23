/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:11:29 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/07 04:11:31 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	space_minus(char c)
{
	if (c == '-' || c == ' ' || ft_isdigit(c))
		return (1);
	return (0);
}

static void	help_check(int argc, char **argv, t_dlist *a, t_dlist *b)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 1;
	while ((int)j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!space_minus(argv[j][i]))
			{
				exit_prog(a, b);
			}
			i++;
		}
		j++;
	}
}

void	check_arg(int argc, char **argv, t_dlist *a, t_dlist *b)
{
	unsigned int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (!space_minus(argv[1][i]))
				exit_prog(a, b);
			i++;
		}
	}
	else if (argc >= 3)
		help_check(argc, argv, a, b);
}

void	push_back(t_dlist *l, unsigned long data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit(1);
	new->data = data;
	new->next = NULL;
	new->prev = l->last;
	if (l->last)
		l->last->next = new;
	else
		l->first = new;
	l->last = new;
}

void	check_duplicate(t_dlist *a, t_dlist *b)
{
	t_node	*head;
	t_node	*tmp;

	tmp = a->first;
	head = a-> first;
	while (tmp)
	{
		head = a->first;
		while (head)
		{
			if (tmp->data == head->data && tmp != head)
				exit_prog(a, b);
			head = head->next;
		}
		tmp = tmp->next;
	}
}
