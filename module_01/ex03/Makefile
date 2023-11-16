# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 14:33:51 by hleung            #+#    #+#              #
#    Updated: 2023/11/16 14:36:23 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	violence
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

all:		${NAME}
${NAME}:	${SRCS} Weapon.hpp HumanA.hpp HumanB.hpp
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
