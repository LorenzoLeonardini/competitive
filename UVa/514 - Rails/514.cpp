/**
	UVa 514 - Rails
	by Lorenzo Leonardini
	Submitted: 2018-08-05
	Accepted 0.030 C++
*/

#include <stdio.h>
#include <stack>

int main(void)
{
	int size;
	while(1)
	{
		scanf("%d", &size);
		if(size == 0) break;

		while(1)
		{
			int perm[size];

			std::stack<int> st;

			scanf("%d", perm);
			if(perm[0] == 0)
			{
				printf("\n");
				break;
			}
			for(int i = 1; i < size; i++)
				scanf("%d", perm + i);

			int toPush = 1;
//			printf("\tEntering %d\n", toPush);
			st.push(toPush++);
			bool possible = true;
			for(int i = 0; i < size; i++)
			{
//				printf("\t\tChecking %d\n", perm[i]);
				if(perm[i] == st.top())
				{
//					printf("\tExiting %d\n", st.top());
					st.pop();
				}
				else if(perm[i] > st.top())
				{
					while(perm[i] != st.top())
					{
//						printf("\tEntering %d\n", toPush);
						st.push(toPush++);
						if(toPush - 1 > perm[i])
						{
							possible = false;
							break;
						}
					}
					if(!possible) break;
//					printf("\tExiting %d\n", st.top());
					st.pop();
				}
				else
				{
					possible = false;
					break;
				}

				if(st.size() == 0)
				{
//					printf("\tEntering %d\n", toPush);
					st.push(toPush++);
				}
			}
			printf(possible ? "Yes\n" : "No\n");
		}
	}

	return 0;
}
