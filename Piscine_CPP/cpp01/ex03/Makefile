SRC		=	main.cpp\
			Weapon.cpp\
			HumanA.cpp\
			HumanB.cpp

HEADERS	=	HumanA.hpp\
			HumanB.hpp\
			Weapon.hpp

NAME	=	warfare

OBJ		=	$(SRC:.cpp=.o)

CFLAGS	=	-Wall -Wextra -Werror

%.o :		%.cpp
			clang++ -c -g $(CFLAGS) $< -o $@

all:		$(NAME) $(HEADERS)

$(NAME):	$(OBJ)
			clang++ $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re