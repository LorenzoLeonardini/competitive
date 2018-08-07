/**
	UVa 594 - One Little, Two Little, Three Little Endians
	by Lorenzo Leonardini
	Submitted: 2018-08-05
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int q = 0;
		for(int i = 0; i < 4; i++)
			q = (q << 8) | ((n >> (8 * i))&255);

		printf("%d converts to %d\n", n, q);
	}

	return 0;
}
