/**
	UVa 12372 - Packing for Holiday
	by Lorenzo Leonardini
	Submitted: 2018-06-30
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int L, W, H;
		scanf("%d %d %d", &L, &W, &H);
		if(L <= 20 && W <= 20 && H <= 20)
			printf("Case %d: good\n", t);
		else
			printf("Case %d: bad\n", t);
	}

	return 0;
}
