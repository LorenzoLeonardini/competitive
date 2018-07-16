#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int min = 100, max = -1;
		int n;
		scanf("%d", &n);
		int v;
		while(n--)
		{
			scanf("%d", &v);
			if(v < min)
				min = v;
			if(v > max)
				max = v;
		}
		printf("%d\n", 2 * (max - min));
	}

	return 0;
}
