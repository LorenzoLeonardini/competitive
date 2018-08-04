#include <stdio.h>
#include <vector>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		char c;
		int n;

		std::vector<int> indices;

		do
		{
			scanf("%d", &n);
			indices.push_back(n);

			scanf("%c", &c);
		}
		while(c != '\n');

		char nums[indices.size()][1000];

		char f[1000];

		for(int i = 0; i < indices.size(); i++)
		{
			scanf("%s", &f);
			for(int j = 0; j < 1000; j++)
				nums[indices[i] - 1][j] = f[j];
		}

		for(int i = 0; i < indices.size(); i++)
			printf("%s\n", nums[i]);

		if(t > 0)
			printf("\n");
	}

	return 0;
}
