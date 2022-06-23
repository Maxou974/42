/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:32:14 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/17 17:14:22 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{	
	int	res;

	res = 0;
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	res = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (res);
}
