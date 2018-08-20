/**
	UVa 11553 - Grid Game
	by Lorenzo Leonardini
	Submitted: 2018-08-20
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <algorithm>

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);
        int m[n][n];
        int perm[n];

        for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            scanf("%d", &(m[x][y]));

        for(int i = 0; i < n; i++)
            perm[i] = i;

        int max = 8001;
        do
        {
            int amount = 0;
            for(int i = 0; i < n; i++)
                amount += m[i][perm[i]];

            if(amount < max) // Since Bob plays optimally, the largest amount that Alice can win is actually the smallest one
                max = amount;
        }
        while(std::next_permutation(perm, perm + n));

        printf("%d\n", max);
    }

    return 0;
}
