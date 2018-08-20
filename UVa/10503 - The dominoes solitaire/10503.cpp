/**
	UVa 10503 - The dominoes solitaire
	by Lorenzo Leonardini
	Submitted: 2018-08-20
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <bitset>
#include <vector>

typedef struct
{
    int a, b;
} piece;

int n, m, start, end, temp;
std::bitset<15> used;
std::vector<piece> pieces;
int sol = false;

void clear()
{
    sol = false;
    pieces.clear();
    for(int i = 0; i < 15; i++)
        used[i] = 0;
}

void solve(int pos, int next)
{
    if(sol) return;
    if(pos == n)
    {
        if(next == end) sol = true;
        return;
    }

    for(int i = 0; i < pieces.size(); i++)
    {
        if(used[i] == 1) continue;
        if(pieces[i].a == next)
        {
            used[i] = 1;
            solve(pos + 1, pieces[i].b);
            used[i] = 0;
        }
        if(pieces[i].b == next)
        {
            used[i] = 1;
            solve(pos + 1, pieces[i].a);
            used[i] = 0;
        }
    }
}

int main(void)
{
    while(scanf("%d", &n))
    {
        if(!n) break;
        scanf("%d", &m);
        scanf("%d %d", &temp, &start);
        scanf("%d %d", &end, &temp);
        clear();
        for(int i = 0; i < m; i++)
        {
            piece p;
            scanf("%d %d", &p.a, &p.b);
            pieces.push_back(p);
        }

        solve(1, start);
        printf(sol ? "YES\n" : "NO\n");
    }

    return 0;
}
