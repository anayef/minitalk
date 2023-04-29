# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anayef <anayef@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 21:50:30 by anayef            #+#    #+#              #
#    Updated: 2023/04/29 16:23:35 by anayef           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
NAME_SERVER = server
NAME_CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
RM = rm -f

all:	${OBJS_SERVER} ${OBJS_CLENT}
			${CC} ${CFLAGS} ${SRCS_SERVER} -o ${NAME_SERVER}
			${CC} ${CFLAGS} ${SRCS_CLIENT} -o ${NAME_CLIENT}

server:	${OBJS_SERVER}
			${CC} ${CFLAGS} ${SRCS_SERVER} -o ${NAME_SERVER}

client:	${OBJS_CLENT}
			${CC} ${CFLAGS} ${SRCS_CLIENT} -o ${NAME_CLIENT}

clean:
			${RM} ${OBJS_SERVER} ${OBJS_CLIENT}

fclean: clean
			${RM} ${OBJS_SERVER} ${OBJS_CLIENT}

re: fclean all

.PHONY: all client server clean fclean re
