NAME_CHECK	=	checker
NAME_PUSWAP	=	push_swap

SRCS_CHECK	=	srcs/checker/checker.c \
				srcs/checker/ops.c

SRCS_UTILS	=	utils/gnl/get_next_line.c \
				utils/gnl/get_next_line_utils.c

OBJS_CHECK 	=	$(SRCS_CHECK: .c=.o)

OBJS_UTILS	=	$(SRCS_UTILS: .c=.o)

CFLAGS		=	-Wall -Werror -Wextra -I ./headers

%.o :			%.c
				gcc -c -g $(CFLAGS) $< -o $@

$(NAME_CHECK) :	$(OBJS_CHECK)
				gcc -g $(CFLAGS) $(OBJS_CHECK) $(OBJS_UTILS) -o $(NAME_CHECK)

##all :			$(NAME_CHECK)