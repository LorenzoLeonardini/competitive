#include <vector>
#include <utility>
#include <algorithm>

int vertex_count;

std::vector<std::vector<std::pair<int, int>>> AdjList; // <- Pair : vertex, edge weight
std::vector<int> dist(vertex_count, INF);

int SSSP(int source, int dest)
{
    dist[source] = 0;
    for(int i = 0; i < vertex_count - 1; i++)
    for(int u = 0; u < vertex_count; u++)
    for(int j = 0; j < AdjList[u].size(); j++)
    {
        std::pair<int, int> v = AdjList[u][j];
        dist[v.first] = std::min(dist[v.first], dist[u] + v.second);
    }

    return dist[dest];
}

bool hasNegativeCycles() // to call after SSSP
{
    for(int u = 0; u < vertex_count; u++)
    for(int j = 0; j < AdjList[u].size(); j++)
    {
        std::pair<int, int> v = AdjList[u][j];
        if(dist[v.first] > dist[u] + v.second)
            return true;
    }
    return false;
}
