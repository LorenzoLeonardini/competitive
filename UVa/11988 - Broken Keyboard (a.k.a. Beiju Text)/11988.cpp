/**
	UVa 11988 - Broken Keyboard (a.k.a. Beiju Text)
	by Lorenzo Leonardini
	Submitted: 2018-08-05
	Accepted 0.200 C++
*/

#include <stdio.h>
#include <list>

int main(void)
{
	std::list<char> text;

	std::list<char>::iterator pos = text.begin();

	char c;
	char mode = 0;

	while(scanf("%c", &c) != EOF)
	{
		if(c == ' ' || c == '\n') {}
		else if(c == '[')
		{
			mode = 1;
			pos = text.begin();
		}
		else if(c == ']')
			mode = 0;
		else
		{
			if(mode == 0)
				text.push_back(c);
			else
				text.insert(pos, c);
		}

		if(c == '\n')
		{
			for(std::list<char>::iterator it = text.begin(); it != text.end(); it++)
				printf("%c", *it);
			printf("\n");
			text.clear();
			pos = text.begin();
			mode = 0;
		}
	}

	return 0;
}
