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
