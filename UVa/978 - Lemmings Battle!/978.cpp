/**
	UVa 978 - Lemmings Batte!
	by Lorenzo Leonardini
	Submitted: 2018-08-10
	Accepted 0.080 C++
*/

#include <stdio.h>
#include <set>
#include <queue>

struct cmp
{
	bool operator()(const char &a, const char &b)
	{
		return a > b;
	}
};

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int b, sg, sb;
		scanf("%d %d %d", &b, &sg, &sb);

		std::multiset<char, cmp> green;
		std::multiset<char, cmp> blue;

		int tmp;
		for(int i = 0; i < sg; i++)
		{
			scanf("%d", &tmp);
			green.insert((char) tmp);
		}
		for(int i = 0; i < sb; i++)
		{
			scanf("%d", &tmp);
			blue.insert((char) tmp);
		}

		while(!green.empty() && !blue.empty())
		{
			std::queue<char> gr;
			std::queue<char> bl;
			std::multiset<char, cmp>::iterator gIt = green.begin();
			std::multiset<char, cmp>::iterator bIt = blue.begin();
			for(int i = 0; i < b; i++)
			{
				if(green.size() <= i || blue.size() <= i) break;
				gr.push(*(gIt++));
				bl.push(*(bIt++));
			}
			int l = gr.size();
			for(int i = 0; i < l; i++)
			{
				int a = gr.front(), b = bl.front();
				gr.pop();
				bl.pop();
				if(a == b)
				{
					green.erase(green.find(a));
					blue.erase(blue.find(b));
				}
				else if(a > b)
				{
					blue.erase(blue.find(b));
					green.erase(green.find(a));
					green.insert(a - b);
				}
				else
				{
					green.erase(green.find(a));
					blue.erase(blue.find(b));
					blue.insert(b - a);
				}
			}
		}

		if(blue.empty() && green.empty())
		{
			printf("green and blue died\n");
		}
		else if(blue.empty())
		{
			printf("green wins\n");
			for(std::multiset<char, cmp>::iterator it = green.begin(); it != green.end(); it++)
				printf("%d\n", *it);
		}
		else
		{
			printf("blue wins\n");
			for(std::multiset<char, cmp>::iterator it = blue.begin(); it != blue.end(); it++)
				printf("%d\n", *it);
		}
		if(t)
			printf("\n");
	}

	return 0;
}
