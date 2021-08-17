/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:43:35 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/17 19:13:09 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	unsigned int	i;

	i = nb;
	if (nb <= 2)
		return (2);
	while (i <= (unsigned int)nb * 2)
	{
		if (!ft_is_prime(i))
			i++;
		else
			return (i);
	}
	return (0);
}
