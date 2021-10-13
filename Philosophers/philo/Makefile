NAME		= philo

BNS_NAME	= philo_bonus

SRCS		=	philosophers_loop.c\
				utils.c\
				utils2.c\
				main.c

BNS_SRCS	=	main.c\
				\

OBJS		= $(SRCS:.c=.o)

BNS_OBJS	= $(BNS_SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

%.o :		%.c
			gcc -c -g $(CFLAGS) $< -o $@

all:		$(NAME)

bonus:		$(BNS_NAME)

$(BNS_NAME)	:	$(BNS_OBJS)
				gcc	$(BNS_OBJS) -o $(BNS_NAME)

$(NAME):	$(OBJS)
			gcc $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re