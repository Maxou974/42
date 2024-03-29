#ifndef LIBASM_BONUS_H
#define LIBASM_BONUS_H

#include "libasm.h"

typedef struct	s_list
{
	void *data;
	struct s_list *next;
} 				t_list;

int ft_atoi_base(const char *src, const char *base);
int ft_list_size(t_list *list);
int ft_list_push_front(t_list **list, void *data);
int ft_list_sort(t_list **list, int (*cmp)());
int ft_list_remove_if(t_list **list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif