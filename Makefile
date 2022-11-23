# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:45:32 by leoferre          #+#    #+#              #
#    Updated: 2022/11/17 22:25:49 by leoferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		pipex

SRCS =		./srcs/pipex.c 			\
			./srcs/pipex_utils_1.c 	\
			./srcs/pipex_utils_2.c	\
			./srcs/forks.c			\
			./srcs/exec_cmds.c
			
OBJ =			$(SRCS:.c=.o)
LIBFT_A = 		libft.a
LIBFT_COMPILE = cd libft && make
LIBFT_COPY = 	cp ./libft/libft.a $(LIBFT_A)
LIBFT_FCLEAN = 	cd libft && make fclean
HEADER = 		./includes/pipex.h
RM =			rm -rf
CC =			cc
FLAGS =			-Wall -Wextra -Werror

all:	$(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) 

$(NAME):	$(OBJ) $(HEADER)
			$(LIBFT_COMPILE)
			$(LIBFT_COPY)
			$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_A)

clean:
		$(RM) $(OBJ)
		$(RM) $(LIBFT_A)
		$(LIBFT_FCLEAN)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re