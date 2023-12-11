# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 09:43:11 by hleung            #+#    #+#              #
#    Updated: 2023/12/11 15:22:15 by hleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	claptrap
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC_DIR		=	src/
CLS_DIR		=	class/
OBJ_DIR		=	.objs/
INC			=	include/

SRC_FILES	=	main.cpp
CLS_FILES	=	ClapTrap.cpp
SRCS		=	${addprefix ${CLS_DIR}, ${CLS_FILES}}
SRCS		+=	${addprefix ${SRC_DIR}, ${SRC_FILES}}
OBJS		=	${addprefix ${OBJ_DIR}, ${SRCS:.cpp=.o}}
DEP_FILES	=	${OBJS:.o=.d}

all:		${NAME}

${OBJ_DIR}%.o:	%.cpp ${OBJ_DIR}
			@${CC} ${CFLAGS} -I ${INC} -MMD -c $< -o $@ -I ${INC}

${NAME}:	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME} 
			@echo "Compiling ${NAME}..."
			@echo "Done!"

${OBJ_DIR}:
			@mkdir -p ${OBJ_DIR}${SRC_DIR} ${OBJ_DIR}${CLS_DIR}

clean:		
			@rm -rf ${OBJ_DIR}
			@echo "Removing object files"

fclean:		clean
			@rm -rf ${NAME}
			@echo "Removing ${NAME}"

re:			
			@make fclean --no-print-directory
			@make all --no-print-directory

.PHONY:		all clean re fclean
