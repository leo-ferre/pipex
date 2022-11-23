/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:23:57 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 17:15:15 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ptr_hexa_len(unsigned long int num)
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

void	ft_ptr_hexa(unsigned long int num)
{
	if (num >= 16)
	{
		ft_ptr_hexa(num / 16);
		ft_ptr_hexa(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd_ptf((num + '0'), 1);
		else
			ft_putchar_fd_ptf((num - 10 + 'a'), 1);
	}
}

int	ft_put_ptr_hexa(unsigned long ptr)
{
	int	printf_size;

	printf_size = 0;
	if (ptr == 0)
		printf_size += write (1, "(nil)", 5);
	else
	{
		printf_size += write(1, "0x", 2);
		ft_ptr_hexa(ptr);
		printf_size += ft_ptr_hexa_len(ptr);
	}
	return (printf_size);
}
