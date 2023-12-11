# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 09:43:11 by hleung            #+#    #+#              #
#    Updated: 2023/12/11 12:13:51 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	scavtrap
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS	=	${SRCS:.cpp=.o}

all:		${NAME}

%.o:		%.cpp
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} ClapTrap.hpp ScavTrap.hpp
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
