#include "memoryAccessProbe.h"


int reload (char *adrs) {
    volatile unsigned long time;
    asm __volatile__ (
        " rdtscp \n"
        " movl %%eax , %% esi \n"
        " movl (%1) , %% eax \n"
        " lfence \n"
        " rdtscp \n"
        " subl %%esi , %% eax \n"
        : "=a" (time)
        : "b" (adrs)
        : "%esi", "%edx", "%ecx");
    return time;
}


void flush(char *adrs) {
    asm __volatile__ (
        " mfence "
        "\nclflush 0(%0)"
        : : "r" (adrs) :);
}