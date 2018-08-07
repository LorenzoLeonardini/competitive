/**
	UVa 12577 - Hajj-e-Akbar
	by Lorenzo Leonardini
	Submitted: 2018-06-30
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	int t = 1;

	do
	{
		char s[6];
		scanf("%s", s);

		if(strcmp(s, "*") == 0)
			break;
		if(strcmp(s, "Hajj") == 0)
			printf("Case %d: Hajj-e-Akbar\n", t);
		else
			printf("Case %d: Hajj-e-Asghar\n", t);
	}
	while(t++);

	return 0;
}
