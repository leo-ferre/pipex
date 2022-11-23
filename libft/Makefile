# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 21:49:21 by leoferre          #+#    #+#              #
#    Updated: 2022/10/25 21:39:24 by leoferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRCS =		ft_atoi.c								\
			ft_bzero.c								\
			ft_calloc.c								\
			ft_isalnum.c							\
			ft_isalpha.c							\
			ft_isascii.c							\
			ft_isdigit.c							\
			ft_isprint.c							\
			ft_itoa.c								\
			ft_memchr.c								\
			ft_memcmp.c								\
			ft_memcpy.c								\
			ft_memmove.c							\
			ft_memset.c								\
			ft_putchar_fd.c							\
			ft_putendl_fd.c							\
			ft_putnbr_fd.c							\
			ft_putstr_fd.c							\
			ft_split.c								\
			ft_strchr.c								\
			ft_strdup.c								\
			ft_striteri.c							\
			ft_strjoin.c							\
			ft_strlcat.c							\
			ft_strlcpy.c							\
			ft_strlen.c								\
			ft_strmapi.c							\
			ft_strncmp.c							\
			ft_strnstr.c							\
			ft_strrchr.c							\
			ft_strtrim.c							\
			ft_substr.c								\
			ft_tolower.c							\
			ft_toupper.c							\
			./get_next_line/get_next_line.c 		\
			./get_next_line/get_next_line_utils.c	\
			./ft_printf/ft_printf.c					\
			./ft_printf/utils/ft_hexa.c 			\
			./ft_printf/utils/ft_percent.c 			\
			./ft_printf/utils/ft_ptr_hexa.c 		\
			./ft_printf/utils/ft_putchar.c 			\
			./ft_printf/utils/ft_putnbr.c 			\
			./ft_printf/utils/ft_putstr.c 			\
			./ft_printf/utils/ft_uns_nbr.c 			

OBJ =		$(SRCS:.c=.o)
RM =		rm -rf
HEADER =	../includes/libft.h
AR =		ar -rcs
CC =		cc
FLAGS =		-Wall -Wextra -Werror

all:	$(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) 

$(NAME):	$(OBJ) $(HEADER)
			$(AR) $(NAME) $(OBJ) $(HEADER)

clean:
		$(RM) $(OBJ)

fclean:	clean 
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re