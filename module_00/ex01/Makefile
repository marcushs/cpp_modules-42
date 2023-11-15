# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 17:37:04 by hleung            #+#    #+#              #
#    Updated: 2023/11/15 17:14:53 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp srcs/addUtils.cpp classes/PhoneBook.cpp classes/Contact.cpp 

all:		${NAME}
${NAME}:	${SRCS} include/Contact.hpp include/PhoneBook.hpp include/main.hpp
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
