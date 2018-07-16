#include <stdio.h>

int main(void)
{
	while(true)
	{
		int months, n;
		float down, perMon, val;
		scanf("%d %f %f %d", &months, &down, &val, &n);
		if(months < 0)
			break;
		float interest[months + 1];
		for (int i = 0; i < months + 1; i++)
			interest[i] = -1;
		for (int i = 0; i < n; i++)
		{
			int j;
			float k;
			scanf("%d %f", &j, &k);
			interest[j] = k;
		}
		float last = 0;
		for (int i = 0; i < months + 1; i++)
			if (interest[i] != -1)
				last = interest[i];
			else
				interest[i] = last;

		perMon = val / months;
		float toBeGiven = val;
		val += down;
//		val = 10500.0;
//		for(int i = 0; i < months + 1; i++)
//			printf("\tMonth %d : %f\n", i, interest[i]);
//		break;

		for (int i = 0; i < months + 1; i++)
		{
			if (i > 0) toBeGiven -= perMon;
			float red = val * interest[i];
//			printf("%f\n", red);
			val -= val * interest[i];
//			printf("\tAfter interest of %f%: ToBeGiven: %f, Value: %f\n", interest[i], toBeGiven, val);
			if(val > toBeGiven)
			{
				if(i == 1)
					printf("1 month\n");
				else
					printf("%d months\n", i);
				break;
			}
		}
	}

	return 0;
}
