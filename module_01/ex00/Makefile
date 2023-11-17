# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:54:57 by hleung            #+#    #+#              #
#    Updated: 2023/11/17 11:13:43 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	zombie
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS	=	${SRCS:.cpp=.o}

all:		${NAME}

%.o:		%.cpp Zombie.hpp
			@${CC} ${CFLAGS} -c $< -o $@ -I Zombie.hpp
			
${NAME}:	${OBJS} Zombie.hpp
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
