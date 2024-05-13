#include "model_print.c"

int main(int argc, char *argv[]) {
    int i=14;
    printInteger("integer",i);

    float f=5.6;
    char *s="hello world";
    printFloat(s, f);

    float a = 12.3;
    float b = -3.7;
    printComplex("complex number", a, b);
}
