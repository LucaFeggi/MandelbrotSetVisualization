#include "model_mandelbrot.c"

int main(int argc, char *argv[]) {

    float zr = 0.0f;
    float zi = 0.0f;

    float cr = -1.0f;
    float ci = 0.0f;

    int ans = isMandelbrotElement(zr, zi, cr, ci);
    printInteger("is in mandelbrot set", ans);

    return 0;
}

