#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int w;
		scanf("%d", &w);

		char possible = 1;
		int height;

		int y1, y2;
		scanf("%d %d", &y1, &y2);
		height = y1 - y2;
		w--;

		while(w--)
		{
			scanf("%d %d", &y1, &y2);
			if(height != y1 - y2)
				possible = 0;
		}

		if(possible)
			printf("yes\n");
		else
			printf("no\n");

		if(t)
			printf("\n");
	}

	return 0;
}
