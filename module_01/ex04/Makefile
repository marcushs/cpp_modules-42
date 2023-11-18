# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 11:23:40 by hleung            #+#    #+#              #
#    Updated: 2023/11/18 11:52:57 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	sed
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
# INC		=	include
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

.PHONY:		all clean re fclean
