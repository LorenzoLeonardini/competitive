/**
	UVa 1203 - Argus
	by Lorenzo Leonardini
	Submitted: 2018-08-12
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>

struct query {
	int id, rep, time;
};

struct cmp {
	bool operator()(const query &a, const query &b)
	{
		if(a.time != b.time)
			return a.time > b.time;
		return a.id > b.id;
	}
};

int main(void)
{
	std::priority_queue<query, std::vector<query>, cmp> q;
	char s[10];
	while(scanf("%s", s) == 1)
	{
		if(strcmp(s, "#") == 0) break;
		int a, b;
		scanf("%d %d", &a, &b);
		query qq;
		qq.id = a;
		qq.rep = b;
		qq.time = b;
		q.push(qq);
	}

	int n;
	scanf("%d", &n);
	while(n--)
	{
		printf("%d\n", q.top().id);
		query qq = q.top();
		q.pop();
		qq.time += qq.rep;
		q.push(qq);
	}

	return 0;
}
