FROM debian:buster

RUN apt update -y && apt upgrade -y && apt install -y mariadb-server

COPY conf/my.cnf /etc/mysql/my.cnf
COPY tool/script.bash /script.bash

RUN chmod +x script.bash

ENTRYPOINT ["bash", "script.bash"]
