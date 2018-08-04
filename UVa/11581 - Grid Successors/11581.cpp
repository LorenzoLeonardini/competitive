#include <stdio.h>

char grid[100000][3][3];

int f(int n)
{
	int count = 0;
	for(int x = 0; x < 3; x++)
		for(int y = 0; y < 3; y++)
			count += grid[n][x][y] == '1' ? 1 : 0;
	if(count == 0) return -1;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			int c = 0;
			if(x > 0) c += grid[n][x - 1][y];
			if(x < 2) c += grid[n][x + 1][y];
			if(y > 0) c += grid[n][x][y - 1];
			if(y < 2) c += grid[n][x][y + 1];

			grid[n + 1][x][y] = c % 2 == 0 ? '0' : '1';
		}
	}
	return 1 + f(n + 1);
}

int main(void)
{
	int n;
	char b;
	scanf("%d\n", &n);

	while(n--)
	{
		for(int y = 0; y < 3; y++)
		{
			for(int x = 0; x < 3; x++)
				scanf("%c", &(grid[0][x][y]));
			if(y < 2)
				scanf("\n");
		}
		printf("%d\n", f(0));
		
		if(n >= 1)
			scanf("\n");
	}

	return 0;
}
