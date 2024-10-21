#include "toralize.h"


int main( int argc, char *argv[]){

    char *host; //Char pointer for the host that we want to connect to
    int port; 
    int s;
    struct sockaddr_in sock; 

    
    if (argc < 3){
        fprintf(stderr, "Usage: %s <HOST> <PORT>\n" , argv[0]);

        return -1; 
    }

    host = argv[1]; 
    port = atoi(argv[2]); //parses pointer to a string and converts to int

    //Create Socket
    s = socket(AF_INET, SOCK_STREAM, 0); 
    if ( s < 0){
        perror("socket"); 
        return -1;
    }

    //Prepare Structure
    sock.sin_family = AF_INET;
    sock.sin_port = htons(PROXY_PORT);
    sock.sin_addr.s_addr = inet_addr(PROXY);


    if (connect(s, (struct sockaddr *)&sock, sizeof(sock))){
        perror("connect"); 

        return -1; 
    }

    printf("Connected to proxy\n"); 
    close(s); 

    return 0; 
}
