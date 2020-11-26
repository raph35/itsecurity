#ifndef PRINTHELLO_H
#define PRINTHELLO_H

#include <stdlib.h>
#include "memoryAccessProbe.h"
#include <stdio.h>

/**
 * @brief This function will print hello followed by the first argument
 *          of the programm
 * @param int n the number of loop for the hello
 * @return void
 * */
void printhello(int n);

/**
 * @brief This function will print hello followed by the first argument
 *          of the programm
 * @param int n the number of loop for the hello
 * @return void
 * */
void printhelloWithFlush(int n);

/**
 * @brief This function will return a function
 * 
 * */
char *returnPrt();
#endif // PRINTHELLO_H
