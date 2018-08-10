/**
	UVa 11136 - Hoax or what
	by Lorenzo Leonardini
	Submitted: 2018-08-10
	Accepted 0.920 C++
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
	while(1)
	{
		int d;
		scanf("%d", &d);
		if(!d) break;

		std::multiset<int, cmp> bills;

		long long int tot = 0;
		while(d--)
		{
			int n;
			scanf("%d", &n);
			while(n--)
			{
				int k;
				scanf("%d", &k);
				bills.insert(k);
			}
			tot += *(--bills.end()) - *bills.begin();
			bills.erase(--bills.end());
			bills.erase(bills.begin());
		}

		printf("%lld\n", tot);
	}

	return 0;
}
