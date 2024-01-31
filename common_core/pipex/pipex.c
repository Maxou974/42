/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:39:35 by mabriel           #+#    #+#             */
/*   Updated: 2022/05/14 16:21:18 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_command(char *cmd, int *pipe, char **envp, int filein)
{
	if (filein != -1)
		dup2(filein, 0);
	dup2(pipe[1], 1);
	close(pipe[0]);
	exec_ve(cmd, envp);
	close(pipe[1]);
	if (filein > 0)
		close(filein);
	exit(127);
}

static void	second_command(char *cmd, int *pipe, char **envp, int fileout)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		error(1);
	if (pid != 0)
	{
		close(pipe[1]);
		close(pipe[0]);
		close(fileout);
		waitpid(pid, NULL, 0);
	}
	if (pid == 0)
	{
		dup2(pipe[0], 0);
		dup2(fileout, 1);
		close(pipe[1]);
		exec_ve(cmd, envp);
		close(pipe[0]);
		close(fileout);
		exit(127);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		file;
	int		pid;

	if (argc != 5 || !*envp)
		error(0);
	open_in(&file, argv[1]);
	if (pipe(fd) == -1)
		error(1);
	pid = fork();
	if (pid == -1)
		error(1);
	if (pid == 0 && file > 0)
		first_command(argv[2], fd, envp, file);
	if (pid != 0)
	{
		if (file > 0)
			close(file);
		file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (file == -1)
			error(1);
		second_command(argv[3], fd, envp, file);
		waitpid(pid, NULL, 0);
	}
	return (0);
}
