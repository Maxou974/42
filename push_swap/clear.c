/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:10:33 by mabriel           #+#    #+#             */
/*   Updated: 2022/03/15 17:32:30 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_apply(char *s, t_dlist *a, t_dlist *b)
{
	free(s);
	exit_prog(a, b);
}

void	init_two_stack(t_dlist *a, t_dlist *b)
{
	init_stack(a);
	init_stack(b);
}

void	clear_two_stack(t_dlist *a, t_dlist *b)
{
	clear(a);
	clear(b);
	free(a);
	free(b);
}

void	exit_prog(t_dlist *A, t_dlist *B)
{
	if (A)
		clear(A);
	if (B)
		clear(B);
	if (B)
		free(B);
	if (A)
		free(A);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
