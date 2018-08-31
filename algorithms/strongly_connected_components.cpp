#include <vector>
#include <utility>
#include <algorithm>

int vertex_count;

std::vector<std::vector<std::pair<int, int>>> AdjList; // <- Pair : vertex, edge weight
std::vector<int> dfs_num(vertex_count, -1), dfs_low(vertex_count, 0), S, visited(vertex_count, 0);

int dfsCounter = 0;

SCC(int index)
{
    dfs_low[index] = dfs_num[index] = dfsCounter++;
    S.push_back(index);
    visited[index] = 1;
    for(int j = 0; j < AdjList[index].size(); j++)
    {
        std::pair<int, int> next = AdjList[index][j];
        if(dfs_num[next.first] == -1)
            SCC(next.first);
        if(visited[next.first])
            dfs_low[index] = std::min(dfs_low[index], dfs_low[next.first]);
    }
    if(dfs_low[index] == dfs_num[index])
    {
        while(true)
        {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            // You can print every element of every SCC here by just printing v
            if(v == index)
                break;
        }
    }
}
