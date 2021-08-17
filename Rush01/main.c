/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:50:08 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/15 20:20:38 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	find_the_four(char **argv, char **tab);
void	horizontal_line(int i, char **tab);
void	vertical_line( int j, char **tab);
void	ft_putstr(char *str);
int		verif_arg(int argc, char **argv);
void	print_error(void);
int		verif_sum(char **argv);
void	ft_putchar(char c);
void	find_one_put_four(char **argv, char **tab);
void	find_two_three(char **argv, char **tab);
void	ft_put_three_four(int i, char **tab);
char	*tab_six_x_six(char **tab, char **argv);

int	main(int argc, char **argv)
{
	if (!verif_arg(argc, argv) || !verif_sum(argv))
	{
		print_error();
		return (0);
	}
	find_two_three(argv, tab);
	find_one_put_four(argv, tab);
