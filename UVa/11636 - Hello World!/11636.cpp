#include <stdio.h>

int main(void)
{
	int n;

	int tPow[20];
	tPow[0] = 1;
	for(int i = 1; i < 20; i++)
		tPow[i] = tPow[i - 1] * 2;

	int t = 0;

	do
	{
		t++;
		scanf("%d", &n);
	
		if(n == 1)
		{
			printf("Case %d: 0\n", t);
			continue;
		}	

		for(int i = 19; i >= 0; i--)
		{
			if(tPow[i] < n)
			{
				printf("Case %d: %d\n", t, i + 1);
				break;
			}
		}
	}
	while(n > 0);
	
	return 0;
}
