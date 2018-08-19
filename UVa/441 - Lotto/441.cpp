/**
	UVa 441 - Lotto
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
    int k = -1;
    while(1)
    {
        if(k == -1)
            scanf("%d", &k);
        else
        {
            scanf("%d", &k);
            if(!k) break;
            printf("\n");
        }

        int n[k];
        for(int i = 0; i < k; i++)
            scanf("%d", n + i);

        for(int a = 0; a < k; a++)
            for(int b = a + 1; b < k; b++)
                for(int c = b + 1; c < k; c++)
                    for(int d = c + 1; d < k; d++)
                        for(int e = d + 1; e < k; e++)
                            for(int f = e + 1; f < k; f++)
                                printf("%d %d %d %d %d %d\n", n[a], n[b], n[c], n[d], n[e], n[f]);
    }

    return 0;
}
