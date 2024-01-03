# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 20:48:30 by hleung            #+#    #+#              #
#    Updated: 2024/01/02 20:48:38 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	easyfind
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

INC			=	include/
SRC_DIR		=	src/
OBJ_DIR		=	.obj/

SRC_LIST	=	main.cpp
SRCS		=	${addprefix ${SRC_DIR}, ${SRC_LIST}}
OBJS		=	${addprefix ${OBJ_DIR}, ${SRCS:.cpp=.o}}
DEP_FILES	=	${OBJS:.o=.d}

all:			${NAME}

${OBJ_DIR}%.o:	%.cpp | ${OBJ_DIR}
				@${CC} ${CFLAGS} -I ${INC} -MMD -c $< -o $@

${NAME}:		${OBJS}
				@${CC} ${OBJS} -o ${NAME}
				@echo "Compiling ${NAME}..."
				@echo "Done!"

${OBJ_DIR}:
				@mkdir -p ${OBJ_DIR}${SRC_DIR} ${OBJ_DIR}${TMP_DIR}

clean:
				@${RM} ${OBJ_DIR}
				@echo "Removing object files"

fclean:			clean
				@${RM} ${NAME}
				@echo "Removing ${NAME}"

re:
				@make fclean --no-print-directory
				@make all --no-print-directory

.PHONY:			all clean fclean re

-include ${DEP_FILES}
