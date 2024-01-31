/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:29:23 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/07 03:31:44 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s, char *st)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	i = 0;
	while (st[i])
	{
		ft_putchar(st[i]);
		i++;
	}
	ft_putchar('\n');
}

void	init_stack(t_dlist *l)
{
	l->first = NULL;
	l->last = NULL;
}

void	push_front(t_dlist *l, unsigned long value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit(1);
	new->data = value;
	new->next = l->first;
	new->prev = NULL;
	if (l->first)
		l->first->prev = new;
	else
		l->last = new;
	l->first = new;
}

void	small_on_top(t_dlist *stack, unsigned long m, char *st)
{
	t_node			*tmp;
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (stack->first->data <= m)
		return ;
	if (stack->first->next->data <= m)
	{
		swap(stack, st);
		return ;
	}
	tmp = stack->first;
	while (tmp && tmp->data > m && ++i)
		tmp = tmp->next;
	tmp = stack->last;
	while (tmp && tmp->data > m && ++j)
		tmp = tmp->prev;
	if (i <= j)
		while (i--)
			rotate(stack, st);
	else if (++j)
		while (j--)
			reverse_rotate(stack, st);
}
