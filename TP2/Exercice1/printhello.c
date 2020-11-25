#include "printhello.h"

void printhello(int n){
    const char* helloptr = "Hello ";
    for(int i = 0; i < n; i++){
        printf("%s%s:%s\n",helloptr, nameptr, ucnameptr);
    }
    // Instrumentation system
    printf("%p (*ucnameptr) %p (*nameptr) %p (*helloptr)\n", ucnameptr, &*nameptr, &(*helloptr));
    printf("%p (nameptr) %p (helloptr)\n", &nameptr, &helloptr);
    printf("%p (printhello) %p (printf)\n", &printhello, &printf);
}