/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:29:33 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 17:17:04 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_bzero_ptf(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

void	ft_condition(long nb, int i, char *itoa)
{
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	itoa[i] = '\0';
	while (--i >= 0 && itoa[i] != '-')
	{
		itoa[i] = (nb % 10) + 48;
		nb /= 10;
	}
}

char	*ft_itoa_ptf(int n)
{
	long	nb;
	int		i;
	char	*itoa;

	nb = n;
	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	itoa = malloc(sizeof(char) * (i + 1));
	if (!itoa)
		return (NULL);
	ft_bzero_ptf(itoa, i);
	ft_condition(nb, i, itoa);
	return (itoa);
}

int	ft_putnbr_ptf(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa_ptf(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
