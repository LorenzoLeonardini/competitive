/**
	UVa 10895 - Matrix Transpose
	by Lorenzo Leonardini
	Submitted: 2018-08-13
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <map>

#define MAX(x, y) (x > y ? x : y)

int main(void)
{
	int w, h;
	while(scanf("%d %d", &h, &w) != EOF)
	{
		std::map<int, int> matrix;

		int indices[MAX(w, h)];

		for(int i = 0; i < h; i++)
		{
			int s;
			scanf("%d", &s);
			if(!s) continue;
			for(int j = 0; j < s; j++)
				scanf("%d", indices + j);
			for(int j = 0; j < s; j++)
			{
				int n;
				scanf("%d", &n);
				matrix[indices[j] - 1 + i * w] = n;
			}
		}

		printf("%d %d\n", w, h);
	
		for(int i = 0; i < w; i++)
		{
			int k = 0;
			for(int j = 0; j < h; j++)
			{
				if(matrix.find(i + j * w) != matrix.end())
					indices[k++] = j;
			}
			printf(k > 0 ? "%d " : "%d", k);
			for(int j = 0; j < k; j++)
				printf(j < k - 1 ? "%d " : "%d", indices[j] + 1);
			printf("\n");
			for(int j = 0; j < k; j++)
				printf(j < k - 1 ? "%d " : "%d", matrix[i + indices[j] * w]);
			printf("\n");
		}
	}

	return 0;
}
