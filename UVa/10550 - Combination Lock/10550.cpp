/**
	UVa 10550 - Combination Lock
	by Lorenzo Leonardini
	Submitted: 2018-06-30
	Accepted 0.000 C++
*/

#include <stdio.h>

int degrees(int start, int end, char clockwise)
{
	int diff = 0;
	if(!clockwise)
	{
		if(end > start)
			diff = end - start;
		else
			diff = 40 - (start - end);
	}
	else
	{
		if(start > end)
			diff = start - end;
		else
			diff = 40 - (end - start);
	}
	return diff * 9;
}

int main(void)
{
	int start, f, s, t;
	while(1)
	{
		scanf("%d %d %d %d", &start, &f, &s, &t);
		if(start == 0 && f == 0 && s == 0 && t == 0) break;
		int sum = 360 * 2;
		sum += degrees(start, f, 1);
		sum += 360;
		sum += degrees(f, s, 0);
		sum += degrees(s, t, 1);
		printf("%d\n", sum);
	}
	return 0;
}
