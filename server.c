#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(){
    
    //setup
    int server, client;
    char buffer[256];
    
    //creates FIFO before waiting for connection
    mkfifo("send", 0644);
    mkfifo("get", 0644);
    // mkfifo("WKP",0644); // wasn't sure how to implement this?
    
    //handshake
    
    /*
    server = open("wkp", O_RDONLY);
    read(server, buffer, sizeof(buffer));
    printf("received message.\n");
    close(server);
    
    client = open("wkp", O_WRONLY);
    write(client, buffer, sizeof(buffer));
    printf("acknowledged.\n"); // server connects to client FIFO, sending an initial acknowledgement message
    close(client);
    */
    
    server = open("get", O_RDONLY);
    read(server, buffer, sizeof(buffer));
    client = open("send", O_WRONLY); // connect client to server
    
    remove("./server");
    
    while(1){
        int i = read(server, buffer, sizeof(buffer)); // processes data
        
        write(client, buffer, sizeof(buffer)); // sends back correct response
        
    }

    return 0;
    
}


