/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 05:36:05 by msaydam           #+#    #+#             */
/*   Updated: 2022/11/26 06:25:17 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*detectpath(char *cmd, char **envp);

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	execmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = detectpath(cmd[0], envp);
	if (!path)
	{
		while (cmd[i++])
		{
			free(cmd[i]);
		}
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		error();
	}
}

char	*detectpath(char *cmd, char **envp)
{
	char	**allpaths;
	char	*path;
	char	*part;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	allpaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (allpaths[i])
	{
		part = ft_strjoin(allpaths[i], "/");
		path = ft_strjoin(part, cmd);
		free(part);
		if (access(path, F_OK) == 0)
			return (path);
		free (path);
		i++;
	}
	i = 0;
	while (allpaths[i++])
		free(allpaths[i]);
	free(allpaths);
	return (0);
}
