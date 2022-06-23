/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:58:21 by mabriel           #+#    #+#             */
/*   Updated: 2022/04/14 00:45:00 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sort(t_dlist *stack)
{
	t_node	*tmp;

	tmp = stack->first;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_is_reverse_sort(t_dlist *stack)
{
	t_node	*tmp;

	tmp = stack->first;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

unsigned int	size_stack(t_dlist *l)
{
	t_node			*tmp;
	unsigned int	i;

	i = 0;
	tmp = l->first;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	chunk(t_dlist *a, t_dlist *b)
{
	unsigned long	l;
	unsigned long	s;

	l = 0;
	s = (0.0375 * size_stack(a)) + 11.25;
	while (size_stack(a) != 0)
	{
		if (l > 1 && a->first->data <= l)
		{
			push(a, b, "b");
			l++;
			rotate(b, "b");
		}
		else if (a->first->data <= l + s)
		{
			push(a, b, "b");
			l++;
		}
		else if (a->first->data >= l && a->last->data <= l + s)
			reverse_rotate(a, "a");
		else
			rotate(a, "a");
	}
}

void	sort(t_dlist *a, t_dlist *b)
{
	unsigned long	size;
	long			ret;

	size = size_stack(a);
	chunk(a, b);
	while (size)
	{
		ret = get_max_top(b, size, a);
		push(b, a, "a");
		if (ret == 1)
		{
			if (size_stack(a) > 1 && a->first->data > a->first->next->data)
				swap(a, "a");
			size--;
		}
		size--;
	}
}
