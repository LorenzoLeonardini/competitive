#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		char s[7];
		scanf("%s", s);

		if(s[3] == '\0')
			if((s[0] == 'o' && s[1] == 'n') || (s[0] == 'o' && s[2] == 'e') || (s[1] == 'n' && s[2] == 'e'))
				printf("1\n");
			else
				printf("2\n");
		else
			printf("3\n");
	}

	return 0;
}
