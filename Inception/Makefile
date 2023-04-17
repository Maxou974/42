YML=srcs/docker-compose.yml
COMP= HOME=$${HOME} docker compose -f ${YML}

all: 
	mkdir -p $${HOME}/volume
	mkdir -p $${HOME}/volume/db_volume
	mkdir -p $${HOME}/volume/wp_volume
	${COMP} up --build -d

start: all

stop: 
	${COMP} stop

clean:
	docker stop $$(docker ps -qa); \
	docker rm $$(docker ps -qa); \
	docker rmi -f $$(docker images -qa); \
	docker volume rm $$(docker volume ls -q); \
	docker network rm $$(docker network ls -q) 2>/dev/null; return 0
	sudo rm -rf $${HOME}/volume/*

.PHONY: all start clean stop