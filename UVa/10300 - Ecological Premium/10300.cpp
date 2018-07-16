#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		scanf("%d", &n);
		int sum = 0;
		while(n--)
		{
			int a, b;
			scanf("%d %*d %d", &a, &b);
			sum += a * b;
		}

		printf("%d\n", sum);
	}

	return 0;
}
