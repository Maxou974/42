/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:55:44 by mabriel           #+#    #+#             */
/*   Updated: 2022/03/15 16:44:32 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_node {
	unsigned long	data;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_ps {
	long			i;
	long			j;
	long			test;
	t_node			*tmp;
	t_node			*tmp2;
	unsigned long	max;
}		t_ps;

typedef struct s_dlist {
	struct s_node	*first;
	struct s_node	*last;
}		t_dlist;

void			clear_apply(char *s, t_dlist *a, t_dlist *b);
void			exit_prog(t_dlist *a, t_dlist *b);
void			init_two_stack(t_dlist *a, t_dlist *b);
void			clear_two_stack(t_dlist *a, t_dlist *b);
void			sort(t_dlist *a, t_dlist *b);
void			ft_putstr(char *s, char *st);
void			ft_putchar(char c);
void			init_stack(t_dlist *l);
void			push_front(t_dlist *l, unsigned long value);
void			push_back(t_dlist *l, unsigned long data);
unsigned int	size_stack(t_dlist *l);
void			swap(t_dlist *stack, char *st);
void			rotate(t_dlist *stack, char *st);
void			reverse_rotate(t_dlist *stack, char *st);
void			push(t_dlist *from, t_dlist *to, char *st);
int				stack_is_sort(t_dlist *stack);
int				stack_is_reverse_sort(t_dlist *stack);
void			small_on_top(t_dlist *stack, unsigned long m, char *st);
void			simple_six_sort(t_dlist *a, t_dlist *b);
void			simple_reverse_three_sort(t_dlist *stack);
void			simple_three_sort(t_dlist *stack);
void			three_two_sort(t_dlist *stack);
long			get_max_top(t_dlist *stack, unsigned long max, t_dlist *a);
void			clear(t_dlist *l);
void			exit_prog(t_dlist *a, t_dlist *b);
void			start(t_dlist *a, t_dlist *b, int argc, char **argv);
void			check_arg(int argc, char **argv, t_dlist *a, t_dlist *b);
unsigned int	size_stack(t_dlist *l);
void			check_duplicate(t_dlist *a, t_dlist *b);

#endif
