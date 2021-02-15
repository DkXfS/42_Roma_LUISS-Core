service nginx start
service mysql start
service php7.3-fpm start

echo "CREATE DATABASE wordpress;" | mysql -uroot
echo "CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'wordpress';" | mysql -uroot
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost';" | mysql -uroot
echo "FLUSH PRIVILEGES;" | mysql -uroot

bash