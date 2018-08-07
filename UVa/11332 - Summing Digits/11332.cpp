/**
	UVa 11332 - Summing Digits
	by Lorenzo Leonardini
	Submitted: 2018-06-30
	Accepted 0.000 C++
*/

#include <stdio.h>

long long f(long long n)
{
	long long sum = 0;
	while(n >= 1)
	{
//		printf("\tSUM : %d, UNIT: %d, N: %d\n", sum, n % 10, n);
		sum += n % 10;
		n /= 10;
	}
//	sum += n;
	return sum;
}

int g(long long n)
{
	while(n >= 10)
		n = f(n);
	return n;
}

int main(void)
{
	long long n;
	while(1)
	{
		scanf("%lld", &n);
		if(!n)
			break;
		printf("%d\n", g(n));
	}
	return 0;
}
