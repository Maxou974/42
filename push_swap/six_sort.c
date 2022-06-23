/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:30:10 by mabriel           #+#    #+#             */
/*   Updated: 2022/02/07 03:30:13 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	help_reverse_three_sort(t_dlist *stack)
{
	if (stack_is_reverse_sort(stack) || size_stack(stack) == 1)
		return ;
	swap(stack, "b");
}

static void	swap_rot(t_dlist *stack)
{
	swap(stack, "b");
	rotate(stack, "b");
}

void	simple_six_sort(t_dlist *A, t_dlist *B)
{
	unsigned long	mediane;

	mediane = size_stack(A) / 2;
	if (stack_is_sort(A))
		return ;
	while (size_stack(A) > 3)
	{
		if (A->first->data <= mediane)
			push(A, B, "b");
		else
			small_on_top(A, mediane, "a");
	}
	simple_three_sort(A);
	if (size_stack(B) != 0)
		simple_reverse_three_sort(B);
	while (size_stack(B) != 0)
		push(B, A, "a");
	if (!stack_is_sort(A))
		swap(A, "a");
}

void	simple_reverse_three_sort(t_dlist *stack)
{
	unsigned long	first;
	unsigned long	second;
	unsigned long	third;

	if (size_stack(stack) < 3)
	{
		help_reverse_three_sort(stack);
		return ;
	}
	first = stack->first->data;
	second = stack->first->next->data;
	third = stack->first->next->next->data;
	if (first < second && second < third)
	{
		rotate(stack, "b");
		swap(stack, "b");
	}
	if (first > second && second < third && first > third)
		swap_rot(stack);
	if (first > second && second < third && first < third)
		reverse_rotate(stack, "b");
	if (first < second && second > third && first < third)
		rotate(stack, "b");
	if (first < second && second > third && first > third)
		swap(stack, "b");
}

void	simple_three_sort(t_dlist *stack)
{
	unsigned long	first;
	unsigned long	second;
	unsigned long	third;

	if (size_stack(stack) < 3)
		return ;
	first = stack->first->data;
	second = stack->first->next->data;
	third = stack->first->next->next->data;
	if (first > second && second > third)
	{
		rotate(stack, "a");
		swap(stack, "a");
	}
	if (first < second && second > third && first < third)
	{
		swap(stack, "a");
		rotate(stack, "a");
	}
	if (first < second && second > third && first > third)
		reverse_rotate(stack, "a");
	if (first > second && second < third && first > third)
		rotate(stack, "a");
	if (first > second && second < third && first < third)
		swap(stack, "a");
}
