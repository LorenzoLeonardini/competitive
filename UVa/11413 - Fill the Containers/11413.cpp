#include <stdio.h>

int vessel[10000];
int n, m;

bool can(int cap)
{
    int c = 1;
    int temp = cap;
    for(int i = 0; i < n; i++)
    {
        if(vessel[i] > cap)
            return false;
        if(vessel[i] > temp)
        {
            if(c == m)
                return false;
            c++;
            temp = cap;
        }
        temp -= vessel[i];
    }
    return true;
}

int main(void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", vessel + i);

        float hi = 1000000000, lo = 1;
        int med;
        int cap = 0;

        while(hi >= lo)
        {
            med = (hi + lo) / 2;
            if(can(med))
            {
                cap = med;
                hi = med - 1;
            }
            else
                lo = med + 1;
        }

        printf("%d\n", cap);
    }

    return 0;
}
