#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define ITERATIONS 	50

#define a  		16807
#define M 		2147483647
#define q  		127773
#define r 		2836

int main(){

    uint32_t i, Y, Z;
    int32_t s = 0x73f12c81;
    
    for(i=0; i<ITERATIONS; i++){

        Y = s % q;
        Z = s / q;
        s = (int64_t)a*Y - (int64_t)r*Z;
        
        if(s <= 0) s += M;
        
        printf("%d\n", s);
    }
}

