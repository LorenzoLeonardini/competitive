/**
	UVa 10656 - Maximum Sum (II)
	by Lorenzo Leonardini
	Submitted: 2018-08-23
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(!n) break;

        int seq[n];
        int count = 0;
        int k;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &k);
            if(k != 0)
                seq[count++] = k;
        }

        if(count == 0)
            printf("0\n");
        else
            for(int i = 0; i < count; i++) printf(i < count - 1 ? "%d " : "%d\n", seq[i]);
    }

    return 0;
}
