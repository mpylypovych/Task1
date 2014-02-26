#define _CRT_SECURE_NO_WARNINGS

/*
16. Використовуючи тільки бітові та арифметичні операції, написати функцію, яка повертає 
беззнакове довге ціле число, яке містить блок одиничних бітів довжиною n, починаючи з p-го 
біта (біти нумеруються від 0 справа наліво).
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <stdarg.h>
#include "myio.h"

const unsigned short numOfBits = 8*sizeof(unsigned long);

unsigned long createNumber(const unsigned n,const unsigned p)
{
	unsigned long res = ~0;
	res=res>>(numOfBits-n);
	res=res<<p;
	return res;
}

int main()
{
	printf("Input length and position(non-negative integers):\n");
	unsigned n, p;
	n=(unsigned)getInput(1,sizeof(unsigned long)*8);
	p=(unsigned)getInput(1,sizeof(unsigned long)*8-n);
	
	unsigned long result = createNumber(n,p);

	printf("Result:\n%lu\n", result);
	printf("Result in binary representation:\n");
	outputBinary(&result);
	printf("Press Enter to exit.\n");
	getchar(); getchar();
}