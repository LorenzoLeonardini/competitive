/**
	UVa 11264 - Coin Collector
	by Lorenzo Leonardini
	Submitted: 2018-08-23
	Accepted 0.000 C++
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
        int coins[n];
        for(int i = 0; i < n; i++)
            scanf("%d", coins + i);

        if(n <= 2)
        {
            printf("%d\n", n);
            continue;
        }

        int value = coins[0];
        int count = 1;

        for(int i = 1; i < n - 1; i++)
        if(coins[i] + value < coins[i + 1])
        {
            value += coins[i];
            count++;
        }

        printf("%d\n", count + 1);
    }

    return 0;
}
