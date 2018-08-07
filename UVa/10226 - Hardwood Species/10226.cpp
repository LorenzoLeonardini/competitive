/**
	UVa 10226 - Hardwood Species
	by Lorenzo Leonardini
	Submitted: 2018-08-06
	Accepted 0.430 C++
*/

#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>

int main(void)
{
	int t;
	scanf("%d\n\n", &t);
	while(t--)
	{
		std::string name;
		std::map<std::string, int> trees;
		float count = 0;
		while(std::getline(std::cin, name))
		{
			if(name.length() == 0) break;
			trees[name]++;
			count++;
		}
		for(std::map<std::string, int>::iterator it = trees.begin(); it != trees.end(); it++)
			printf("%s %.4f\n", it->first.c_str(), (it->second * 100.0) / count);
		if(t > 0)
			printf("\n");
	}

	return 0;
}
