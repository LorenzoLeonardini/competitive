#include <stdio.h>

int main(void)
{
	while(true)
	{
		int q;
		scanf("%d", &q);
		if (q == 0) break;
		int cx, cy;
		scanf("%d %d", &cx, &cy);
		while(q--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			if (x == cx || y == cy)
			{
				printf("divisa\n");
				continue;
			}
			char NS = y > cy ? 'N' : 'S';
			char EO = x < cx ? 'O' : 'E';
			printf("%c%c\n", NS, EO);
		}
	}
}
