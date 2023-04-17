YML=srcs/docker-compose.yml
COMP= HOME=$${HOME} docker compose -f ${YML}

all: 
	mkdir -p $${HOME}/data
	mkdir -p $${HOME}/data/db_volume
	mkdir -p $${HOME}/data/wp_volume
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
	sudo rm -rf $${HOME}/data/*

.PHONY: all start clean stop