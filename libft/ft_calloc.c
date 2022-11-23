/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:00:41 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:04:16 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;
	size_t	fullsize;

	if (nmemb == __SIZE_MAX__ || size == __SIZE_MAX__)
		return (NULL);
	fullsize = nmemb * size;
	new = (void *)malloc(fullsize);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, fullsize);
	return (new);
}
