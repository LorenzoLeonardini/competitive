/**
	UVa 793 - Network Connections
	by Lorenzo Leonardini
	Submitted: 2018-08-18
	Accepted 0.040 C++
*/

#include <stdio.h>
#include <iostream>
#include <vector>

class UnionFind
{
	private:
		std::vector<int> p, rank;
	public:
		UnionFind(int n)
		{
			rank.assign(n + 2, 0);
			p.assign(n + 2, 0);
			for(int i = 0; i < n + 2; i++)
				p[i] = i;
		}
		int findSet(int i)
		{
			return (p[i] == i) ? i : (p[i] = findSet(p[i]));
		}
		bool isSameSet(int i, int j)
		{
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j)
		{
			if(!isSameSet(i, j))
			{
				int x = findSet(i), y = findSet(j);
				if(rank[x] > rank[y])
					p[y] = x;
				else
				{
					p[x] = y;
					if(rank[x] == rank[y]) rank[y]++;
				}
			}
		}
};

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		scanf("%d", &n);
		std::cin.ignore(100, '\n');

		UnionFind set(n);

		char c;
		int a, b, succ = 0, unsucc = 0;
		while(1)
		{
			if(scanf("%c", &c) == EOF) break;
			if(c == '\n') break;

			scanf("%d %d", &a, &b);
			std::cin.ignore(1000, '\n');
			a--;
			b--;
			if(c == 'q')
			{
				if(set.isSameSet(a, b))
					succ++;
				else
					unsucc++;
				continue;
			}

			set.unionSet(a, b);
		}

		printf("%d,%d\n", succ, unsucc);
		if(t)
			printf("\n");
	}

	return 0;
}
