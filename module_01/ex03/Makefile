# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 14:33:51 by hleung            #+#    #+#              #
#    Updated: 2023/11/17 11:13:22 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	violence
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS	=	${SRCS:.cpp=.o}

all:		${NAME}

%.o:		%.cpp Weapon.hpp HumanA.hpp HumanB.hpp
			@${CC} ${CFLAGS} -c $< -o $@ -I Weapon.hpp HumanA.hpp HumanB.hpp

${NAME}:	${OBJS} Weapon.hpp HumanA.hpp HumanB.hpp
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "Compiling ${NAME}..."
			@echo "Done!"

clean:		
			@rm ${OBJS}

fclean:		clean
			@rm -rf ${NAME}
			@echo "Removing ${NAME}"

re:			
			@make fclean --no-print-directory
			@make all --no-print-directory

.PHONY:		all clean re fclean
