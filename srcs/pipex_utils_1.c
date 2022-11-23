/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:05:34 by leoferre          #+#    #+#             */
/*   Updated: 2022/11/17 22:28:32 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	acs_files_checker(char **argv)
{
	if (access(argv[1], R_OK) == -1)
		perror(argv[1]);
	if (open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644) == -1)
		perror(argv[4]);
	return ;
}

void	arg_number_checker(int argc)
{
	if (argc != 5)
	{
		write(1, "Wrong number of arguments\n", 26);
		exit(1);
	}
}

char	**path_get(char **envp)
{
	char	*envp_path;
	char	**paths;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			break ;
		envp++;
	}
	envp_path = *envp + 5;
	paths = ft_split(envp_path, ':');
	return (paths);
}

void	str_free(char	**str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return ;
}

void	error_printer(char *cmds, char *msgs)
{
	write(2, cmds, ft_strlen(cmds));
	write(2, ": ", ft_strlen(": "));
	write(2, msgs, ft_strlen(msgs));
	write(2, "\n", 1);
	return ;
}
