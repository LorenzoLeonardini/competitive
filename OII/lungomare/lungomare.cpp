#include <stdio.h>

long long int percorri(int N, long long int L, long long int D[], long long int P[])
{
	long long int dist = 0;
	long long int max = 0;

	for(int i = 0; i < N; i++)
	{
		if(i > 0) dist += D[i] - D[i - 1];
		else dist += D[i];
		if (P[i] < dist && P[i] < L - D[i])
		{
			dist += P[i];
			if(dist > max) max = dist;
			dist = P[i];
		}
	}
	dist += L - D[N - 1];
	if (dist > max) max = dist;

	return max;
}
