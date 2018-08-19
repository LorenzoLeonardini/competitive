/**
	UVa 1260 - Sales
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.010 C++
*/

#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);
        int values[n];

        int total = 0;

        for(int i = 0; i < n; i++)
        {
            scanf("%d", values + i);
            for(int j = 0; j < i; j++)
                if(values[j] <= values[i])
                    total++;
        }

        printf("%d\n", total);
    }

    return 0;
}
