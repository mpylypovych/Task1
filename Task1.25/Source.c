#define _CRT_SECURE_NO_WARNINGS

/*
25. Використовуючи тільки бітові операції, написати функцію, яка очищує (встановлює в 0) 
наймолодший установлений в 1 біт у заданому беззнаковому довгому цілому числі.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include "myio.h"

//const unsigned len = (unsigned)floor(log10((long double)ULONG_MAX)) + 1;
//#define ULONG_MAX_LENGTH (unsigned)floor(log10((long double)ULONG_MAX)) + 1




void doJob(unsigned long* x)
{
	*x = (*x)&(*x - 1);
}

int main()
{
	unsigned long x = getInput();

	printf("Input in binary representation:\n");

	outputBinary(&x);
	doJob(&x);

	printf("Result:\n%lu\n", x);
	printf("Result in binary representation:\n");
	outputBinary(&x);
	printf("Press Enter to exit.\n");
	getchar(); getchar();
}