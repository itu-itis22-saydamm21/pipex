/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 05:39:45 by msaydam           #+#    #+#             */
/*   Updated: 2022/11/26 05:42:23 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

void	childproc(char **argv, char **envp, int *fd);
void	parentproc(char **argv, char **envp, int *fd);
char	*detectpath(char *cmd, char **envp);
void	error(void);
void	execmd(char *argv, char **envp);
char	*detectpath(char *cmd, char **envp);

#endif 