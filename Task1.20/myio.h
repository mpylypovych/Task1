


//const unsigned len = (unsigned)floor(log10((long double)ULONG_MAX)) + 1;
#ifndef ULONG_MAX_LENGTH
#define ULONG_MAX_LENGTH (unsigned)floor(log10((long double)ULONG_MAX)) + 1
#endif


unsigned long getInput(int count,...)
{
	va_list ap;
    va_start(ap, count); /* Requires the last fixed parameter (to get the address) */
    unsigned long max = ULONG_MAX;
	if(count==1)
	{
        max = va_arg(ap, unsigned long);
	}
    va_end(ap);
	
	unsigned maxLength;
	if(max==ULONG_MAX)
	{
		maxLength=ULONG_MAX_LENGTH;
	}
	else
	{
		maxLength=(unsigned)floor(log10((long double)max)) + 1;
	}
	
	unsigned long x;

	char* s = (char*)malloc((maxLength + 1)*sizeof(char));
	char * pEnd;
	char * pEndC;
	while (true)
	{
		printf("Please enter an integer between 0 and %lu\n", max);
		scanf("%s", s);
		x = strtoul(s, &pEnd, 10);
		
		bool b = 0;
		if ((strlen(s) == maxLength))
		{
			char* temp = (char*)malloc((maxLength + 1)*sizeof(char));
			strncpy(temp,s,maxLength-1);
			if (strtoul(temp, &pEndC, 10) > max / 10)
			{
				b = 1;
			}
			else
			if (strtoul(temp, &pEndC, 10) == max / 10)
			{
				if (s[maxLength - 1] - '0' > max % 10)
				{
					b = 1;
				}
			}
			free(temp);
		}
		if ((strlen(s)>maxLength) || b)
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
	free(s);
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