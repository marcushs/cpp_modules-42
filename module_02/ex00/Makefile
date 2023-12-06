# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 13:06:46 by hleung            #+#    #+#              #
#    Updated: 2023/12/06 15:45:21 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	canon
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Fixed.cpp
OBJS	=	${SRCS:.cpp=.o}

all:		${NAME}

%.o:		%.cpp
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} Fixed.hpp
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
