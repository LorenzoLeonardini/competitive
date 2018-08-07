/**
	UVa 10300 - Ecological Premium
	by Lorenzo Leonardini
	Submitted: 2018-06-30
	Accepted 0.000 C++
*/

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
