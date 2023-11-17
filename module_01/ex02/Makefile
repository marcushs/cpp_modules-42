# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 13:10:37 by hleung            #+#    #+#              #
#    Updated: 2023/11/17 11:03:59 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	brain
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp
OBJS	=	${SRCS:.cpp=.o}

all:		${NAME}

%.o:		%.cpp
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "Compiling ${NAME}..."
			@echo "Done!"

clean:		
			@rm ${OBJS}
			@echo "Removing object files"
			
fclean:		clean
			@rm -rf ${NAME}
			@echo "Removing ${NAME}"
re:			
			@make fclean --no-print-directory
			@make all --no-print-directory
.PHONY:		all clean fclean re 
