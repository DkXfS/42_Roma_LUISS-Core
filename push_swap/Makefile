NAME_CHECK	=	checker
NAME_PUSWAP	=	push_swap

SRCS		=	srcs/ops.c \

SRCS_CHECK	=	srcs/checker/checker.c \
				srcs/cmd_route.c \

SRCS_UTILS	=	utils/gnl/get_next_line.c \
				utils/gnl/get_next_line_utils.c \

OBJS_CHECK 	=	$(SRCS_CHECK: .c=.o)

OBJS_UTILS	=	$(SRCS_UTILS: .c=.o)

OBJS_SRCS	=	$(SRCS: .c=.o)

CFLAGS		=	-Wall -Werror -Wextra -I ./headers

%.o:			%.c
				gcc -c -g $(CFLAGS) $< -o $@

$(NAME_CHECK) :	$(OBJS_CHECK) $(OBJS_SRCS) $(OBJS_UTILS)
				gcc -g $(CFLAGS) $(OBJS_SRCS) $(OBJS_CHECK) $(OBJS_UTILS) -o $(NAME_CHECK)

##all :			$(NAME_CHECK)

clean:
				rm -f $(OBJS_CHECK) $(OBJS_SRCS) $(OBJS_UTILS)

fclean:			clean
				rm -f $(NAME_CHECK)
				rm -f $(NAME_PUSWAP)