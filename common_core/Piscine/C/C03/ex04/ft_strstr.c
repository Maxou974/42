/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:11:27 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/09 15:10:18 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	lengh;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	lengh = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return (str);
	while (str[j])
	{
		i = j;
		k = 0;
		while (str[i] == to_find[k])
		{
			if (to_find[k + 1] == '\0')
				return (&str[j]);
			i++;
			k++;
		}
		j++;
	}
	return (0);
}
