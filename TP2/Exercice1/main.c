#include <stdio.h>
#include "global.h"
#include "printhello.h"

const char OFFSET = 'a' - 'A';

int main(int argc, char* argv[]){
    // Checking if there are no argument
    if( argc <= 1 ){
        printf("Usage: %s <name>\n", argv[0]);
        return -1;
    }
    nameptr = argv[1];

    // Getting the length of the argument number one
    size_t len = strlen(nameptr);

    // Allocate dynamically the memory of ucnameptr
    // ucnameptr = malloc((len + 1) * sizeof(char));
    ucnameptr = calloc(len + 1 ,sizeof(char));

    // Process the transformation to uppercase
    for(size_t i = 0; i < len; i++){
        char c = *(nameptr + i);
        // if(c > 96 && c < 122)
        //     ucnameptr[i] = c - 32;
        // else
        // {
        //     ucnameptr[i] = c;
        // }
        ucnameptr[i] = c - ((c > 96 && c < 122)? OFFSET: 0);        
    }
    ucnameptr[len] = '\0';

    // Extracting the PID of the running process
    pid_t pid = getpid();
    // printf("The pid of the running process is %d\n", (int)pid);
    // Calling the function hello
    printhello(2);
    // Showing the results
    char cmd[50];
    sprintf(cmd, "cat /proc/%d/maps", getpid());
    system(cmd);

    free(ucnameptr);
    // free(nameptr);

    return 0;
}