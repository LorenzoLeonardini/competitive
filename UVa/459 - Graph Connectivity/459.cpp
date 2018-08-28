/**
	UVa 459 - Graph Connectivity
	by Lorenzo Leonardini
	Submitted: 2018-08-27
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

int n;
std::vector<int> AdjList[30];
bool visited[30];

void dfs(int index)
{
    visited[index] = true;
    for(int i = 0; i < AdjList[index].size(); i++)
        if(!visited[AdjList[index][i]])
            dfs(AdjList[index][i]);
}

int main(void)
{
    int t;
    scanf("%d", &t);

    std::cin.ignore(100, '\n');
    std::cin.ignore(100, '\n');
    while(t--)
    {
        char a, b;

        for(int i = 0; i < 30; i++)
            AdjList[i].clear();

        scanf("%c", &a);
        std::cin.ignore(100, '\n');
        n = a - 'A' + 1;
        while(1)
        {
            if(scanf("%c", &a) == EOF) break;
            if(a == '\n') break;
            scanf("%c", &b);
            std::cin.ignore(100, '\n');
            int A = a - 'A';
            int B = b - 'A';
            AdjList[A].push_back(B);
            AdjList[B].push_back(A);
        }

        memset(visited, false, sizeof(bool) * 30);

        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited[i]) continue;
            count++;
            dfs(i);
        }

        printf("%d\n", count);
        if(t)
            printf("\n");
    }

    return 0;
}
