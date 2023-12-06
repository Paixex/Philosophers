# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:56:38 by digil-pa          #+#    #+#              #
#    Updated: 2023/12/06 15:24:48 by digil-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS	=	checkers.c			\
			init.c				\
			main.c				\
			philo_utils.c		\
			routine.c			\
			threads.c			\
			
OBJS	=	$(SRCS:.c=.o)

CC	=	cc

RM	=	rm	-f

CFLAGS	=	-Wall	-Wextra	-Werror	-pthread -fsanitize=thread

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC)	$(CFLAGS)	$(OBJS)	-o	$(NAME)

clean:
			$(RM)	$(OBJS)

fclean:		clean
			$(RM)	$(NAME)

re:			fclean $(NAME)

.PHONY:		all	clean	fclean	re