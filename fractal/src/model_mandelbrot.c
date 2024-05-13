#include "model_complexnumber.c"
#include "model_print.c"

/*  MANDELBROT
*/

/*  PRE:    origin o = or + oi·j, 
            element candidate cr + ci·j
    POS:    return 0 if cr + ci·j is not element of M set
            return 1 if cr + ci·j is element of M set
*/
int isMandelbrotElement(float or0, float oi0, float cr, float ci) {
    /* if numiter >= MAXNUMITERTION, cr + ci·j is in M
    */
    const int MAXNUMITERATION = 500;

    int ans=0;

    float zr0 = or0;
    float zi0 = oi0;

    float m = module(zr0, zi0);
    
    int numiter = 0;
    while (m <= 2 && numiter < MAXNUMITERATION) {
       square(zr0, zi0, &zr0, &zi0);
       sum(zr0, zi0, cr, ci, &zr0, &zi0);
       m = module(zr0, zi0);
       
       ++numiter;
    }
    
    ans = m <= 2;

    return ans;

}
