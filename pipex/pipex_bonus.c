/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:24:27 by mabriel           #+#    #+#             */
/*   Updated: 2022/04/19 02:35:46 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_doc(char *tmp, char **argv)
{
	if (*tmp == '\n' && argv[2][0] == '\0')
		return (1);
	if (*tmp == '\n')
		return (0);
	if (!ft_strncmp(tmp, argv[2], ft_strlen(tmp) - 1))
		return (1);
	else
		return (0);
}

static void	here_doc(int argc, char **argv, char **envp)
{
	int		*fd;
	int		i;
	int		file;
	char	*tmp;

	fd = (int *)malloc(sizeof(int) * 2);
	if (pipe(fd) == -1)
		error(1);
	while (1)
	{
		tmp = get_next_line(0);
		if (check_doc(tmp, argv))
			break ;
		ft_putstr_fd(tmp, fd[1]);
		free(tmp);
	}
	free(tmp);
	i = 2;
	while (++i < argc - 2)
		fd = pipe_to_pipe(fd, argv[i], envp);
	file = open(argv[argc - 1], O_APPEND | O_CREAT | O_WRONLY, 0777);
	if (file == -1)
		error(1);
	pipe_to_file(file, fd, argv[i], envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc <= 4)
		error(0);
	if (ft_strcmp("here_doc", argv[1]))
		here_doc(argc, argv, envp);
	else if (argc >= 5)
		do_pipex(argc, argv, envp);
	return (0);
}
