/**
	UVa 193 - Graph Coloring
	by Lorenzo Leonardini
	Submitted: 2018-08-21
	Accepted 0.000 C++
*/

#include <stdio.h>

char edges[100][100];
char used[100];
char usedCount;
int best[100];
int max;

int n, k, a, b;

void clear()
{
    for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
        edges[i][j] = 0;
    for(int i = 0; i < 100; i++)
        used[i] = 0;
    for(int i = 0; i < 100; i++)
        best[i] = 0;
    max = 0;
    usedCount = 0;
}

void take(int i)
{
    if(used[i]) return;
    used[i]++;
    usedCount++;
    for(int j = 0; j < n; j++)
        if(edges[i][j] == 1)
            used[j] += 2;
}

void untake(int i)
{
    if(!used[i]) return;
    used[i]--;
    usedCount--;
    for(int j = 0; j < n; j++)
        if(edges[i][j] == 1)
            used[j] -= 2;
}

void solve(int taken, int depth)
{
    bool finished = true;
    for(int i = 0; i < n && finished; i++)
        if(used[i] == 0)
            finished = false;
    if(finished)
    {
        if(usedCount <= max) return;
        max = usedCount;
        a = 0;
        for(int i = 0; i < n; i++)
            if(used[i] % 2 != 0)
                best[a++] = i;
        return;
    }
    for(int i = taken + 1; i < n; i++)
    {
        if(used[i] > 0) continue;
        take(i);
        solve(i, depth + 1);
        untake(i);
    }
}

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        clear();
        scanf("%d %d", &n, &k);
        for(int i = 0; i < k; i++)
        {
            scanf("%d %d", &a, &b);
            edges[a - 1][b - 1] = edges[b - 1][a - 1] = 1;
        }

        solve(-1, 0);
        printf("%d\n", max);
        for(int i = 0; i < max; i++)
            printf(i < max - 1 ? "%d " : "%d\n", best[i] + 1);
    }

    return 0;
}
