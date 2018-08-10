/**
	UVa 11849 - CD
	by Lorenzo Leonardini
	Submitted: 2018-08-10
	Accepted 0.670 C++
*/

#include <stdio.h>
#include <set>

struct cmp
{
	bool operator()(const int &a, const int &b)
	{
		return a < b;
	}
};

int main(void)
{
	int n, m;
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;

		std::set<int, cmp> s;
		int x;
		int count = 0;
		while(n--)
		{
			scanf("%d", &x);
			s.insert(x);
		}
		while(m--)
		{
			scanf("%d", &x);
			if(s.find(x) != s.end())
				count++;
		}
		printf("%d\n", count);
	}
}
