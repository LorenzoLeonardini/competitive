/**
	UVa 11764 - Jumping Mario
	by Lorenzo Leonardini
	Submitted: 2018-07-03
	Accepted 0.000 C++
*/

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
