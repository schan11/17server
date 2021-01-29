#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int server, client;
    char buffer[256];
    
    server = open("send", O_WRONLY);
    client = open("get", O_RDONLY);
    
    sprintf(buffer, "%d", getpid()); // creates private FIFO
    
    remove("./client");
    
    while(1){
        printf("send me a message: \n");
        fgets(buffer, sizeof(buffer), stdin);
        
        write(server, buffer, sizeof(buffer));
        
        read(client, buffer, sizeof(buffer));
        
        // displays response
        printf("here's what you sent me: %s\n\n", buffer);
    }
    
    return 0;
    
}
