/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_print_c_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:45:55 by mabriel           #+#    #+#             */
/*   Updated: 2021/12/07 00:45:56 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(int c, int *char_numbers)
{
	ft_putchar_fd((unsigned char)c, 1);
	*char_numbers += 1;
}

void	ft_print_s(const char *s, int *char_numbers)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		*char_numbers += ft_strlen("(null)");
		return ;
	}
	ft_putstr_fd((char *)s, 1);
	*char_numbers += ft_strlen(s);
}

void	ft_treat(const char c, va_list List, int *char_numbers)
{
	if (c == 'x')
		ft_print_x(va_arg(List, unsigned int), char_numbers);
	if (c == 'X')
		ft_print_xmaj(va_arg(List, unsigned int), char_numbers);
	if (c == 'd' || c == 'i')
		ft_print_d(va_arg(List, int), char_numbers);
	if (c == 'c')
		ft_print_c(va_arg(List, int), char_numbers);
	if (c == 's')
		ft_print_s(va_arg(List, char *), char_numbers);
	if (c == 'u')
		ft_print_u(va_arg(List, unsigned int), char_numbers);
	if (c == '%')
		ft_print_c((int) '%', char_numbers);
	if (c == 'p')
		ft_print_p(va_arg(List, void *), char_numbers);
}
