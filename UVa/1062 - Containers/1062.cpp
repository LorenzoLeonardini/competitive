#include <stdio.h>
#include <stack>
#include <string.h>

int main(void)
{
	char in[1001];
	int t = 0;
	while(++t)
	{
		scanf("%s", in);
		if(strcmp(in, "end") == 0) break;
		int size = strlen(in);

		std::stack<char> stacks[28];

		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < 26; j++)
			{
				if(!stacks[j].size())
				{
					stacks[j].push(in[i]);
					break;
				}
				else if(stacks[j].top() >= in[i])
				{
					stacks[j].push(in[i]);
					break;
				}
			}
		}

		int counter = 0;
		while(stacks[counter++].size());

		printf("Case %d: %d\n", t, counter - 1);
	}

	return 0;
}
