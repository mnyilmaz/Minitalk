NAME		= minitalk.a

SRCS		= server.c client.c

OBJS		= ${SRCS:.c=.o}

CFLAGS 		= -Wall -Wextra -Werror
CC 			= gcc

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)

clean:
			@rm -f $(OBJS) 

fclean: 	clean
			@rm -f $(NAME)

re:		fclean all

d:
		$(CC) $(CFLAGS) $(SRCS) -o t.exe
		@echo "Compiled"

.PHONY:		all clean fclean re d
