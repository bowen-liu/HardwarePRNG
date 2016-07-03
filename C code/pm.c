#include <stdio.h>

int main(){

    const int a = 16807;
    const int M = 2147483647;
    const int q = 127773;
    const int r = 2836;
      
    int i, Y, Z;
    //int s = 0x7B818935;
    int s = 0x73f12c81;
    
    
    for(i=0;i<10;i++){

        Y = s % q;
        Z = s / q;
        s = (a*Y - r*Z) % M;
        //s = (a*Y - r*Z);
        
        printf("Current Seed: %d\n", s);
    }
}

