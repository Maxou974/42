#!/bin/bash

if [ ! -e /var/www/wordpress/wp-config.php ]; then

wp core download --allow-root

wp config create --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_USER_PASSWORD --dbhost="mariadb:3306" --path="/var/www/wordpress/" --allow-root --skip-check

wp core install --url=$WORDPRESS_URL --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --path="/var/www/wordpress/" --allow-root

wp user create $WORDPRESS_DFT_USER $WORDPRESS_DFT_EMAIL --role=author --user_pass=$WORDPRESS_DFT_PASSWORD --allow-root --path="/var/www/wordpress/"
fi

exec /usr/sbin/php-fpm7.3 -F