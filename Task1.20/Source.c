#define _CRT_SECURE_NO_WARNINGS

/*
20. Використовуючи тільки бітові та арифметичні операції, написати функцію, яка виконує 
циклічний зсув заданого беззнакового довгого цілого числа на r бітів уліво.
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

unsigned long cycleShift(const unsigned long x,const unsigned long r)
{
	unsigned long res = x;
	unsigned long mask =~(ULONG_MAX >> r);
	unsigned long extraPart = mask & res;
	extraPart = extraPart >>(numOfBits - r);
	unsigned long mainPart = res << r;
	return mainPart | extraPart;
//	return ( (~(ULONG_MAX >> r) & res) >> (numOfBits - r) ) | (res << r);
}

int main()
{
	unsigned long x, r;
	x=getInput(0);
	printf("Input in binary representation:\n");

	outputBinary(&x);
	r=getInput(1,sizeof(unsigned long)*8);
	
	unsigned long result = cycleShift(x,r);

	printf("Result:\n%lu\n", result);
	printf("Result in binary representation:\n");
	outputBinary(&result);
	printf("Press Enter to exit.\n");
	getchar(); getchar();
}