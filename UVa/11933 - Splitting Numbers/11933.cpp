#include <stdio.h>

int main(void)
{
	int n;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		
		int a = 0, b = 0;
		int k = 1;
		for(int i = 0; i < 32; i++)
		{
			int j = 1 << i;
			if(n & j)
			{
				if(k % 2 == 1)
					a = a | j;
				else
					b = b | j;
				k++;
			}
		}

		printf("%d %d\n", a, b);
	}

	return 0;
}
