/**
	UVa 599 - The Forrest for the Trees
	by Lorenzo Leonardini
	Submitted: 2018-08-18
	Accepted 0.210 C++
*/

#include <stdio.h>
#include <bitset>
#include <iostream>

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int v = 0;
		int e = 0;
		int a = 0;
		std::bitset<28> set;
		std::bitset<28> vertices;

		while(1)
		{
			char c;
			scanf("%c", &c);
			if(c == '*') break;
			if(c == '(') e++;
			if(c < 'A' || c > 'Z') continue;
			set[c - 'A'] = 1;
		}
		std::cin.ignore(100, '\n');
		while(1)
		{
			char c;
			scanf("%c", &c);
			if(c == '\n') break;
			if(c > 'Z' || c < 'A') continue;
			vertices[c - 'A'] = 1;
			v++;
		}

		for(int i = 0; i < 26; i++)
			if(set[i] == 0 && vertices[i] == 1) a++;

		printf("There are %d tree(s) and %d acorn(s).\n", v - e - a, a);
	}

	return 0;
}
