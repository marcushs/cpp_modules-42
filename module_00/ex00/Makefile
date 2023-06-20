NAME	=	megaphone
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	megaphone.cpp

all:		${NAME}
${NAME}:	${SRCS}
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
