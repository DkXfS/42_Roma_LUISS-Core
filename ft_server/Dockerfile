FROM	debian:buster
RUN		apt update
RUN		apt install -y nginx wget mariadb-server openssl
RUN		apt install -y php-mbstring php-fpm php-mysql php-cli php-json

#.::- phpmyadmin -::.#
RUN		mkdir var/www/html/phpmyadmin
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN		tar -xzf phpMyAdmin-5.0.4-english.tar.gz --strip-components=1\
	-C /var/www/html/phpmyadmin && rm -rf phpMyAdmin-5.0.4-english.tar.gz
COPY	srcs/config.inc.php /var/www/html/phpmyadmin

#.::- wordpress -::.#
RUN		wget https://wordpress.org/latest.tar.gz && tar -xzf latest.tar.gz
RUN		mv wordpress /var/www/html/ && rm -rf latest.tar.gz
COPY	srcs/wp-config.php /var/www/html/wordpress

#.::- openssl -::.#
RUN		openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout \
	/etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt\
	-subj "/C=IT/ST=Lazio/L=Roma/O=Ecole 42/OU=42 Roma LUISS/CN=batsy"

#.::- Giving rights to nginx user -::.#
RUN		chown -R www-data: /var/www/*
RUN		chmod -R 755 /var/www/*

#.::- Setting up nginx files -::.#
RUN		rm var/www/html/index.nginx-debian.html
COPY	srcs/nginx.conf /etc/nginx/sites-available/default

#.::- copying scripts and starting initialization -::.#
COPY	srcs/autoindexToggle.sh ./
COPY	srcs/start.sh ./
RUN		chmod +x start.sh autoindexToggle.sh
CMD		./start.sh