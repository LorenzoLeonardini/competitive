/**
	UVa 10954 - Add All
	by Lorenzo Leonardini
	Submitted: 2018-08-12
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>

int main(void)
{
	int n;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;

		std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
		int k;
		while(n--)
		{
			scanf("%d", &k);
			queue.push(k);
		}

		int cost = 0;

		while(queue.size() != 1)
		{
			int a = queue.top();
			queue.pop();
			int b = queue.top();
			queue.pop();
			a += b;
			cost += a;
			queue.push(a);
		}

		printf("%d\n", cost);
	}

	return 0;
}
