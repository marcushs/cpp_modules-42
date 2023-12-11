# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 14:33:51 by hleung            #+#    #+#              #
#    Updated: 2023/12/11 13:40:54 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	violence
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
INC		=	include
SRCS	=	main.cpp classes/Weapon.cpp classes/HumanA.cpp classes/HumanB.cpp
OBJS	=	${SRCS:.cpp=.o}

all:		${NAME}

%.o:		%.cpp 
			@${CC} ${CFLAGS} -c $< -o $@ -I ${INC}

${NAME}:	${OBJS} ${INC}/Weapon.hpp ${INC}/HumanA.hpp ${INC}/HumanB.hpp
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
