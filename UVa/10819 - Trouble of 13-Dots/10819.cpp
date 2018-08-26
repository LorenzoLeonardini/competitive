/**
	UVa 10819 - Trouble of 13-Dots
	by Lorenzo Leonardini
	Submitted: 2018-08-26
	Accepted 0.220 C++
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

int itemCost[110];
char itemValue[110];
int state[110][10010];
int budget, n, temp;

int max = 0;

int val(int id, int remain)
{
    if(remain == 0) return 0;
    if(id == n)
    {
        if(budget <= 1800) return 0;
        if(budget > 2000) return 0;
        if(budget + 200 - remain > 2000) return 0;
        if(remain >= 200) return 0;
        return -1000;
    }
    if(state[id][remain] != -1) return state[id][remain];
    if(itemCost[id] > remain) return state[id][remain] = val(id + 1, remain);
    if(itemCost[id] <= remain) return state[id][remain] = std::max(val(id + 1, remain), itemValue[id] + val(id + 1, remain - itemCost[id]));
    return 0;
}

int main(void)
{
    int t = 0;
    while(scanf("%d %d", &budget, &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d %d", itemCost + i, itemValue + i);

        // if(++t != 146) continue;
        // printf("\t%d %d\n", budget, n);
        // for(int i = 0; i < n; i++)
        //     printf("\t%d %d\n", itemCost[i], itemValue[i]);

        memset(state, -1, sizeof(int) * 110 * 10010);
        int sol;
        if(budget > 1800)
            sol = val(0, budget + 200);
        else
            sol = val(0, budget);
        if(sol < 0) sol += 1000;
        printf("%d\n", sol);
    }

    return 0;
}
// ZenHackCTF{Letters_in_The_Middle_of_words_:)}
