#include <stdio.h>

int main(void)
{
	while(1)
	{
		int n;
		scanf("%d", &n);

		if(n == 0)
			break;

		int minSp = 50;

		int sp[n];
		for(int i = 0; i < n; i++)
			sp[i] = 0;

		for(int j = 0; j < n; j++)
		{
			char c;
			for(int i = 0; i < 25; i++)
			{
				scanf("%c", &c);
				if(c == '\n')
				{
					i--;
					continue;
				}
				if(c == ' ')
					sp[j]++;
			}
			if(sp[j] < minSp)
				minSp = sp[j];
//			printf("\t%d\n", sp[j]);
		}

		int area = 0;
		for(int i = 0; i < n; i++)
			area += sp[i] - minSp;
		printf("%d\n", area);
	}

	return 0;
}
