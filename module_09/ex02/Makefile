# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 20:16:44 by hleung            #+#    #+#              #
#    Updated: 2024/04/30 20:17:11 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PmergeMe
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

INC			=	include/
SRC_DIR		=	src/
CLS_DIR		=	class/
OBJ_DIR		=	.obj/

SRC_LIST	=	main.cpp
CLS_LIST	=	PmergeMe.cpp
SRCS		=	${addprefix ${SRC_DIR}, ${SRC_LIST}}
SRCS		+=	${addprefix ${CLS_DIR}, ${CLS_LIST}}
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
				@mkdir -p ${OBJ_DIR}${SRC_DIR} ${OBJ_DIR}${CLS_DIR}

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
