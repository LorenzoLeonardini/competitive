#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);

	for(int t = 1; t <= T; t++)
	{
		int walls;
		int high = 0;
		int low = 0;
		int wall;
		scanf("%d %d", &walls, &wall);

		int n;

		walls--;

		while(walls--)
		{
			scanf("%d", &n);

			if(n > wall)
				high++;
			else if(n < wall)
				low++;
			wall = n;
		}

		printf("Case %d: %d %d\n", t, high, low);
	}
	
	return 0;
}
