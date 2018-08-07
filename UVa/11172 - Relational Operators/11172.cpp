/**
	UVa 11172 - Relational Operators
	by Lorenzo Leonardini
	Submitted: 2018-06-30
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%c\n", a < b ? '<' : a > b ? '>' : '=');
	}

	return 0;
}
