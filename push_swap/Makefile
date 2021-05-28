NAME_CHECK	=	checker
NAME_PUSWAP	=	push_swap

SRC			=	srcs/ops.c \
				srcs/ops2.c \

SRC_CHECK	=	srcs/checker/checker.c \

SRC_UTILS	=	utils/gnl/get_next_line.c \
				utils/gnl/get_next_line_utils.c \

SRC_PUSWAP	=	srcs/push_swap/op_masks.c \
				srcs/push_swap/optimize_moves.c \
				srcs/push_swap/push_swap.c \
				srcs/push_swap/supp_func.c \

OBJ_CHECK 	=	$(SRC_CHECK:.c=.o)

OBJ_UTILS	=	$(SRC_UTILS:.c=.o)

OBJ_SRC		=	$(SRC:.c=.o)

OBJ_PUSWAP	=	$(SRC_PUSWAP:.c=.o)

CFLAGS		=	-Wall -Werror -Wextra -I ./headers

%.o :			%.c
				gcc -c -g $(CFLAGS) $< -o $@

$(NAME_CHECK) :	$(OBJ_SRC) $(OBJ_UTILS) $(OBJ_CHECK) 
				gcc -g $(CFLAGS) $(OBJ_SRC) $(OBJ_CHECK) $(OBJ_UTILS) -o $(NAME_CHECK)

$(NAME_PUSWAP):	$(OBJ_SRC) $(OBJ_UTILS) $(OBJ_PUSWAP)
				gcc -g $(CFLAGS) $(OBJ_UTILS) $(OBJ_SRC) $(OBJ_PUSWAP) -o $@

all :			$(NAME_PUSWAP)

clean :
				rm -f $(OBJ_CHECK) $(OBJ_SRC) $(OBJ_UTILS) $(OBJ_PUSWAP)

fclean :		clean
				rm -f $(NAME_CHECK)
				rm -f $(NAME_PUSWAP)
