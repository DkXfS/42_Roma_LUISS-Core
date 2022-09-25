NAME =	inception

all:		$(NAME)

$(NAME):
			docker compose -f ./srcs/docker-compose.yml up --build

addredirect:
			echo "127.0.0.1 apanthap.42.fr" >> /etc/hosts

clean:
			docker compose -f ./srcs/docker-compose.yml down

cleanvlm:	clean
			rm -rf ~/data/db
			rm -rf ~/data/wordpress

fclean:		clean
			docker system prune -af --volumes

.PHONY:		all clean fclean cleanvlm addredirect $(NAME)