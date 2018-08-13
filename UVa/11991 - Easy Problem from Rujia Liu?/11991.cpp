/**
	UVa 11991 - Easy Problem from Rujia Liu?
	by Lorenzo Leonardini
	Submitted: 2018-08-13
	Accepted 0.040 C++
*/

#include <stdio.h>
#include <vector>
#include <map>

int main(void)
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		std::map<int, std::vector<int>> map;
		int k;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &k);
			if(map.find(k) != map.end())
				map[k].push_back(i);
			else
			{
				std::vector<int> v;
				v.push_back(i);
				map[k] = v;
			}
		}

		for(int i = 0; i < m; i++)
		{
			int k, v;
			scanf("%d %d", &k, &v);
			if(map.find(v) == map.end())
				printf("0\n");
			else if(map[v].size() <= k - 1)
				printf("0\n");
			else
				printf("%d\n", map[v][k - 1]);
		}
	}

	return 0;
}
