#include <stdio.h>
#include "printhello.h"
#include "memoryAccessProbe.h"


float average(int *tab, int n);
float variance(int *tab, int n);
void renderToCsv(int *timeaccess, int *timeaccessWithflush, int n);

int main(int argc, char* argv[]){
    if(argc <= 1){
        fprintf(stderr, "Usage %s <n>\n n is the number of the loop\n", argv[0]);
        return -1;
    }
    char *iter = argv[1];
    int iteration = atoi(iter);

    if( iteration <= 0 ){
        fprintf(stderr, "The argument must be a positif number\n");
        return -2;
    }
    int *timeaccess, *timeaccessWithflush;
    timeaccess = calloc(iteration, sizeof(int));
    timeaccessWithflush = calloc(iteration, sizeof(int));
    printhello(iteration);
    printhelloWithFlush(iteration);
    char* ptr = returnPrt();
    for (int i = 0; i < iteration; i++){
        timeaccess[i] = reload(ptr);
        printf("Iteration:%d time access:%d\n", i+1, timeaccess[i]);
    }
    for (int i = 0; i < iteration; i++){
        timeaccessWithflush[i] = reload(ptr);
        flush(ptr);
        printf("Iteration:%d time access:%d\n", i+1, timeaccess[i]);
    }
    printf("\n==== Average:%f Variance:%f ====\n", average(timeaccess, iteration), variance(timeaccess, iteration));
    renderToCsv(timeaccess, timeaccessWithflush, iteration);
    return 0;
}

float average(int *tab, int n){
    float result = 0;
    for(int i = 0; i < n; i++){
        result += tab[i];
    }
    // printf("le total est: %f et le moyenne est %f", result, result/(float(n)));
    return result/(float)n;
}

float variance(int *tab, int n){
    float av = average(tab, n);
    float var = 0;
    // float var2 = 0;
    for(int i = 0; i < n; i++){
        var += tab[i]*tab[i];
    }
    // printf("var: %f vs ", var2/(float)n - av*av);
    // for(int i = 0; i < n; i++){
    //     var += (tab[i] - av)*(tab[i] - av);
    // }
    // printf("Var sarotra %f \n", var/(float)n);
    return var/(float)n - av*av;
}

/**
 * \brief This function will save an array into a CSV file
 * 
 * \param int* tab is the array that containt the data
 * \param int n is the dimension of the array
 * 
 * \return void
 * 
 * */
void renderToCsv(int *timeaccess, int *timeaccessWithflush, int n){
    FILE* csvOutput = NULL;
    char filename[256];
    printf("Enter the filename(max 255 caracteres): ");
    scanf("%s", filename);
    printf("Filename: %s", filename);
    csvOutput = fopen(filename, "w");
    if(csvOutput == NULL){
        fprintf(stderr, "Failed to open file");
        return;
    }
    // fprintf(csvOutput, "iteration,timeaccess,timeaccessWithflush\n");
    // fprintf(stdout, "iteration,timeaccess,timeaccessWithflush\n");
    // printf("iteration,timeaccess\n");
    fprintf(csvOutput, "%d", 0);
    fprintf(stdout, "%d", 0);
    for(int i = 1; i < n; i++){
        fprintf(csvOutput, ",%d", i);
        printf(",%d", i);
    }
    fprintf(csvOutput,"\n");
    fprintf(stdout,"\n");
    fprintf(csvOutput, "%d", timeaccess[0]);
    fprintf(stdout, "%d", timeaccess[0]);
    for(int i = 1; i < n; i++){
        fprintf(csvOutput,",%d", timeaccess[i]);
        fprintf(stdout,",%d", timeaccess[i]);
    }
    fprintf(csvOutput,"\n");
    fprintf(stdout,"\n");
    fprintf(csvOutput, "%d", timeaccessWithflush[0]);
    fprintf(stdout, "%d", timeaccessWithflush[0]);
    for(int i = 1; i < n; i++){
        fprintf(csvOutput,",%d", timeaccessWithflush[i]);
        fprintf(stdout,",%d", timeaccessWithflush[i]);
    }
}