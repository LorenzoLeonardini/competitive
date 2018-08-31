#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

int vertex_count;

std::vector<std::vector<std::pair<int, int>>> AdjList; // <- Pair : vertex, edge weight
std::vector<int> dist(vertex_count, INF);

int dijkstra(int source, int dest)
{
    dist[source] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::pair<int, int>(0, source));
    while(!pq.empty())
    {
        std::pair<int, int> front = pq.top();
        pq.pop();
        int d = front.first;
        int u = front.second;
        if(d > dist[u])
            continue;
        for(int j = 0; j < AdjList[u].size(); j++)
        {
            std::pair<int, int> v = AdjList[u][j];
            if(dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
                pq.push(std::pair<int, int>(dist[v.first], v.first));
            }
        }
    }

    return dist[dest];
}
