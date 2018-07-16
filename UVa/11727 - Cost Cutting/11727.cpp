#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		int sum = 0, min = 100000000, max =0;
		for(int i = 0; i < 3; i++)
		{
			int n;
			scanf("%d", &n);
			sum += n;
			if (n < min)
				min = n;
			if (n > max)
				max = n;
		}
		printf("Case %d: %d\n", t, sum - min - max);
	}

	return 0;
}
