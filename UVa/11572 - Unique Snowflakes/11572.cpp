/**
	UVa 11572 - Unique Snowflakes
	by Lorenzo Leonardini
	Submitted: 2018-08-17
	Accepted 0.260 C++
*/

#include <stdio.h>
#include <queue>
#include <set>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		scanf("%d", &n);
		std::queue<int> series;
		std::set<int> fallen;

		int k;
		int max = 0;

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &k);
			if(fallen.find(k) == fallen.end())
			{
				series.push(k);
				fallen.insert(k);
				continue;
			}
			
			if(series.size() > max)
				max = series.size();

			int q;
			do
			{
				q = series.front();
				series.pop();
				fallen.erase(q);
			}
			while(q != k);

			fallen.insert(k);
			series.push(k);
		}

		if(series.size() > max)
			max = series.size();

		printf("%d\n", max);
	}

	return 0;
}
