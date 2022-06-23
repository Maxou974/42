/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:20 by mabriel           #+#    #+#             */
/*   Updated: 2022/04/13 19:29:40 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_dlist *a, t_dlist *b)
{
	rotate(a, NULL);
	rotate(b, NULL);
}

void	ss(t_dlist *a, t_dlist *b)
{
	swap(a, NULL);
	swap(b, NULL);
}

void	rrr(t_dlist *a, t_dlist *b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
}

static void	apply(char *s, t_dlist *a, t_dlist *b)
{
	if (ft_strcmp(s, "rra\n"))
		reverse_rotate(a, NULL);
	else if (ft_strcmp(s, "rrb\n"))
		reverse_rotate(b, NULL);
	else if (ft_strcmp(s, "ra\n"))
		rotate(a, NULL);
	else if (ft_strcmp(s, "rb\n"))
		rotate(b, NULL);
	else if (ft_strcmp(s, "sa\n"))
		swap(a, NULL);
	else if (ft_strcmp(s, "sb\n"))
		swap(b, NULL);
	else if (ft_strcmp(s, "pa\n"))
		push(b, a, NULL);
	else if (ft_strcmp(s, "pb\n"))
		push(a, b, NULL);
	else if (ft_strcmp(s, "rrr\n"))
		rrr(a, b);
	else if (ft_strcmp(s, "rr\n"))
		rr(a, b);
	else if (ft_strcmp(s, "ss\n"))
		ss(a, b);
	else
		clear_apply(s, a, b);
	free(s);
}

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	char	*s;

	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_dlist));
	b = malloc(sizeof(t_dlist));
	if (!a || !b)
		exit_prog(a, b);
	init_two_stack(a, b);
	start(a, b, argc, argv);
	s = get_next_line(0);
	while (s)
	{
		apply(s, a, b);
		s = get_next_line(0);
	}
	free(s);
	if (stack_is_sort(a) && size_stack(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_two_stack(a, b);
	return (0);
}
