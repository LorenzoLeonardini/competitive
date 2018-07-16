#include <stdio.h>

int main(void)
{
	int b, n;

	while(1)
	{
		scanf("%d %d", &b, &n);

		if(b == 0 && n == 0)
			break;

		int m[b];
		for (int i = 0; i < b; i++)
		{
			int v;
			scanf("%d", &v);
			m[i] = v;
		}

		for(int i = 0; i < n; i++)
		{
			int d, c, v;
			scanf("%d %d %d", &d, &c, &v);
			m[d-1] -= v;
			m[c-1] += v;
		}

		bool possible = true;
		for(int i = 0; i < b; i++)
		{
			if(m[i] < 0)
			{
				possible = false;
				break;
			}
		}

		printf(possible ? "S\n" : "N\n");
	}
	
	return 0;
}
