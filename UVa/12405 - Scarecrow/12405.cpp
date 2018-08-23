/**
	UVa 12405 - Scarecrow
	by Lorenzo Leonardini
	Submitted: 2018-08-23
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        int n;
        scanf("%d", &n);
        char s[n + 1];
        scanf("%s", s);

        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '.')
            {
                count++;
                i += 2;
            }
        }

        printf("Case %d: %d\n", t, count);
    }

    return 0;
}
