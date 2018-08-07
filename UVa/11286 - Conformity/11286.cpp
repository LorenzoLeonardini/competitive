/**
	UVa 11286 - Conformity
	by Lorenzo Leonardini
	Submitted: 2018-08-06
	Accepted 0.030 C++
*/

#include <stdio.h>
#include <algorithm>
#include <map>

long long int genKey(int *arr)
{
	std::sort(arr, arr + 5);

	long long int key = 0;

	for(int i = 0; i < 5; i++)
	{
		int u = arr[i] % 10;
		int d = arr[i] / 10 % 10;
		int c = arr[i] / 100 % 10;

		key = key | (c & 7);
		key = key << 4;
		key = key | (d & 15);
		key = key << 4;
		key = key | (u & 15);
		key = key << 3;
	}

	return key;
}

int main(void)
{
	int n;
	int courses[5];

	while(1)
	{
		scanf("%d", &n);
		if(!n) break;

		std::map<long long int, int> combinations;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < 5; j++)
				scanf("%d", courses + j);
			combinations[genKey(courses)]++;
		}

		int max = 0;
		int num = 0;

		for(std::map<long long int, int>::iterator it = combinations.begin(); it != combinations.end(); it++)
		{
			if(it->second > max)
				max = it->second, num = 0;
			if(it->second == max)
				num++;
		}

		printf("%d\n", num * max);
	}

	return 0;
}
