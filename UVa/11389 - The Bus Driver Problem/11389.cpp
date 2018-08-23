/**
	UVa 11389 - The Bus Driver Problem
	by Lorenzo Leonardini
	Submitted: 2018-08-23
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <algorithm>
#include <functional>

int main(void)
{
    int n, d, r;

    while(1)
    {
        scanf("%d %d %d", &n, &d, &r);
        if(n == 0 && d == 0 && r == 0) break;

        int morning[n];
        int afternoon[n];
        for(int i = 0; i < n; i++) scanf("%d", morning + i);
        for(int i = 0; i < n; i++) scanf("%d", afternoon + i);

        std::sort(morning, morning + n);
        std::sort(afternoon, afternoon + n, std::greater<int>());

        int count = 0;
        for(int i = 0; i < n; i++)
            if(morning[i] + afternoon[i] - d > 0)
                count += morning[i] + afternoon[i] - d;
        printf("%d\n", count * r);
    }

    return 0;
}
