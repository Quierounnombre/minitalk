# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 19:29:24 by vicgarci          #+#    #+#              #
#    Updated: 2022/11/14 14:38:40 by vicgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
LIBFT = libft_def/libft_def.a
CLIENT_NAME = client
SERVER_NAME = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

CLIENT_FILES =  ./client_f/client.c \
				./client_f/parse.c \
				./client_f/set_sigh.c \
				./client_f/sig_handler.c \
				./client_f/transform.c

SERVER_FILES = 	./server_f/server.c \
				./server_f/send_chars.c \
				./server_f/set_sigh.c \
				./server_f/sig_handler.c \
				./server_f/init_global.c

CLIENT_OBJS = ${CLIENT_FILES:.c=.o}
SERVER_OBJS = ${SERVER_FILES:.c=.o}

all: libft $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(CLIENT_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(SERVER_OBJS) -o $(SERVER_NAME)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	$(MAKE) clean -C ./libft_def

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(LIBFT)


re: fclean libft $(CLIENT_NAME) $(SERVER_NAME)

libft:
	$(MAKE) -C ./libft_def

norma:
	@echo 6966205b5b2024286e6f726d696e65747465207c206772657020274572726f7227207c207763202d6c29202d65712030205d5d3b207468656e206e6f726d696e657474653b20656c736520286e6f726d696e65747465207c206772657020274572726f7227293b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re libft norma