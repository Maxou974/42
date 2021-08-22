/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:26:25 by mabriel           #+#    #+#             */
/*   Updated: 2021/08/22 17:10:13 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 4096

char	*ft_atoa_key(char *str, int cmpt);
char	*ft_atoa_value(char *str, int cmpt);
char	*ft_strcpy_ultimate(char *src, int start, int end);
void    ft_putstr(char *str);
void    ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_str_line_numbers(char *str);

typedef struct dict
{
	char	*key;
	char	*value;
} s_dict;

int main()
{
	int fd;
	char	buf[BUFF_SIZE + 1];
	s_dict *tab;
	int	i;

	fd = open("dict", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open () Error\n");
		return (0);
	}
	read(fd, buf, BUFF_SIZE);
	if (close(fd) == -1)
	{
		ft_putstr("Close() Error\n");
		return (0);
 	}
	tab = malloc(sizeof(s_dict) * ft_str_line_numbers(buf));
	i = 0;
	while (i < ft_str_line_numbers(buf))
	{
		tab[i].key = ft_atoa_key(buf,i);
		tab[i].value = ft_atoa_value(buf,i);
		i++;
	}	
	for (int k = 0; k < ft_str_line_numbers(buf); k++)
	{
		printf("%s:", tab[k].key);
		printf("%s\n", tab[k].value);

	}
	free(tab);
}

int	ft_str_line_numbers(char *str)
{
	int	i;
	int cmp;

	i = 0;
	cmp = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			cmp++;
		i++;
	}
	return (cmp);
}

int	is_an_isspace(char c)
{
	if ((c >=11 && c <= 13) || c == ' ' || c == 9)
		return (1);
	return (0);
}

char	*ft_atoa_key(char *str, int cmpt)
{
	int	i;
	int	end;
	int	start;
	int	j;

	i = -1;
	j = 0;
	while (str[++i] && j < cmpt)
		if(str[i] == '\n')
			j++;
	while (is_an_isspace(str[i]))
			i++;
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	end = i;
	return (ft_strcpy_ultimate(str,start,end));
}

char	*ft_atoa_value(char *str, int cmpt)
{
	int	i;
	int	end;
	int	start;
	int	j;

	i = -1;
	j = 0;
	while (str[++i] && j < cmpt)
		if(str[i] == '\n')
			j++;
	if (str[i] == '\n')
		return (ft_strcpy_ultimate("\0", 0, 1));
	while (str[i] != ':')
		i++;
	i++;
	while (is_an_isspace(str[i]))
			i++;
	start = i;
	while (str[i] >= 32 && str[i] <= 126)
		i++;
	end = i;
	return (ft_strcpy_ultimate(str,start,end));
}

char *ft_strcpy_ultimate(char *src, int start, int end)
{
	int i;
	char *dest;

	i = 0;
	dest = malloc(sizeof(char) * (end - start + 1));	
	while (start < end)
	{
		dest[i] = src[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void    ft_putstr(char *str)
{
	int i;
 
	i = -1;
    while (str[++i])
       ft_putchar(str[i]);
}
int ft_strlen(char *str)
{
        int i;

	i = 0;
    while (str[i])
         i++;
    return (i);
}
