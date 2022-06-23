/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:55:38 by mabriel           #+#    #+#             */
/*   Updated: 2022/03/15 13:13:54 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist *stack, char *st)
{
	t_node	*cell_one;
	t_node	*cell_two;

	if (size_stack(stack) < 2)
		return ;
	cell_one = stack->first;
	cell_two = stack->first->next;
	cell_one->next = cell_two->next;
	cell_one->prev = cell_two;
	cell_two->prev = NULL;
	cell_two->next = cell_one;
	stack->first = cell_two;
	if (stack->first->next->next)
		stack->first->next->next->prev = cell_one;
	else
		stack->last = cell_one;
	if (st != NULL)
		ft_putstr("s", st);
}

void	rotate(t_dlist *stack, char *st)
{
	t_node	*tmp;

	if (size_stack(stack) < 2)
		return ;
	tmp = stack->first->next;
	stack->first->prev = stack->last;
	stack->first->next = NULL;
	tmp->prev = NULL;
	stack->last->next = stack->first;
	stack->last = stack->first;
	stack->first = tmp;
	if (st != NULL)
		ft_putstr("r", st);
}

void	reverse_rotate(t_dlist *stack, char *st)
{
	t_node	*tmp;

	if (size_stack(stack) < 2)
		return ;
	tmp = stack->last->prev;
	stack->first->prev = stack->last;
	stack->last->next = stack->first;
	stack->last->prev = NULL;
	tmp->next = NULL;
	stack->first = stack->last;
	stack->last = tmp;
	if (st != NULL)
		ft_putstr("rr", st);
}

void	push(t_dlist *from, t_dlist *to, char *st)
{
	t_node	*tmp;

	if (size_stack(from) == 0)
		return ;
	push_front(to, from->first->data);
	tmp = from->first;
	from->first = from->first->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
	if (st != NULL)
		ft_putstr("p", st);
}
