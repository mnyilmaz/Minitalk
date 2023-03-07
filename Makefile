NAME_S = server.a
NAME_C = client.a

S_SRC = server.c utils.c
C_SRC = client.c utils.c

S_OBJ = $(S_SRC:.c=.o)
C_OBJ = $(C_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(S_OBJ)
	ar rc $(NAME_S) $(S_OBJ)

$(NAME_C): $(C_OBJ)
	ar rc $(NAME_C) $(C_OBJ)

clean:
	rm -f $(S_OBJ) $(C_OBJ)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all

rm:
	@rm -f server
	@rm -f client

server:
	@$(CC) $(CFLAGS) $(S_SRC) -o server
	@./server

client:
	@$(CC) $(CFLAGS) $(C_SRC) -o client
 
.PHONY: all clean fclean re rm server client
