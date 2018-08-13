/**
	UVa 11995 - I Can Guess The Data Structure!
	by Lorenzo Leonardini
	Submitted: 2018-08-12
	Accepted 0.670 C++
*/

#include <stdio.h>
#include <queue>
#include <stack>

int main(void)
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		std::stack<char> stack;
		std::queue<char> queue;
		std::priority_queue<char> p_queue;

		char a, b;
		int k, j;
		bool s = true, q = true, pq = true;

		while(n--)
		{
			scanf("%d %d", &k, &j);
			a = (char) k;
			b = (char) j;
			if(a == 1)
			{
				if(s)
					stack.push(b);
				if(q)
					queue.push(b);
				if(pq)
					p_queue.push(b);
			}
			else
			{
				if(s)
				{
					s = !stack.empty() && stack.top() == b;
					stack.pop();
				}
				if(q)
				{
					q = !queue.empty() && queue.front() == b;
					queue.pop();
				}
				if(pq)
				{
					pq = !p_queue.empty() && p_queue.top() == b;
					p_queue.pop();
				}
			}
		}

		if(s && !q && !pq)
			printf("stack\n");
		else if(!s && q && !pq)
			printf("queue\n");
		else if(!s && !q && pq)
			printf("priority queue\n");
		else if(!s && !q && !pq)
			printf("impossible\n");
		else
			printf("not sure\n");
	}

	return 0;
}
