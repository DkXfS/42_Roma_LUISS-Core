SRC		=	main.cpp\
			Fixed.cpp

NAME	=	fixedPointInt

OBJ		=	$(SRC:.cpp=.o)

CFLAGS	=	-Wall -Wextra -Werror

%.o :		%.cpp
			clang++ -c -g $(CFLAGS) $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			clang++ $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re