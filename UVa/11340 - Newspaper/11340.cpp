/**
	UVa 11340 - Newspaper
	by Lorenzo Leonardini
	Submitted: 2018-08-14
	Accepted 0.310 C++
*/

#include <stdio.h>
#include <iostream>
#include <map>

// I am aware that mixing scanf and cin is a real mess.
// I KNOW IT'S NOT FAST.

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		std::map<char, double> values;
		char c;
		double val;
		for(int i = 0; i < n; i++)
		{
			std::cin >> c >> val;
			values[c] = val;
		}
		std::cin.ignore();

		double tot = 0;
		int lines;
		scanf("%d", &lines);
		std::cin.ignore();
		while(lines)
		{
			scanf("%c", &c);
			if(c == '\n') lines--;
			if(values.find(c) != values.end())
				tot += values[c];
		}
		printf("%.2f$\n", tot / 100.0);
	}
	
	return 0;
}
