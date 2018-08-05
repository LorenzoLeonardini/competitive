#include <stdio.h>
#include <math.h>

int neighbours(int a, int b, int dim)
{
	int x = a ^ b;
	bool ret = false;
	for(int k = 0; k < dim + 1; k++)
	{
		if(x & 1 == 1)
		{
			if(x != 1) ret = true;
			break;
		}
		x = x >> 1;
	}
	return !ret;
}

int main(void)
{
	int dim;
	while(scanf("%d", &dim) != EOF)
	{
		int size = pow(2, dim);

		int weights[size];
		long long int potencies[size] = { 0 };

		for(int i = 0; i < size; i++)
			scanf("%d", weights + i);

		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				if(i == j) continue;
				if(!neighbours(i, j, dim)) continue;
				potencies[i] += weights[j];
			}
		}

		long long int max = 0;
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				if(i == j) continue;
				if(!neighbours(i, j, dim)) continue;
				if(max < potencies[i] + potencies[j])
					max = potencies[i] + potencies[j];
			}
		}

		printf("%lld\n", max);
	}
	return 0;
}
