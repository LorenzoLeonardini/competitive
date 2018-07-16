#include <stdio.h>

int main(void)
{
	while(1)
	{
		int nums[12];
		if(scanf("%d %d", nums, nums + 1) == EOF)
			break;

		int n = 2;

		char c;
		for(int i = 2; i < 10; i++)
		{
			scanf("%c", &c);
			if(c == '\n') break;
			scanf("%d", nums + i);
			n++;
		}

		int mcm = 1;
		for(int i = 0; i < n; i++)
		{
			int n = 2;
			while(nums[i] > 1)
			{
				for(int j = 0; j < n; j++)
			}
		}
	}

	return 0;
}	
