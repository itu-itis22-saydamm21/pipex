/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 06:22:52 by msaydam           #+#    #+#             */
/*   Updated: 2022/11/26 06:23:55 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	childproc(char **argv, char **envp, int *fd);
void	parentproc(char **argv, char **envp, int *fd);

void	parentproc(char **argv, char **envp, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	execmd(argv[3], envp);
}

void	childproc(char **argv, char **envp, int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		printf("no file\n");
		error();
	}
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execmd(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	id;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		id = fork();
		if (id == -1)
			error();
		if (id == 0)
		{
			childproc(argv, envp, fd);
		}
		waitpid(id, NULL, 0);
		parentproc(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: required num of args is 5.\n\e[0m", 2);
	}
	return (0);
}
