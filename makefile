all: server client


server: server.c
	gcc -o server server.c

client: client.c
	gcc -o client client.c

clear: 
	rm *.o
	rm server client
