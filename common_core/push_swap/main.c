/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:33:20 by mabriel           #+#    #+#             */
/*   Updated: 2022/04/11 17:12:17 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_on_top(t_dlist *stack, unsigned long m, char *st)
{
	t_node			*tmp;
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (stack->first->data >= m)
		return ;
	if (stack->first->next->data >= m)
	{
		swap(stack, st);
		return ;
	}
	tmp = stack->first;
	while (tmp && tmp->data < m && ++i)
		tmp = tmp->next;
	tmp = stack->last;
	while (tmp && tmp->data < m && ++j)
		tmp = tmp->prev;
	if (i <= j)
		while (i--)
			rotate(stack, st);
	else if (++j)
		while (j--)
			reverse_rotate(stack, st);
}

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;

	a = malloc(sizeof(t_dlist));
	b = malloc(sizeof(t_dlist));
	if (!a || !b)
		exit_prog(a, b);
	init_two_stack(a, b);
	if (argc == 1)
	{
		clear_two_stack(a, b);
		return (0);
	}
	start(a, b, argc, argv);
	if (!stack_is_sort(a) && size_stack(a) <= 6)
		simple_six_sort(a, b);
	else if (!stack_is_sort(a) && size_stack(a) > 6)
		sort(a, b);
	clear_two_stack(a, b);
	return (0);
}
