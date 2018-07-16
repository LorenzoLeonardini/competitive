#include "grader.h"
#include "cluedo.h"
#include <stdio.h>

void Solve()
{
	int m = 1, l = 1, w = 1;
	while(1)
	{
//		printf("%d %d %d\n", m, l, w);
		int r = Theory(m, l, w);

//		printf("%d\n", r);

		if(r == 0)
			return;
		if(r == 1) m++;
		else if(r == 2) l++;
		else if(r == 3) w++;
	}
}

