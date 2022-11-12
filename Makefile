# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 19:29:24 by vicgarci          #+#    #+#              #
#    Updated: 2022/11/12 14:24:04 by vicgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
LIBFT = libft_def/libft_def.a
CLIENT_NAME = client
SERVER_NAME = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT_FILES =  ./client_f/client.c \
				./client_f/parse.c \
				./client_f/set_sigh.c \
				./client_f/sig_handler.c \
				./client_f/transform.c

SERVER_FILES = 	./server_f/server.c \
				./server_f/send_chars.c \
				./server_f/set_sigh.c \
				./server_f/sig_handler.c

CLIENT_OBJS = ${CLIENT_FILES:.c=.o}
SERVER_OBJS = ${SERVER_FILES:.c=.o}

$(MAKE_LIBFT):
	$(MAKE) -C ./libft_def

all: $(MAKE_LIBFT) $(SERVER_NAME) $(CLIENT_NAME) 

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(CLIENT_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(SERVER_OBJS) -o $(SERVER_NAME)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)


re: fclean $(MAKE_LIBFT) $(CLIENT_NAME) $(SERVER_NAME)

.PHONY: all clean fclean re