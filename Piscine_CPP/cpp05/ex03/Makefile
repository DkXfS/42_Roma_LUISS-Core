SRC		=	main.cpp\
			Bureaucrat.cpp\
			Form.cpp\
			ShrubberyCreationForm.cpp\
			PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp\
			Intern.cpp

NAME	=	bureaucrats

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
			rm -f $(NAME) *_shrubbery

re:			fclean all

.PHONY:		all clean fclean re