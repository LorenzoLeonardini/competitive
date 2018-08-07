/**
	UVa 11034 - Ferry Loading IV
	by Lorenzo Leonardini
	Submitted: 2018-08-06
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <queue>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int l, m;
		scanf("%d %d", &l, &m);
		l *= 100;
		std::queue<int> carsL;
		std::queue<int> carsR;

		int cL;
		char p[7];

		for(int i = 0; i < m; i++)
		{
			scanf("%d %s", &cL, p);
			if(strcmp(p, "left") == 0)
				carsL.push(cL);
			else
				carsR.push(cL);
		}

		char pos = 0; // 0 = left, 1 = right;
		int counter = 0;

		while(!carsR.empty() || !carsL.empty())
		{
			int ll = 0;
			if(!pos)
			{
				if(!carsL.empty())
				{
					while(ll + carsL.front() < l)
					{
						if(carsL.empty())
							break;
						ll += carsL.front();
						carsL.pop();
					}
					pos = 1;
					counter++;
				}
				else if(!carsR.empty())
				{
					pos = 1;
					counter++;
				}
			}
			else
			{
				if(!carsR.empty())
				{
					while(ll + carsR.front() < l)
					{
						if(carsR.empty())
							break;
						ll += carsR.front();
						carsR.pop();
					}
					pos = 0;
					counter++;
				}
				else if(!carsL.empty())
				{
					pos = 0;
					counter++;
				}
			}
		}
		printf("%d\n", counter);
	}

	return 0;
}
