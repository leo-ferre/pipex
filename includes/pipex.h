/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:15:17 by leoferre          #+#    #+#             */
/*   Updated: 2022/11/22 17:27:34 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>

int		pipex(int argc, char **argv, char **envp);
void	arg_number_checker(int argc);
void	acs_files_checker(char **argv);
void	child_fork(char **argv, char **envp, int *fd_pipe);
void	parent_fork(char **argv, char **envp, int *fd_pipe);
void	exec_cmds(char *cmds, char **envp);
char	**args_check(char *cmds);
char	*path_check(char **cmds_args, char **envp);
char	**path_get(char **envp);
void	str_free(char	**str);
void	error_printer(char *cmds, char *msgs);
int		verify_quote(char *str);
void	spaces_fix(char *str);
void	quotes_fix(char *str);
void	put_spaces(char **cmds_args);
int		is_quote(char c);

#endif