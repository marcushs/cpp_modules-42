# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 17:37:04 by hleung            #+#    #+#              #
#    Updated: 2023/11/17 11:14:14 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp srcs/addUtils.cpp classes/PhoneBook.cpp classes/Contact.cpp
INC			=	include
DIR_OBJS	=	.objs/
LIST_OBJS	=	${SRCS:.cpp=.o}
OBJS		=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}

${DIR_OBJS}%.o:	%.cpp ${DIR_OBJS} ${INC}/Contact.hpp ${INC}/PhoneBook.hpp ${INC}/main.hpp
				@${CC} ${CFLAGS} -c $< -o $@ -I ${INC}

all:		${NAME}

${NAME}:	${OBJS} ${DIR_OBJS} ${INC}/Contact.hpp ${INC}/PhoneBook.hpp ${INC}/main.hpp
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "Compiling ${NAME}..."
			@echo "Done!"

${DIR_OBJS}:
			@mkdir -p .objs
			@mkdir -p .objs/srcs
			@mkdir -p .objs/classes

clean:
			@rm -rf .objs
			@echo "Removing object files"

fclean:		clean
			@rm -rf ${NAME}
			@echo "Removing ${NAME}"
			
re:			
			@make fclean --no-print-directory
			@make all --no-print-directory
			
.PHONY:		all clean re fclean
