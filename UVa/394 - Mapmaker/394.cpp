#include <stdio.h>
#include <string.h>
#include <vector>

typedef struct
{
	char name[12];
	unsigned int B;
	unsigned int D;
	unsigned int S;
	int L[12];
	int U[12];
	int C[12];
} array;

int calcC(int d, array a)
{
	return a.C[d + 1] * (a.U[d] - a.L[d] + 1);
}

int calcAddress(array a, int *n)
{
	int addr = a.C[0];
	for(int i = 1; i <= a.D; i++)
		addr += a.C[i] * n[i - 1];
	return addr;
}

int main(void)
{
	std::vector<array> arrays;

	int N, R;
	scanf("%d %d", &N, &R);

	while(N--)
	{
		array a;
		scanf("%s", a.name);
		scanf("%d %d %d", &a.B, &a.S, &a.D);
		for(int i = 0; i < a.D; i++)
			scanf("%d %d", a.L + i, a.U + i);
		a.C[a.D] = a.S;
		for(int i = a.D - 1; i > 0; i--)
			a.C[i] = calcC(i, a);
		a.C[0] = a.B;
		for(int i = 1; i <= a.D; i++)
			a.C[0] -= a.C[i] * a.L[i - 1];
//		for(int i = 0; i <= a.D; i++)
//			printf("\tC%d: %d\n", i, a.C[i]);
		arrays.push_back(a);
	}

	while(R--)
	{
		array a;
		char n[12];
		int nums[12];
		scanf("%s", &n);
		for(int i = 0; i < arrays.size(); i++)
		{
			if(strcmp(n, arrays[i].name) == 0)
			{
				a = arrays[i];
				break;
			}
		}

		for(int i = 0; i < a.D; i++)
			scanf("%d", nums + i);

		printf("%s[%d", a.name, nums[0]);
		for(int i = 1; i < a.D; i++)
			printf(", %d", nums[i]);
		printf("] = %d\n", calcAddress(a, nums));
	}

	return 0;
}
