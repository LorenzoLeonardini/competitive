#include <stdio.h>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	int sum = 0;

	while(t--)
	{
		char o[7];
		scanf("%s", o);

		if(strcmp(o, "donate") == 0)
		{
			int n;
			scanf("%d", &n);
			sum += n;
		}
		else
			printf("%d\n", sum);
	}

	return 0;
}