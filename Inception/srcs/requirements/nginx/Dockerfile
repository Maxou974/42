FROM debian:buster

RUN apt update -y && apt upgrade -y && apt install -y nginx openssl
RUN mkdir -p /etc/nginx/key
RUN openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:2048 -out /etc/nginx/key/mabriel.crt -keyout /etc/nginx/key/mabriel.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=mabriel.42.fr/UID=mabriel"

COPY conf/nginx.conf /etc/nginx/sites-available/default

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]