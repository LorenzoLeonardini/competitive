/**
	UVa 10172 - The Lonesome Cargo Distributor
	by Lorenzo Leonardini
	Submitted: 2018-08-14
	Accepted 0.010 C++
*/

#include <stdio.h>
#include <stack>
#include <queue>

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int num, cap, que;
		scanf("%d %d %d", &num, &cap, &que);
		std::queue<int> stations[num];
		int k, q;
		int toSend = 0;
		std::stack<int> carrier;
		
		for(int i = 0; i < num; i++)
		{
			scanf("%d", &k);
			toSend += k;
			for(int j = 0; j < k; j++)
			{
				scanf("%d", &q);
				stations[i].push(q - 1);
			}
		}

		int time = 0;
		int index = 0;
		while(toSend)
		{
			while(carrier.size())
			{
				if(carrier.top() == index)
				{
					carrier.pop();
					toSend--;
					time++;
				}
				else if(stations[index].size() >= que) break;
				else
				{
					time++;
					stations[index].push(carrier.top());
					carrier.pop();
				}
			}

			while(stations[index].size() && carrier.size() < cap)
			{
				carrier.push(stations[index].front());
				stations[index].pop();
				time++;
			}

			if(toSend)
			{
				time += 2;
				index++;
				index %= num;
			}
		}

		printf("%d\n", time);
	}

	return 0;
}
