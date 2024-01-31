/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:19:58 by mabriel           #+#    #+#             */
/*   Updated: 2022/05/20 21:22:19 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int x)
{
	if (x == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
	{
		perror("Error");
		exit(1);
	}
}

int	*file_to_pipe(int file, char **argv, char **envp, int out)
{
	int	*fd;
	int	pid;
	int	tmp;

	fd = (int *)malloc(sizeof(int) * 2);
	if (!fd || pipe(fd) == -1)
		error(1);
	pid = fork();
	if (pid == -1)
		error(1);
	tmp = fd[1];
	if (pid == 0)
	{
		dup2(file, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		free(fd);
		exec_ve(argv[2], envp);
		close(file);
		close(out);
		close(tmp);
		exit(127);
	}
	return (fd);
}

int	*pipe_to_pipe(int *pip, char *cmd, char **envp)
{
	int	*fd;
	int	pid;

	fd = (int *)malloc(sizeof(int) * 2);
	if (!fd || pipe(fd) == -1)
		error(1);
	pid = fork();
	if (pid == -1)
		error(1);
	if (pid == 0)
	{
		close(fd[0]);
		close(pip[1]);
		dup2(pip[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		free(pip);
		free(fd);
		exec_ve(cmd, envp);
		exit(127);
	}
	close(pip[1]);
	close(pip[0]);
	free(pip);
	return (fd);
}

void	pipe_to_file(int file, int *pipe, char *cmd, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		error(1);
	if (pid == 0)
	{
		dup2(pipe[0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
		close(pipe[1]);
		free(pipe);
		exec_ve(cmd, envp);
		close(file);
		exit(127);
	}
	close(pipe[0]);
	close(pipe[1]);
	waitpid(pid, NULL, 0);
	free(pipe);
}

void	do_pipex(int argc, char **argv, char **envp)
{
	int	filein;
	int	fileout;
	int	*pipe;
	int	i;

	i = 2;
	open_in(&filein, argv[1]);
	fileout = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (filein == -1 || fileout == -1)
		error(1);
	pipe = file_to_pipe(filein, argv, envp, fileout);
	while (++i < argc - 2)
		pipe = pipe_to_pipe(pipe, argv[i], envp);
	pipe_to_file(fileout, pipe, argv[i], envp);
	close(filein);
	close(fileout);
}
