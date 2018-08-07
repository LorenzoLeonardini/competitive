/**
	UVa 12015 - Google is Feeling Lucky
	by Lorenzo Leonardini
	Submitted: 2018-07-04
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char url[101];
	int rate;
} site;

int cmp(const void* aa, const void* bb)
{
	site a = *((site*) aa);
	site b = *((site*) bb);
	return a.rate - b.rate;
}

int main(void)
{
	int T;
	scanf("%d", &T);

	site sites[10];

	for(int t = 1; t <= T; t++)
	{
		for(int i = 0; i < 10; i++)
		{
			site n;
			scanf("%s %d", n.url, &n.rate);
			sites[i] = n;
		}

		qsort(&sites, 10, sizeof(site), *cmp);

		int p = 1;
		for(int i = 8; i >= 0; i--)
		{
			if(sites[i].rate == sites[i+1].rate)
				p++;
			else
				break;
		}

		printf("Case #%d:\n", t);

		for(int i = 10 - p; i < 10; i++)
			printf("%s\n", sites[i].url);
	}


	return 0;
}
