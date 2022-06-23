/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:58:35 by mabriel           #+#    #+#             */
/*   Updated: 2022/03/14 22:43:38 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_rt(t_dlist *stack, t_dlist *a, t_ps *ps)
{
	while (ps->i-- > 0)
	{
		if (!ps->test && stack->first->data == ps->max - 1)
		{
			push(stack, a, "a");
			ps->test++;
			ps->i--;
			if (ps->i < 0)
				break ;
		}
		rotate(stack, "b");
	}
}

static void	make_rrt(t_dlist *stack, t_dlist *a, t_ps *ps)
{
	while (ps->j-- > 0)
	{
		if (!ps->test && stack->first->data == ps->max - 1)
		{
			push(stack, a, "a");
			ps->test++;
		}	
		reverse_rotate(stack, "b");
	}
}

static void	count(t_dlist *stack, t_ps *ps)
{
	ps->tmp = stack->first;
	ps->tmp2 = stack->last;
	while (ps->tmp && ps->tmp->data != ps->max)
	{
		ps->tmp = ps->tmp->next;
		ps->i++;
	}
	while (ps->tmp2 && ps->tmp2->data != ps->max)
	{
		ps->tmp2 = ps->tmp2->prev;
		ps->j++;
	}
}

long	get_max_top(t_dlist *stack, unsigned long max, t_dlist *a)
{
	t_ps	ps;

	ps.i = 0;
	ps.j = 1;
	ps.max = max;
	if (stack->first->data == max)
		return (0);
	if (stack->first->next->data == max)
	{
		swap(stack, "b");
		return (0);
	}
	count(stack, &ps);
	ps.test = 0;
	if (ps.i <= ps.j)
		make_rt(stack, a, &ps);
	else
		make_rrt(stack, a, &ps);
	return (ps.test);
}

void	clear(t_dlist *l)
{
	t_node	*tmp;
	t_node	*node;

	node = l->first;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	l->first = NULL;
	l->last = NULL;
}
