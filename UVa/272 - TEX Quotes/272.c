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
