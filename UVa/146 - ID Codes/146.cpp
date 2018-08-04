#include <stdio.h>
#include <string.h>
#include <algorithm>

int main(void)
{
	char s[1000];

	while(1)
	{
		scanf("%s", &s);
		if(strncmp(s, "#", 1) == 0) break;

		if(std::next_permutation(s, s + strlen(s)))
			printf("%s\n", s);
		else
			printf("No Successor\n");
	}

	return 0;
}