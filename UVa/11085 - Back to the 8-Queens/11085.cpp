/**
	UVa 11085 - Back to the 8-Queens
	by Lorenzo Leonardini
	Submitted: 2018-08-20
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <vector>
#include <math.h>

typedef struct
{
    int r[8];
} check;

std::vector<check> checks;
int row[8];
int a, b;

bool place(int r, int c)
{
    if(c + r * 8 < b + a * 8) return false; // Controls if you are not repeating by checking if you already manually put a queen there
    for(int prev = 0; prev < c; prev++)
        if(row[prev] == r || (std::abs(row[prev] - r) == std::abs(prev - c)))
            return false;
    return true;
}

void backtrack(int c)
{
    if (c == 8 && row[b] == a)
    {
        check c;
        for(int i = 0; i < 8; i++)
            c.r[i] = row[i];
        checks.push_back(c);
    }
    for(int r = 0; r < 8; r++)
        if(place(r, c))
        {
            row[c] = r;
            backtrack(c + 1);
        }
}

void precalculate() // Placing a queen in each of the 64 positions, how many combinations are there
{
    for(a = 0; a < 8; a++)
    for(b = 0; b < 8; b++)
    backtrack(0);
}

int leastMoves() // Just keeps track of the least amount of moves you have to do
{
    int min = 8;

    for(std::vector<check>::iterator it = checks.begin(); it != checks.end(); it++)
    {
        int n = 0;
        for(int i = 0; i < 8; i++)
        {
            if(row[i] - 1 == (*it).r[i]) continue;
            n++;
            if(n >= min) break;
        }
        if(n < min)
            min = n;
    }
    return min;
}

int main(void)
{
    precalculate(); // Precalculate all the possible queen positions

    int t = 0;
    while(scanf("%d %d %d %d %d %d %d %d", row, row + 1, row + 2, row + 3, row + 4, row + 5, row + 6, row + 7) != EOF)
        printf("Case %d: %d\n", ++t, leastMoves()); // Calc :)
}
