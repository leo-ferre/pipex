/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:46:29 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 20:07:00 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned int	ft_test_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

unsigned int	ft_counter_digits_itoa(int n)
{
	unsigned int	counter;

	counter = 1;
	while (n / 10)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	unsigned int	is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	is_negative = ft_test_negative(n);
	if (is_negative == 1)
		n *= -1;
	i = ft_counter_digits_itoa(n) + is_negative;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (is_negative)
		str[0] = '-';
	while (i-- > is_negative)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
