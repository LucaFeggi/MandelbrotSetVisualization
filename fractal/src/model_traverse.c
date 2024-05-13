#include "model_print.c"
#include "model_mandelbrot.c"

/*  PRE: abcisses range interval, [x0, x1]
         ordinate range interval, [y0, y1]
         interval subdivision, precission d
*/
void candidates(float x0, float x1, float y0, float y1, float d) {
    for (float j=x0; j<=x1; j=j+d) {
        for (float i=y0; i>= y1; i=i-d) {
            int ans = isMandelbrotElement(0, 0, j, i);
            printComplex("", j, i);
            printInteger("", ans);
        }

    }
}
