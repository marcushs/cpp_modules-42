# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:02:03 by hleung            #+#    #+#              #
#    Updated: 2024/01/04 18:02:25 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	mutant
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
				@mkdir -p ${OBJ_DIR}${SRC_DIR}

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
