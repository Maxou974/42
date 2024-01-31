/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:39:41 by mabriel           #+#    #+#             */
/*   Updated: 2022/05/03 19:03:43 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_split(char **d)
{
	unsigned int	i;

	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
}

static char	*test_path(char *cmd, char *path)
{
	char	*dst;
	char	*tmp;

	if (!cmd || cmd[0] == 0)
		return (NULL);
	tmp = ft_strjoin(path, "/");
	dst = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!access(dst, F_OK))
		return (dst);
	else
		free(dst);
	return (NULL);
}

static char	*find_path(char *cmd, char **envp)
{
	char			**all_paths;
	char			**tmp;
	char			*dest;
	unsigned int	i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=/", 10))
		i++;
	tmp = ft_split(envp[i], '=');
	all_paths = ft_split(tmp[1], ':');
	free_split(tmp);
	i = -1;
	while (all_paths[++i])
	{
		dest = test_path(cmd, all_paths[i]);
		if (dest)
		{
			free_split(all_paths);
			return (dest);
		}
	}
	free_split(all_paths);
	return (NULL);
}

static void	err(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	exec_ve(char *cmd, char **envp)
{
	char	**tmp;
	char	*path;
	int		ret;

	tmp = ft_quote_split(cmd, ' ');
	if (!access(cmd, F_OK))
		path = cmd;
	else
		path = find_path(tmp[0], envp);
	ret = 0;
	if (!cmd || !tmp || !path)
	{
		free_split(tmp);
		free(path);
		err(cmd);
	}
	else
	{
		ret = execve(path, tmp, envp);
		free_split(tmp);
		free(path);
	}
	if (ret == -1)
		err(cmd);
}
