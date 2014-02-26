#define _CRT_SECURE_NO_WARNINGS

/*
4. Використовуючи тільки бітові операції, написати функцію, яка міняє місцями біти у 2-х заданих 
позиціях беззнакового довгого цілого числа.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include "myio.h"



unsigned long swapBits(const unsigned long x,unsigned short n, unsigned short m)
{
//	return (x & (~((1 << m) | (1 << n)))) | ((((x >> n) & 1) << m) | (((x >> m) & 1) << n));
	unsigned long mask0 = ~((1 << m) | (1 << n)); //0s on n-th and m-th positions
	unsigned long prepx = x&mask0;					//cleared n-th and m-th bits
	unsigned long mask1 = ((x>>n)&1) << m;			//initial n-th bit on m-th position
	unsigned long mask2 = ((x >> m) & 1) << n;		//vice versa
	return prepx | (mask1 | mask2);
}

int main()
{
	unsigned long x = getInput();

	printf("Input in binary representation:\n");

	outputBinary(&x);

	unsigned n, m;

	unsigned short numOfBits = 8*sizeof(unsigned long);
	while(true)
	{
		
		printf("Input positions to be swapped (2 different numbers from 0 to %u):\n", numOfBits);
		scanf("%u %u",&n,&m);
		if(n>=numOfBits)
		{
			printf("First parameter is too big\n");
		}
		else if(m>=numOfBits)
		{
			printf("Second parameter is too big\n");
		}
		else if(n==m)
		{
			printf("Parameters are equal\n");
		}
		else
		{
			break;
		}
	}

	unsigned long result = swapBits(x, n, m);

	printf("Result:\n%lu\n", result);
	printf("Result in binary representation:\n");
	outputBinary(&result);
	printf("Press Enter to exit.\n");
	getchar(); getchar();
}