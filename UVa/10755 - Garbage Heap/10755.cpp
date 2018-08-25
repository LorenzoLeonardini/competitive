/**
	UVa 10755 - Garbage Heap
	by Lorenzo Leonardini
	Submitted: 2018-08-25
	Accepted 0.020 C++
*/

#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        long long int table[a][b][c];

        long long int m = -1000000000000000000;

        for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++)
        for(int k = 0; k < c; k++)
        {
            scanf("%lld", &table[i][j][k]);
            if(table[i][j][k] > m)
                m = table[i][j][k];
            if(j > 0) table[i][j][k] += table[i][j - 1][k];
            if(k > 0) table[i][j][k] += table[i][j][k - 1];
            if(j > 0 && k > 0) table[i][j][k] -= table[i][j - 1][k - 1];
        }

        long long int max = m, sum, subrect;
        for(int i = 0; i < b; i++) for(int j = 0; j < c; j++)
        for(int k = i; k < b; k++) for(int l = j; l < c; l++)
        {
            sum = 0;
            for(int w = 0; w < a; w++)
            {
                subrect = table[w][k][l];
                if(i > 0) subrect -= table[w][i - 1][l];
                if(j > 0) subrect -= table[w][k][j - 1];
                if(i > 0 && j > 0) subrect += table[w][i - 1][j - 1];
                sum += subrect;
                if(sum > max) max = sum;
                if(sum < 0) sum = 0;
            }
        }

        printf("%lld\n", max);
        if(t)
            printf("\n");
    }

    return 0;
}
