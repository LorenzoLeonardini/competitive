#include <vector>
#include <utility>

std::vector<std::vector<std::pair<int, int>>> AdjList; // <- Pair : vertex, edge weight
std::vector<bool> visited;

void dfs(int index)
{
    visited[index] = true;
    for(int j = 0; j < AdjList[index].size(); j++)
    {
        std::pair<int, int> next = AdjList[index][j];
        if(!visited[next.first])
            dfs(next.first);
    }
}
