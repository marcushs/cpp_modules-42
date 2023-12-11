# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 17:37:04 by hleung            #+#    #+#              #
#    Updated: 2023/12/11 09:22:02 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC_DIR		=	srcs/
CLS_DIR		=	classes/
INC			=	include/
OBJ_DIR		=	.objs/

SRC_FILES	=	main.cpp addUtils.cpp
CLS_FILES	=	Contact.cpp PhoneBook.cpp
SRCS		=	${addprefix ${SRC_DIR}, ${SRC_FILES}}
SRCS		+=	${addprefix ${CLS_DIR}, ${CLS_FILES}}
OBJS		=	${addprefix ${OBJ_DIR}, ${SRCS:.cpp=.o}}

${OBJ_DIR}%.o:	%.cpp ${OBJ_DIR} ${INC}Contact.hpp ${INC}PhoneBook.hpp ${INC}main.hpp
				@${CC} ${CFLAGS} -c $< -o $@ -I ${INC}

all:		${NAME}

${NAME}:	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "Compiling ${NAME}..."
			@echo "Done!"

${OBJ_DIR}:
			@mkdir -p ${OBJ_DIR}${CLS_DIR} ${OBJ_DIR}${SRC_DIR}
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
