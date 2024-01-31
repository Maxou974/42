YML=srcs/docker-compose.yml
COMP= HOME=$${HOME} docker compose -f ${YML}

all: 
	cp ../.env_inception srcs/.env
	mkdir -p $${HOME}/data
	mkdir -p $${HOME}/data/DB
	mkdir -p $${HOME}/data/WordPress
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

re: stop all

.PHONY: all start re clean stop