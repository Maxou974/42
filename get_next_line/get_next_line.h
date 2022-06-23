/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:55:08 by mabriel           #+#    #+#             */
/*   Updated: 2021/12/01 22:10:20 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
char	*clean_line(char *dirty_line);
char	*left_line(char *dirty_line);
void	help_left_line(char *str, int *i, int *j);

#endif 
