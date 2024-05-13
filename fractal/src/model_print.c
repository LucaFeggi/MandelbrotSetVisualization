#ifndef MODEL_PRINT
#define MODEL_PRINT
#include <stdio.h>

void printInteger(char *a, int b) {
    printf("\t \t %s %d\n", a, b);
}

void printFloat(char *a, float b) {
    printf("%s %.2f\n",a, b);
}

void printComplex(char *a, float b, float c) {
    printf("%s %f \t %fi",a, b, c);
}

void printComplexFormated(char *a, float b, float c) {
    printf("%s %.2f \t + \t %.2fi",a, b, c);
}

void printComplexLn(char *a, float b, float c) {
    printf("%s %.2f + %.2f*i \n",a, b, c);
}
#endif
