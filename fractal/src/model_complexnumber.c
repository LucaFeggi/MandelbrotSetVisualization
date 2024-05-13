#include "math.h"

/*  COMPLEX NUMBER LIBRARY
*/

/*  PRE:    complex numbers a+bi and c+di
    POS:    sum of a+bi and c+di in e+fi
*/

void sum(float a, float b, float c, float d, float *e, float *f){
    *e = a + c;
    *f = b + d;
}

/*  PRE:    complex number a + b·i
    POS:    complex number c + d·i = (a + b·i)^2
                            a b·i
                            a b·i
                            ------
                            a·b·i + b·i·b·i
                      a·a + a·b·i
                ------------------------------
                      a^2 + 2·a·b·i - b^2
*/
void square(float a, float b, float *c, float *d) {
    *c = a*a - b*b;
    *d = 2*a*b;
}



/*  PRE:    complex number z = a + b·j
    POS:    module |z|
*/
float module(float a, float b) {
    return sqrt(a*a + b*b);
}

