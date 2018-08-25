/**
	UVa 108 - Maximum Sum
	by Lorenzo Leonardini
	Submitted: 2018-08-25
	Accepted 0.030 C++
*/

#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int table[n][n];

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        scanf("%d", &table[i][j]);
        if(i > 0) table[i][j] += table[i - 1][j];
        if(j > 0) table[i][j] += table[i][j - 1];
        if(i > 0 && j > 0) table[i][j] -= table[i - 1][j - 1];
    }

    int max = -2000000;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
    for(int k = i; k < n; k++) for(int l = j; l < n; l++)
    {
        int temp = table[k][l];
        if(i > 0) temp -= table[i - 1][l];
        if(j > 0) temp -= table[k][j - 1];
        if(i > 0 && j > 0) temp += table[i - 1][j - 1];
        if(temp > max)
            max = temp;
    }

    printf("%d\n", max);

    return 0;
}
