/**
	UVa 10487 - Closest Sums
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.010 C++
*/

#include <stdio.h>

int main(void)
{
    int t = 1, n;

    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;

        printf("Case %d:\n", t++);

        long long int numbers[n];
        for(int i = 0; i < n; i++)
            scanf("%lld", numbers + i);

        int queries;
        scanf("%d", &queries);

        for(int q = 0; q < queries; q++)
        {
            long long int min = 100000000000;
            long int sum = -1;
            long long int k;
            scanf("%lld", &k);
            for(int i = 0; i < n; i++)
                for(int j = i + 1; j < n; j++)
                {
                    long long int diff = numbers[i] + numbers[j] - k;
                    if (diff < 0) diff *= -1;
                    if(diff < min)
                    {
                        min = diff;
                        sum = numbers[i] + numbers[j];
                    }
                }
            printf("Closest sum to %lld is %lld.\n", k, sum);
        }
    }

    return 0;
}
