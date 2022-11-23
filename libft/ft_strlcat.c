/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:55:40 by leoferre          #+#    #+#             */
/*   Updated: 2022/11/22 17:21:35 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t max_size)
{
	size_t	return_size;

	return_size = 0;
	while (*dst && return_size < max_size)
	{
		dst++;
		return_size++;
	}
	if (return_size >= max_size)
		return (return_size + ft_strlen(src));
	while (*src && return_size + 1 < max_size)
	{
		*dst = *src;
		dst++;
		src++;
		return_size++;
	}
	*dst = '\0';
	return (return_size + ft_strlen(src));
}
