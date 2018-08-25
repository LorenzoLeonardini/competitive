/**
	UVa 11951 - Area
	by Lorenzo Leonardini
	Submitted: 2018-08-25
	Accepted 0.160 C++
*/

#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        int n, m, budget;
        scanf("%d %d %d", &n, &m, &budget);

        int table[n][m];

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &table[i][j]);
            if(i > 0) table[i][j] += table[i - 1][j];
            if(j > 0) table[i][j] += table[i][j - 1];
            if(i > 0 && j > 0) table[i][j] -= table[i - 1][j - 1];
        }

        int max = 0;
        int p = budget + 1;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
        for(int k = i; k < n; k++) for(int l = j; l < m; l++)
        {
            int area = (k - i + 1) * (l - j + 1);
            if(area < max) continue;
            int sum = table[k][l];
            if(i > 0) sum -= table[i - 1][l];
            if(j > 0) sum -= table[k][j - 1];
            if(i > 0 && j > 0) sum += table[i - 1][j - 1];
            if(sum > budget) continue;
            if(area == max)
            {
                if(sum < p)
                    p = sum;
            }
            else
            {
                max = area;
                p = sum;
            }
        }

        if(max == 0) p = 0;
        printf("Case #%d: %d %d\n", t, max, p);
    }

    return 0;
}
