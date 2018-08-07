/**
	UVa 11547 - Automatic Answer
	by Lorenzo Leonardini
	Submitted: 2018-06-30
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		scanf("%d", &n);
		long long result = (n * 567 / 9 + 7492) * 235 / 47 - 498;
		if (result < 0)
			result *= -1;
		printf("%d\n", (result % 100 - result % 10) / 10);
	}

	return 0;
}
