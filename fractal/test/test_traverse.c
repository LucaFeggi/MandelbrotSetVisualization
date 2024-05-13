#include "model_traverse.c"

int main(int argc, char *argv[]) {

    /*  abcisses range interval
    */
    float x0 = -2.00f;
    float x1 = 1.00f;
    
    /*  ordenate range interval
    */
    float y0 = 1.50f;
    float y1 = -1.50f;

    /*  interval subdivision, precission
    */
    float d = 0.05f;

    candidates(x0, x1, y0, y1, d);
    return 0;
}
