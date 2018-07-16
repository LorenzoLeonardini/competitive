#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);

	for(int t = 1; t <= T; t++)
	{
		int n;
		int max = 0;
		scanf("%d", &n);

		while(n--)
		{
			int a;
			scanf("%d", &a);
			if(a > max)
				max = a;
		}

		printf("Case %d: %d\n", t, max);
	}

	return 0;
}
