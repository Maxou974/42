/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:35:21 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/13 11:38:41 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ir(char c, char min, char max)
{
	return (min <= c && c <= max);
}

int	is_an(char c)
{
	return (ir(c, 'a', 'z') || ir(c, 'A', 'Z') || ir(c, '0', '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 || !is_an(str[i - 1])) && ir(str[i], 'a', 'z'))
			str[i] -= 32;
		if ((i != 0 && is_an(str[i - 1])) && ir(str[i], 'A', 'Z'))
			str[i] += 32;
		i++;
	}
	return (str);
}
