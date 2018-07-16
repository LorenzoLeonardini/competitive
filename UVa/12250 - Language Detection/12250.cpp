#include <stdio.h>
#include <string.h>

int main(void)
{
	int t = 1;
	do
	{
		char s[15];
		scanf("%s", s);
		if(strcmp(s, "#") == 0)
			break;

//		printf("\t%d\n", strcmp(s, "HALLO"));
		printf("Case %d: ", t);
		if(strncmp(s, "ZDRAVSTVUJTE", 12) == 0)
			printf("RUSSIAN\n");
		else if(strncmp(s, "HOLA", 4) == 0)
			printf("SPANISH\n");
		else if(strncmp(s, "HELLO", 5) == 0)
			printf("ENGLISH\n");
		else if(strncmp(s, "HALLO", 5) == 0)
			printf("GERMAN\n");
		else if(strncmp(s, "CIAO", 4) == 0)
			printf("ITALIAN\n");
		else if(strncmp(s, "BONJOUR", 7) == 0)
			printf("FRENCH\n");
		else
			printf("UNKNOWN\n");
//		scanf("%[^\n]", s);
//		break;
	}
	while(t++);

	return 0;
}
