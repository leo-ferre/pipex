/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:18:41 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 17:14:58 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_hexa(unsigned int num, const char flag)
{
	if (num >= 16)
	{
		ft_hexa(num / 16, flag);
		ft_hexa(num % 16, flag);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd_ptf((num + '0'), 1);
		else
		{
			if (flag == 'x')
				ft_putchar_fd_ptf((num - 10 + 'a'), 1);
			if (flag == 'X')
				ft_putchar_fd_ptf((num - 10 + 'A'), 1);
		}
	}
}

int	ft_put_hexa(unsigned int num, const char flag)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hexa(num, flag);
	return (ft_hexa_len(num));
}
