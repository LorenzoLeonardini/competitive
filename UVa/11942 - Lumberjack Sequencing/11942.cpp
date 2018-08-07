/**
	UVa 11942 - Lumberjack Sequencing
	by Lorenzo Leonardini
	Submitted: 2018-07-04
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	int seq[10];

	printf("Lumberjacks:\n");

	while(t--)
	{
		for(int i = 0; i < 10; i++)
			scanf("%d", seq + i);

		bool maj = seq[1] > seq[0];

		bool right = true;

		if(maj)
		{
			for(int i = 0; i < 9; i++)
				if(seq[i] > seq[i+1])
					right = false;
		}
		else
		{
			for(int i = 0; i < 9; i++)
				if(seq[i] < seq[i+1])
					right = false;
		}

		printf(right ? "Ordered\n" : "Unordered\n");
	}

	return 0;
}
