/**
	UVa 10901 - Ferry Loading III
	by Lorenzo Leonardini
	Submitted: 2018-08-06
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <queue>
#include <string.h>
#include <bitset>

int main(void)
{
	int c;
	scanf("%d", &c);
	while(c--)
	{
		int n, t, m;
		scanf("%d %d %d", &n, &t, &m);
		unsigned char carsL[100001] = { 0 };
		unsigned char carsR[100001] = { 0 };
		int time;
		char p[7];
		int maxTime;
		int carsOut[m];
		for(int i = 0; i < m; i++)
		{
			scanf("%d %s", &time, p);
			if(strcmp(p, "left") == 0)
				carsL[time]++;
			else
				carsR[time]++;
			maxTime = time;
		}
		std::queue<int> right;
		std::queue<int> left;
		char pos = 0; // 0 = left, 1 = right
		int changing = 0;
		int counter = 0;

		for(time = 0; time < maxTime + 1 || !right.empty() || !left.empty(); time++)
		{
			if(time < 100001)
			{
			while(carsL[time]--)
				left.push(counter++);
			while(carsR[time]--)
				right.push(counter++);
			}

			if(--changing > 0)
				continue;

			if(pos == 0)
			{
				if(!left.empty())
				{
					for(int i = 0; i < n; i++)
					{
						if(!left.empty())
						{
							carsOut[left.front()] = time + t;
							left.pop();
						}
					}
					pos = 1;
					changing = t;
				}
				else if(!right.empty())
				{
					pos = 1;
					changing = t;
				}
			}
			else
			{
				if(!right.empty())
				{
					for(int i = 0; i < n; i++)
					{
						if(!right.empty())
						{
							carsOut[right.front()] = time + t;
							right.pop();
						}
					}
					pos = 0;
					changing = t;
				}
				else if(!left.empty())
				{
					pos = 0;
					changing = t;
				}
			}
		}
		for(int i = 0; i < m; i++)
			printf("%d\n", carsOut[i]);
		if(c > 0)
			printf("\n");
	}

	return 0;
}
