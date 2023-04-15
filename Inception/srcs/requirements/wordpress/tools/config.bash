#!/bin/bash

DB_NAME="nom_de_la_base_de_donnees"
DB_USER="nom_de_l_utilisateur"
DB_USER_PASSWORD="mot_de_passe_de_l_utilisateur"
DB_ROOT_PASSWORD="rootpassword"

WORDPRESS_URL="mabriel.42.fr"
WORDPRESS_TITLE="mysite"
WORDPRESS_ADMIN_USER="maxime"
WORDPRESS_ADMIN_PASSWORD="maximepassword"
WORDPRESS_ADMIN_EMAIL="maximeabriel974@gmail.com"

if [ ! -e /var/www/wordpress/wp-config.php ]; then
mkdir -p /var/www/wordpress

wp core download --allow-root --path=/var/www/wordpress

wp config create --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_USER_PASSWORD --dbhost="mariadb:3306" --path="/var/www/wordpress/" --allow-root --skip-check

wp core install --url=$WORDPRESS_URL --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --path="/var/www/wordpress/" --allow-root

wp user create $WORDPRESS_DFT_USER $WORDPRESS_DFT_EMAIL --role=author --user_pass=$WORDPRESS_DFT_PASSWORD --allow-root
fi

mkdir -p /run/php
/usr/sbin/php-fpm7.3 -F