FROM debian:buster
RUN apt update -y && apt upgrade -y && apt install nginx -y
COPY ./conf/default /etc/nginx/site-available/default
EXPOSE 80
CMD ["/usr/sbin/nginx", "-g", "daemon off;"]