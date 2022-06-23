/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:34:24 by mabriel           #+#    #+#             */
/*   Updated: 2021/12/07 05:05:30 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		list;
	int			char_numbers;

	char_numbers = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%' && *format + 1 != '\0')
		{
			format++;
			ft_treat(*format, list, &char_numbers);
			char_numbers--;
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
		char_numbers++;
	}
	va_end(list);
	return (char_numbers);
}
