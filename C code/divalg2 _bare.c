#include <stdio.h>
#include <stdlib.h>

#define WORDSIZE 32

int findMS(int y, const int look_for_ms1)
{
	int i;
	int bit_mask;
	
	if(!look_for_ms1)
		y = ~y;
	
	for(i=WORDSIZE,bit_mask=(1<<WORDSIZE-1); i>0; i--,bit_mask=(bit_mask>>1))
	{
		if ((y & bit_mask) != 0)
			return i;
	}
	return -1;
}

int mu(int Y)
{
	return (Y >= 0 ? 1:-1);
}

int findPy(int Y)
{
	if(Y > 0)
		return findMS(Y, 1);
	else if (Y < 0)
		return findMS(Y, 0);
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

void divide(int Y, int X, int *r, int *q)
{
	int Z = 0;
	int py = findPy(Y);
	int px = findPx(X);
	
	int temp;

	//Algorithm Phase 1
	while(py > px)
	{
		temp = mu(Y) * (1<<(py-px));	//mu*delta
		Y = Y - temp * X;
		Z = Z + temp;
		
		py=findPy(Y);
		px=findPx(X);	
	}
	
	//Algorithm Phase 2
	if (!(Y >= 0 && Y < X))
	{
		temp = mu_phase2(Y,X);
		Y = Y - temp*X;
		Z = Z + temp;
	}
	
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
	
	printf("Inputs: Y = %d, X = %d\n", Y, X);
	divide(Y, X, &r, &q);
	printf("Remainder = %u, Quotient = %u\n", r, q);	
}
