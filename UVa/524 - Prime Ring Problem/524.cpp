/**
	UVa 524 - Prime Ring Problem
	by Lorenzo Leonardini
	Submitted: 2018-08-20
	Accepted 0.120 C++
*/

#include <stdio.h>
#include <bitset>

std::bitset<32> prime;
std::bitset<17> used;

int ring[17] = { 1 };

int n;

void precalculate() // precalculate primes
{
    prime[2] = 1;
    for(int i = 3; i < 32; i++)
    {
        bool p = true;
        for(int j = 2; j < i; j++)
        {
            if(prime[j] == 0) continue;
            if(i % j == 0)
            {
                p = false;
                break;
            }
        }
        if(p)
            prime[i] = 1;
    }
}

void clear()
{
    for(int i = 0; i < 17; i++)
        used[i] = 0;
    used[1] = 1;
}

void calc(int pos)
{
    if(pos == n)
    {
        if(prime[ring[pos - 1] + 1] == 0) return;
        printf("\n1 ");
        for(int i = 1; i < n; i++)
            printf(i < n - 1 ? "%d " : "%d", ring[i]);
        return;
    }
    for(int i = 2; i < 32; i++)
    {
        if(prime[i] == 0) continue;
        int next = i - ring[pos - 1];
        if(next <= 1) continue;
        if(next > n) continue;
        if(used[next] == 1) continue;
        used[next] = 1;
        ring[pos] = next;
        calc(pos + 1);
        used[next] = 0;
    }
}

int main(void)
{
    precalculate();

    int t = 0;
    while(scanf("%d", &n) != EOF)
    {
        if(t > 0)
            printf("\n\n");
        clear();
        printf("Case %d:", ++t);
        calc(1);
    }

    printf("\n");
}
