/**
	UVa 11450 - Wedding Shopping
	by Lorenzo Leonardini
	Submitted: 2018-08-24
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <cstring>

int prices[25][25];
int m, c;
bool possible[25][210];

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &m, &c);
        for(int i = 0; i < c; i++)
        {
            scanf("%d", &prices[i][0]);
            for(int j = 1; j <= prices[i][0]; j++)
                scanf("%d", &prices[i][j]);
        }

        memset(possible, false, sizeof possible);
        for(int i = 1; i <= prices[0][0]; i++)
            if(m - prices[0][i] >= 0)
                possible[0][m - prices[0][i]] = true;

        for(int i = 1; i < c; i++)
        for(int mon = 0; mon < m; mon++)
        if(possible[i - 1][mon])
            for(int j = 1; j <= prices[i][0]; j++)
            if(mon - prices[i][j] >= 0)
                possible[i][mon - prices[i][j]] = true;

        int money;
        for(money = 0; money <= m && !possible[c - 1][money]; money++);
        if(money == m + 1)
            printf("no solution\n");
        else
            printf("%d\n", m - money);
    }

    return 0;
}
