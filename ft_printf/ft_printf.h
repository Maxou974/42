/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:46:22 by mabriel           #+#    #+#             */
/*   Updated: 2021/12/07 04:10:16 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_print_p(void *p, int *char_numbers);
void	ft_print_u(unsigned int n, int *char_numbers);
void	ft_print_d(int n, int *char_numbers);
void	ft_print_xmaj(unsigned int n, int *char_numbers);
void	ft_print_x(unsigned int n, int *char_numbers);
void	ft_treat(const char c, va_list List, int *char_numbers);
void	ft_print_s(const char *s, int *char_numbers);
void	ft_print_c(int c, int *char_numbers);
int		ft_printf(const char *format, ...);
char	*ft_uitoa_base_maj(unsigned int n, int base, int maj);
char	*ft_ulltoa(unsigned long long n, int base, int maj);

#endif
