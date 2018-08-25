/**
	UVa 10684 - The jackpot
	by Lorenzo Leonardini
	Submitted: 2018-08-25
	Accepted 0.030 C++
*/

#include <stdio.h>

int main(void)
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(!n) break;

        int nums[n];
        for(int i = 0; i < n; i++) scanf("%d", nums + i);
        long long int sum = 0;
        long long int max = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            if(sum < 0)
                sum = 0;
            if(sum > max)
                max = sum;
        }
        if(max == 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", max);
    }

    return 0;
}
