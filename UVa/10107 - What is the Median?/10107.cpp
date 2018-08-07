/**
	UVa 10107 - What is the Median?
	by Lorenzo Leonardini
	Submitted: 2018-08-04
	Accepted 0.550 C++
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	int A = *(int*)a;
	int B = *(int*)b;
	return A - B;
}

int main(void)
{
	long long int nums[10002];
	int num = 0;

	while(scanf("%lld", nums + num++) != EOF)
	{
		qsort(nums, num, sizeof(long long int), cmp);

		if(num % 2 == 1)
			printf("%lld\n", nums[num / 2]);
		else
			printf("%lld\n", (nums[num / 2 - 1] + nums[num / 2]) / 2);
	}
	return 0;
}
