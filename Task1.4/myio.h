


//const unsigned len = (unsigned)floor(log10((long double)ULONG_MAX)) + 1;
#ifndef ULONG_MAX_LENGTH
#define ULONG_MAX_LENGTH (unsigned)floor(log10((long double)ULONG_MAX)) + 1
#endif


unsigned long getInput()
{
	unsigned long x;

	char* s = (char*)malloc((ULONG_MAX_LENGTH + 1)*sizeof(char));
	char * pEnd;
	char * pEndC;
	while (true)
	{
		printf("Please enter an integer between 0 and %lu\n", ~(unsigned long)0);
		scanf("%s", s);
		x = strtoul(s, &pEnd, 10);
		
		bool b = 0;
		if ((strlen(s) == ULONG_MAX_LENGTH))
		{
			char* temp = (char*)malloc((ULONG_MAX_LENGTH + 1)*sizeof(char));
			strncpy(temp,s,ULONG_MAX_LENGTH-1);
			if (strtoul(temp, &pEndC, 10) > ULONG_MAX / 10)
			{
				b = 1;
			}
			else
			if (strtoul(temp, &pEndC, 10) == ULONG_MAX / 10)
			{
				if (s[ULONG_MAX_LENGTH - 1] - '0' > ULONG_MAX % 10)
				{
					b = 1;
				}
			}
			free(temp);
		}
		if ((strlen(s)>ULONG_MAX_LENGTH) || b)
		{
			printf("Number is too long. Please, try again\n");
		}
		else if ((pEnd != s + strlen(s)) || (s[0]=='-'))
		{
			printf("Your input is not an positive integer\n");
		}
		else
		{
			break;
		}
	}
	free(s);getchar();
	return x;
}

void outputBinary(const unsigned long* x)
{
	for (unsigned long z = ULONG_MAX - (ULONG_MAX >> 1); z > 0; z >>= 1)
	{
		((*x & z) == z) ? printf("1") : printf("0");
	}
	printf("\n");
}