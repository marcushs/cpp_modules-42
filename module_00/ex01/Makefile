# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 17:37:04 by hleung            #+#    #+#              #
#    Updated: 2023/11/12 17:37:09 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	megaphone.cpp

all:		${NAME}
${NAME}:	${SRCS}
			@${CC} ${CFLAGS} ${SRCS} -o ${NAME}
			@echo "Compiling ${NAME}..."
			@echo "Done!"
fclean:
			@rm -rf ${NAME}
			@echo "Removing ${NAME}"
re:			
			@make fclean --no-print-directory
			@make all --no-print-directory
.PHONY:		all clean re 