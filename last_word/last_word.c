/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:50:50 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/20 21:08:26 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}




int main(int argc, char **argv)
{
	int i;
	int j;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	j = ft_strlen(argv[1]) - 1;
	while (j >= 0 && (argv[1][j] == 9 || argv[1][j] == 32))
		j--;
	i = j;
	while (i >= 0 && (argv[1][i] != 9 && argv[1][i] != 32))
		i--;
	i += 1;
	while (i <= j)
	{
		ft_putchar(argv[1][i]);
		i++;
	}
	ft_putchar('\n');
	printf("\n%d\n", '\t');
	return (0);
}


