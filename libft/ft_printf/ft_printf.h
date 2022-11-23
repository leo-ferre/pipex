/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:01:28 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 17:15:58 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_putchar_ptf(int c);
void	ft_putchar_fd_ptf(char c, int fd);
void	ft_putstr_ptf(char *str);
int		ft_printstr(char *str);
int		ft_ptr_hexa_len(unsigned long int num);
void	ft_ptr_hexa(unsigned long int num);
int		ft_put_ptr_hexa(unsigned long ptr);
void	ft_condition(long nb, int i, char *itoa);
char	*ft_itoa_ptf(int n);
int		ft_putnbr_ptf(int n);
int		ft_num_len(unsigned int num);
char	*ft_uns_itoa(unsigned int n);
int		ft_put_uns_nbr(unsigned int n);
int		ft_hexa_len(unsigned int num);
void	ft_hexa(unsigned int num, const char flag);
int		ft_put_hexa(unsigned int num, const char flag);
int		ft_percent(void);
int		ft_flags(va_list args, const char flag);
int		ft_printf(const char *str, ...);

#endif
