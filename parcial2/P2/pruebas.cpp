#include "pruebas.h"

int* resizeBilinear(int* pixels, int w1, int h1, int w2, int h2)
{
    int* retval = new int[w2*h2] ;
    int a, b, c, d, x, y, index ;
    float x_ratio = ((float)(w1-1))/w2 ;
    float y_ratio = ((float)(h1-1))/h2 ;
    float x_diff, y_diff, blue, red, green ;
    int offset = 0 ;
    for (int i=0;i<h2;i++) {
        for (int j=0;j<w2;j++) {
            x = (int)(x_ratio * j) ;
            y = (int)(y_ratio * i) ;
            x_diff = (x_ratio * j) - x ;
            y_diff = (y_ratio * i) - y ;
            index = (y*w1+x) ;
            a = pixels[index] ;
            b = pixels[index+1] ;
            c = pixels[index+w1] ;
            d = pixels[index+w1+1] ;

            // blue element
            // Yb = Ab(1-w1)(1-h1) + Bb(w1)(1-h1) + Cb(h1)(1-w1) + Db(wh)
            blue = (a&0xff)*(1-x_diff)*(1-y_diff) + (b&0xff)*(x_diff)*(1-y_diff) +
                   (c&0xff)*(y_diff)*(1-x_diff)   + (d&0xff)*(x_diff*y_diff);

            // green element
            // Yg = Ag(1-w1)(1-h1) + Bg(w1)(1-h1) + Cg(h1)(1-w1) + Dg(wh)
            green = ((a>>8)&0xff)*(1-x_diff)*(1-y_diff) + ((b>>8)&0xff)*(x_diff)*(1-y_diff) +
                    ((c>>8)&0xff)*(y_diff)*(1-x_diff)   + ((d>>8)&0xff)*(x_diff*y_diff);

            // red element
            // Yr = Ar(1-w1)(1-h1) + Br(w1)(1-h1) + Cr(h1)(1-w1) + Dr(wh)
            red = ((a>>16)&0xff)*(1-x_diff)*(1-y_diff) + ((b>>16)&0xff)*(x_diff)*(1-y_diff) +
                  ((c>>16)&0xff)*(y_diff)*(1-x_diff)   + ((d>>16)&0xff)*(x_diff*y_diff);

            retval[offset++] =
                    0xff000000 | // hardcoded alpha
                    ((((int)red)<<16)&0xff0000) |
                    ((((int)green)<<8)&0xff00) |
                    ((int)blue) ;
        }
    }
    return retval;
}
