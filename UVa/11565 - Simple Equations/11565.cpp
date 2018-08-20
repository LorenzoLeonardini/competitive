/**
	UVa 11565 - Simple Equations
	by Lorenzo Leonardini
	Submitted: 2018-08-20
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        long long int A, B, C;
        scanf("%lld %lld %lld", &A, &B, &C);

        long long int x, y, z;
        bool sol = false;

        for(x = -1000; x <= A && !sol; x++)
        for(y = x + 1; y <= A && !sol; y++)
        {
            z = A - x - y;
            if(z <= y) continue;
            if(x * y * z != B) continue;
            if(x * x + y * y + z * z != C) continue;
            printf("%d %d %d\n", x, y, z);
            sol = true;
        }

        if(!sol)
            printf("No solution.\n");
    }

    return 0;
}
