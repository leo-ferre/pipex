/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:11:52 by leoferre          #+#    #+#             */
/*   Updated: 2022/11/17 18:31:42 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	verify_quote(char *str)
{
	while (*str)
	{
		if (is_quote(*str))
			return (1);
		str++;
	}
	return (0);
}

void	spaces_fix(char *str)
{
	while (*str && !is_quote(*str))
		str++;
	if (*str)
		str++;
	while (*str && !is_quote(*str))
	{
		if (*str == ' ')
			*str = -1;
		str++;
	}
	if (*str)
		str++;
	if (*str)
		spaces_fix(str);
}

void	quotes_fix(char *str)
{
	while (*str)
	{
		if (is_quote(*str))
			*str = ' ';
		str++;
	}
}

void	put_spaces(char **cmds_args)
{
	char	*str;

	while (*cmds_args)
	{
		str = *cmds_args;
		while (*str)
		{
			if (*str == -1)
				*str = ' ';
			str++;
		}
		cmds_args++;
	}
	return ;
}

int	is_quote(char c)
{
	return (c == '\'');
}
