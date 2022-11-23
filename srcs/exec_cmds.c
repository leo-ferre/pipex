/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:34:36 by leoferre          #+#    #+#             */
/*   Updated: 2022/11/22 17:34:29 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_cmds(char *cmds, char **envp)
{
	char	**cmds_args;
	char	*cmds_path;

	cmds_args = args_check(cmds);
	cmds_path = path_check(cmds_args, envp);
	execve(cmds_path, cmds_args, envp);
	exit(1);
}

char	**args_check(char *cmds)
{
	char	**arguments;

	if (verify_quote(cmds))
	{
		spaces_fix(cmds);
		quotes_fix(cmds);
		arguments = ft_split(cmds, ' ');
		put_spaces(arguments);
	}
	else
		arguments = ft_split(cmds, ' ');
	return (arguments);
}

char	*path_check(char **cmds_args, char **envp)
{
	int		i;
	char	*cmds_path;
	char	**paths;

	i = 0;
	paths = path_get(envp);
	cmds_path = malloc(sizeof(char) * (PATH_MAX + 1));
	while (paths[i])
	{
		ft_strlcat(cmds_path, paths[i], PATH_MAX);
		ft_strlcat(cmds_path, "/", PATH_MAX);
		ft_strlcat(cmds_path, cmds_args[0], PATH_MAX);
		if (access(cmds_path, X_OK) == 0)
		{
			str_free(paths);
			return (cmds_path);
		}
		*cmds_path = 0;
		i++;
	}
	error_printer(cmds_args[0], "command not found");
	str_free(paths);
	str_free(cmds_args);
	free(cmds_path);
	exit(127);
}
