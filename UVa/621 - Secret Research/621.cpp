#include <stdio.h>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		char s[10000];
		scanf("%s", s);
		int len = strlen(s);

		if(len == 1)
			printf("+");
		else if(len == 2 && s[0] == '7' && s[1] == '8')
			printf("+");
		else if(len > 2 && s[len - 2] == '3' && s[len - 1] == '5')
			printf("-");
		else if(len > 2 && s[0] == '9' && s[len - 1] == '4')
			printf("*");
		else if(len > 3 && s[0] == '1' && s[1] == '9' && s[2] == '0')
			printf("?");
		else
			printf("+");
		printf("\n");
	}


	return 0;
}
