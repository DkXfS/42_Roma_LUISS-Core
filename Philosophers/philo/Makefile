NAME		= Philosophers

SRCS		=	philosophers_loop.c\
				utils.c\
				main.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

%.o :		%.c
			gcc -c -g $(CFLAGS) $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re