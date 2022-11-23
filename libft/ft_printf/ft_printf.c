/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:46:48 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 19:30:05 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(va_list args, const char flag)
{
	int	printf_size;

	printf_size = 0;
	if (flag == 'c')
		printf_size += ft_putchar_ptf(va_arg(args, int));
	else if (flag == 'd' || flag == 'i')
		printf_size += ft_putnbr_ptf(va_arg(args, int));
	else if (flag == 's')
		printf_size += ft_printstr(va_arg(args, char *));
	else if (flag == 'p')
		printf_size += ft_put_ptr_hexa(va_arg(args, unsigned long));
	else if (flag == 'u')
		printf_size += ft_put_uns_nbr(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		printf_size += ft_put_hexa(va_arg(args, unsigned int), flag);
	else if (flag == '%')
		printf_size += ft_percent();
	return (printf_size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		printf_size;

	i = 0;
	printf_size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printf_size += ft_flags(args, str[i + 1]);
			i++;
		}
		else
			printf_size += ft_putchar_ptf(str[i]);
		i++;
	}
	va_end(args);
	return (printf_size);
}
