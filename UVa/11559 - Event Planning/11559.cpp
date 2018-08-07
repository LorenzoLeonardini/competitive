/**
	UVa 11559 - Event Planning
	by Lorenzo Leonardini
	Submitted: 2018-07-02
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
	int n, b, h, w;
	while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF)
	{
		int min = b + 100;
		while(h--)
		{
			int ww = w;
			int cost;
			scanf("%d", &cost);
			while(ww--)
			{
				int free;
				scanf("%d", &free);
				if(free >= n)
					if(cost < min)
						min = cost;
			}
		}
		if(min * n <= b)
			printf("%d\n", min * n);
		else
			printf("stay home\n");
	}

	return 0;
}
