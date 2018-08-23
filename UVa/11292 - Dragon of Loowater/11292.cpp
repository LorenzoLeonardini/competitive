/**
	UVa 11292 - Dragon of Loowater
	by Lorenzo Leonardini
	Submitted: 2018-08-23
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <algorithm>

int main(void)
{
    int n, m;
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        int heads[n];
        int knights[m];
        for(int i = 0; i < n; i++) scanf("%d", heads + i);
        for(int i = 0; i < m; i++) scanf("%d", knights + i);

        int j = 0, i = n;
        int cost = 0;
        if(m < n)
            goto nope;

        std::sort(heads, heads + n);
        std::sort(knights, knights + m);

        for(i = 0; i < n; i++)
        {
            if(j == m)
                break;
            for(; j < m; j++)
            {
                if(knights[j] >= heads[i])
                {
                    cost += knights[j];
                    j++;
                    break;
                }
            }
        }

        if(i == n)
            printf("%d\n", cost);
        else
        nope: printf("Loowater is doomed!\n");
    }

    return 0;
}
