FROM debian:buster

RUN apt update -y && apt upgrade -y
RUN apt install -y wget php7.3 php-fpm php-mysql

COPY conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY tools/config.bash /

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

ENTRYPOINT ["bash", "config.bash"]