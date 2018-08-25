/**
	UVa 10827 - Maximum sum on a torus
	by Lorenzo Leonardini
	Submitted: 2018-08-25
	Accepted 0.320 C++
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
        int table[n * 2][n * 2];

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &table[i][j]);
            table[i][j + n] = table[i][j];
            table[i + n][j] = table[i][j];
            table[i + n][j + n] = table[i][j];
        }

        for(int i = 0; i < n * 2; i++)
        for(int j = 0; j < 2 * n; j++)
        {
            if(i > 0) table[i][j] += table[i - 1][j];
            if(j > 0) table[i][j] += table[i][j - 1];
            if(i > 0 && j > 0) table[i][j] -= table[i - 1][j - 1];
        }

        int max = -1000000;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
        for(int k = i; k < i + n; k++) for(int l = j; l < j + n; l++)
        {
            int sum = table[k][l];
            if(i > 0) sum -= table[i - 1][l];
            if(j > 0) sum -= table[k][j - 1];
            if(i > 0 && j > 0) sum += table[i - 1][j - 1];
            if(sum > max) max = sum;
        }

        printf("%d\n", max);
    }

    return 0;
}
