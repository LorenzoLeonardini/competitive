/**
	UVa 272 - TEX Quotes
	by Lorenzo Leonardini
	Submitted: 2018-06-30
	Accepted 0.000 C
*/

#include <stdio.h>

#define true 1
#define false 2

int main(void)
{
	char left = true;

/*	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w"); */

	char c;

	while(scanf("%c", &c) != EOF)
	{
		if(c != '"')
			printf("%c", c);
		else
		{
			if(left)
				printf("``");
			else
				printf("''");
			left++;
			left %= 2;
		}
	}

/*	fclose(in);
	fclose(out); */

	return 0;
}
