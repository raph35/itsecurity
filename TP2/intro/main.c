// Code by Raphael

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* nameptr;
char* ucnameptr;
const char OFFSET = 'a' - 'A';

/**
 * @brief This function will print hello followed by the first argument
 *          of the programm
 * @param int n the number of loop for the hello
 * @return void
 * */
void printhello(int n);


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

void printhello(int n){
    const char* helloptr = "Hello ";
    for(int i = 0; i < n; i++){
        printf("%s%s:%s\n",helloptr, nameptr, ucnameptr);
    }
    // Instrumentation system
    printf("Test: %p vs %p", ucnameptr, &*ucnameptr);
    // return;
    printf("%p (*ucnameptr) %p (*nameptr) %p (*helloptr)\n", ucnameptr, &*nameptr, &(*helloptr));
    printf("%p (nameptr) %p (helloptr)\n", &nameptr, &helloptr);
    printf("%p (printhello) %p (printf) %p (main)\n", &printhello, &printf, &main);
}