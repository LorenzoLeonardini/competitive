/**
	UVa 927 - Integer Sequences from Addition of Terms
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int i;
        scanf("%d", &i);
        long long int coeff[i + 1];
        for(int k = 0; k <= i; k++)
            scanf("%lld", coeff + k);
        int d, k;
        scanf("%d %d", &d, &k);

        int n = 1;
        long long int index = 1;
        while(index <= k)
            index += d * n++;
        n--;
        long long int res = 0;
        for(int q = 0; q <= i; q++)
        {
            long long int temp = coeff[q];
            for(int h = 0; h < q; h++)
                temp *= n;
            res += temp;
        }

        printf("%lld\n", res);
    }
}
