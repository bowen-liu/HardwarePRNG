#include <stdio.h>
#include <stdlib.h>

#define WORDSIZE 32

/* The findMS function finds the bit position for the most significant 1 or 0 of an input number, specified by the user.
	Input:
		-y: The input number to be scanned
		-look_for_ms1:  If set to 1, the function will search for the most significant bit that's 1.
				If set to 0, the function will search for the most significant bit that's 0.

*/
int findMS(int y, const int look_for_ms1)
{
	int i;
	int bit_mask;
	
	//Negates the bits of y if we're looking for a most significant 0
	if(!look_for_ms1)
		y = ~y;
	
	//Starting from the MSB, scan y downwards for the most significant bit that's 1
	for(i=WORDSIZE,bit_mask=(1<<WORDSIZE-1); i>0; i--,bit_mask=(bit_mask>>1))
	{
		if ((y & bit_mask) != 0)
			return i;
	}
	
	//No bits are found
	return -1;
}

int mu(int Y)
{
	int ret_val = (Y >= 0 ? 1:-1);
	
	printf("mu=%d,\t", ret_val);
	return ret_val;
}

int findPy(int Y)
{
	if(Y > 0)
		return findMS(Y, 1);	//Find the most significant bit that's 1 in y
	else if (Y < 0)
		return findMS(Y, 0);	//Find the most significant bit that's 0 in y
	else 
		return 0;
}

int findPx(int X)
{
	return findMS(X, 1);
}

int mu_phase2(int Y, int X)
{
	if (Y >= X)
		return 1;
	else if (Y < 0)
		return -1;
	else
		return 0;		//Shouldn't happen
}

/* The main division algorithm that divides Y by X.
	Inputs:
		-Y is the divident
		-X is the divisor
		-r is a pointer to an int where the remainder of Y/X is returned to
		-q is a pointer to an int where the quotient of Y/X is returned to
*/
void divide(int Y, int X, int *r, int *q)
{
	int Z = 0;
	int py = findPy(Y);
	int px = findPx(X);
	
	int i = 0;
	int temp;
	
	printf("\ni=%d\tY=%d,\tZ=%d,\t", i, Y, Z);

	//Algorithm Phase 1
	while(py > px)
	{
		temp = mu(Y) * (1<<(py-px));	//mu*delta
		printf("delta=%d", 1<<(py-px));
		Y = Y - temp * X;
		Z = Z + temp;
		
		printf("\ni=%d\tY=%d,\tZ=%d,\t", ++i, Y, Z);
		
		py=findPy(Y);
		px=findPx(X);	
	}
	printf("\nEnd of phase 1. Y=%d, Z=%d", Y, Z);
	
	//Algorithm Phase 2
	if (!(Y >= 0 && Y < X))
	{
		temp = mu_phase2(Y,X);
		Y = Y - temp*X;
		Z = Z + temp;
	}
	printf("\nEnd of phase 2. Y=%d, Z=%d", Y, Z);
	
	//Return quotient and remainder
	*r = Y;
	*q = Z;
}

int main(int argc, char *argv[])
{
	int Y, X;
	int r, q;
	
	if(argc != 3)
	{
		printf("usage: divide y x\n");
		return -1;
	}
	
	Y = atoi(argv[1]);
	X = atoi(argv[2]);
	
	printf("Inputs: Y = %d, X = %d\n\n", Y, X);
	divide(Y, X, &r, &q);
	printf("\nRemainder = %u, Quotient = %u\n", r, q);	
}
