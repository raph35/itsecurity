#include "printhello.h"

void printhello(int n){
    char* helloptr = "Hello ";
    for(int i = 0; i < n; i++){
        // printf("%s%s:%s\n",helloptr, nameptr, ucnameptr);
        printf("The time access of the variable helloptr(printhello) is: %d\n", reload(helloptr));
    }
}

void printhelloWithFlush(int n){
    char* helloptr = "Hello ";
    for(int i = 0; i < n; i++){
        // printf("%s%s:%s\n",helloptr, nameptr, ucnameptr);
        printf("The time access(with flush) of the variable helloptr(printhello) is: %d\n", reload(helloptr));
        flush(helloptr);
    }
}

char *returnPrt(){
    char* helloptr = "Hello ";
    return helloptr;
}