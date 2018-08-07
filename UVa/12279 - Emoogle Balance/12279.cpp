/**
	UVa 12279 - Emoogle Balance
	by Lorenzo Leonardini
	Submitted: 2018-06-30
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
	int t = 1;

	do
	{
		int n;
		scanf("%d", &n);
		if (!n)
			break;

		int count = 0;
		int v;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &v);
			count += v ? 1 : -1;
		}
		printf("Case %d: %d\n", t, count);
	}
	while(t++);

	return 0;
}
