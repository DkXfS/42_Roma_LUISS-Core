NAME	=	libasm.a

SRCS	=	srcs/ft_read.s \
			srcs/ft_strcmp.s \
			srcs/ft_strcpy.s \
			srcs/ft_write.s \
			srcs/ft_strdup.s \
			srcs/ft_strlen.s

B_SRCS	=	srcs/bonus/ft_list_size.s \
			srcs/bonus/ft_list_push_front.s \
			srcs/bonus/ft_atoi_base.s \
			srcs/bonus/ft_list_sort.s \

ASM		=	$(SRCS:.s=.o)

B_ASM	=	$(B_SRCS:.s=.o)

CFLAGS	=	-Wall -Wextra -Werror

%.o		:	%.s
			nasm -f macho64 $<

$(NAME)	:	$(ASM)
			ar rcs $(NAME) $(ASM)

all		:	$(NAME)

clean	:
			rm -rf $(ASM) $(B_ASM)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

bonus	:	$(NAME) $(B_ASM)
			ar rcs $(NAME) $(B_ASM)
