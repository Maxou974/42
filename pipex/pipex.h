/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:37:59 by mabriel           #+#    #+#             */
/*   Updated: 2022/05/03 19:27:42 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"

void	exec_ve(char *cmd, char **envp);
void	error(int x);
int		*file_to_pipe(int file, char **argv, char **envp, int fileout);
int		*pipe_to_pipe(int *pip, char *cmd, char **envp);
void	pipe_to_file(int file, int *pipe, char *cmd, char **envp);
void	do_pipex(int argc, char **argv, char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	**ft_quote_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_free_split(char **d);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s, char *d);
void	open_in(int *fd, char *s);

#endif
