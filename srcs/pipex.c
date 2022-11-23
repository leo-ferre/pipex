/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:10:44 by leoferre          #+#    #+#             */
/*   Updated: 2022/11/21 20:28:06 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	pipex(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd_pipe[2];

	arg_number_checker(argc);
	acs_files_checker(argv);
	pipe(fd_pipe);
	pid = fork();
	if (pid == 0)
		child_fork(argv, envp, fd_pipe);
	else
	{
		waitpid(pid, NULL, 0);
		parent_fork(argv, envp, fd_pipe);
	}
	return (0);
}

int	main(int argc, char *argv[], char **envp)
{
	return (pipex(argc, argv, envp));
}
