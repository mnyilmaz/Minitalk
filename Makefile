# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 14:07:58 by mervyilm          #+#    #+#              #
#    Updated: 2023/03/08 15:00:13 by mervyilm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_SRC = server.c utils.c ft_printf.c
C_SRC = client.c utils.c ft_printf.c

CFLAGS = -Wall -Wextra -Werror
CC = gcc

rm:
	@rm -f server
	@rm -f client

server:
	@$(CC) $(CFLAGS) $(S_SRC) -o server
	@$(CC) $(CFLAGS) $(C_SRC) -o client
	@./server

.PHONY: all clean fclean re rm server