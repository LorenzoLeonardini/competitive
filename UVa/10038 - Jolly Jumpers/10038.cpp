#include <stdio.h>

#define ABS(x) (x > 0 ? x : x * -1)

bool joke(int nums[], int n)
{
	int jolly[n - 1];
	for(int i = 0; i < n - 1; i++)
	{
		jolly[i] = 1;
	}

	for(int i = 0; i < n - 1; i++)
	{
		int index = nums[i + 1] - nums[i];
		if(index < 0)
			index *= -1;
		index--;
//		printf("\t%d\n", index);
		if(index < 0 || index >= n)
		{
//			printf("\t%d\n", index);
			return false;
		}
		if(jolly[index] == 0)
			return false;
		jolly[index] = 0;
	}

	for(int i = 0; i < n - 1; i++)
		if(jolly[i] == 1)
			return false;

	return true;
}

int main(void)
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int nums[n];

		for(int i = 0; i < n; i++)
			scanf("%d", nums + i);

		printf("%s\n", joke(nums, n) ? "Jolly" : "Not jolly");
	}

	return 0;
}

