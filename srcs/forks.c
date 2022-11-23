/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:26:44 by leoferre          #+#    #+#             */
/*   Updated: 2022/11/17 22:28:58 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_fork(char **argv, char **envp, int *fd_pipe)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		exit(0);
	dup2(infile, 0);
	dup2(fd_pipe[1], 1);
	exec_cmds(argv[2], envp);
}

void	parent_fork(char **argv, char **envp, int *fd_pipe)
{
	int	outfile;

	close(fd_pipe[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		exit (1);
	dup2(fd_pipe[0], 0);
	dup2(outfile, 1);
	exec_cmds(argv[3], envp);
}
