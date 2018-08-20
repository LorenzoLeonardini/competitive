/**
	UVa 624 - CD
	by Lorenzo Leonardini
	Submitted: 2018-08-20
	Accepted 0.000 C++
*/

#include <stdio.h>

int n;
int t;
int tracks[20];

int max;
int sol;

void track(int size, int used, int i)
{
    if(size > n) return;
    if(size > max)
    {
        max = size;
        sol = used;
    }
    if(i >= t) return;

    track(size + tracks[i], used | (1 << i), i + 1);
    track(size, used, i + 1);
}

int main(void)
{
    while(scanf("%d %d", &n, &t) != EOF)
    {
        for(int i = 0; i < t; i++)
            scanf("%d", tracks + i);

        max = sol = 0;
        track(0, 0, 0);

        for(int i = 0; i < t; i++)
            if((sol >> i) & 1 == 1)
                printf("%d ", tracks[i]);
        printf("sum:%d\n", max);
    }

    return 0;
}
