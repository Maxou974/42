/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:50:08 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/23 10:40:20 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	find_the_four(char **argv, int **tab);
void	horizontal_line(int i, int **tab);
void	vertical_line( int j, int **tab);
void	ft_putstr(char *str);
int		verif_arg(int argc, char **argv);
void	print_error(void);
int		verif_sum(char **argv);
void	ft_putchar(char c);
void	find_one_put_four(char **argv, int **tab);
void	find_two_three(char **argv, int **tab);
void	ft_put_three_four(int i, int **tab);
char	*tab_six_x_six(int **tab, char **argv);
int		*extract_arg(char **argv);
int		*get_line(int a, char **argv, int **tab);
int		*get_clmn(int a, char **argv, int **tab);

int	main(int argc, char **argv)
{
	int	**tab;
	int	i;

	tab = malloc(sizeof(int) * 4);
	i = -1;
	while (++i < 4)
		tab[i] = malloc(sizeof(int) * 4);
	if (!verif_arg(argc, argv) || !verif_sum(argv))
	{
		print_error();
		return (0);
	}
	find_two_three(argv, tab);
	find_one_put_four(argv, tab);
	return (0);
}
