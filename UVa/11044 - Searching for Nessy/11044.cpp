/**
	UVa 11044 - Searching for Nessy
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
		int w, h;
		scanf("%d %d", &w, &h);
		float sW = (w - 2) / 3.0;
		if(sW != (int) sW) sW++;
		float sH = (h - 2) / 3.0;
		if(sH != (int) sH) sH++;
//		printf("\tsW: %f sH: %f\n", sW, sH);
		printf("%d\n", (int) sW * (int) sH);
	}
}
