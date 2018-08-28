/**
	UVa 11902 - Dominator
	by Lorenzo Leonardini
	Submitted: 2018-08-26
	Accepted 0.050 C++
*/

#include <stdio.h>
#include <vector>
#include <set>
#include <bitset>

std::vector<int> AdjList[110];
std::set<int> reachable;
std::set<int> temp;

std::bitset<110> visited;

int n = -1;

void dfs_check(int index, int ignore)
{
    if(index == ignore) return;
    visited[index] = 1;
    temp.insert(index);
    for(int i = 0; i < AdjList[index].size(); i++)
    {
        int next = AdjList[index][i];
        if(visited[next] == 0)
            dfs_check(next, ignore);
    }
}

void dfs(int index)
{
    visited[index] = 1;
    reachable.insert(index);
    for(int i = 0; i < AdjList[index].size(); i++)
    {
        int next = AdjList[index][i];
        if(visited[next] == 0)
            dfs(next);
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        for(int i = 0; i < n; i++)
            AdjList[i].clear();
        reachable.clear();
        scanf("%d", &n);
        int read;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &read);
            if(read == 1)
                AdjList[i].push_back(j);
        }
        dfs(0);

        printf("Case %d:\n", t);
        for(int i = 0; i < n; i++)
        {
            temp.clear();
            for(int j = 0; j < n; j++)
                visited[j] = 0;
            dfs_check(0, i);
            printf("+");
            for(int k = 0; k < n * 2 - 1; k++) printf("-");
            printf("+\n");
            for(int j = 0; j < n; j++)
            if(reachable.find(j) == reachable.end())
                printf("|N");
            else if(temp.find(j) != temp.end())
                printf("|N");
            else
                printf("|Y");
            printf("|\n");
        }
        printf("+");
        for(int k = 0; k < n * 2 - 1; k++) printf("-");
        printf("+\n");
        for(int j = 0; j < n; j++)
            visited[j] = 0;
    }

    return 0;
}
