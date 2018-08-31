#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

int vertex_count;

std::vector<std::vector<std::pair<int, int>>> AdjList; // <- Pair : vertex, edge weight
std::vector<int> dist(vertex_count, INF), parent(vertex_count, 0);

int source;

void printPath(int dest)
{
    if(dest == source)
    {
        printf("%d\n", source);
        return;
    }
    printPath(parent[dest]);
    printf("%d ", dest);
}

void SSSP(int src, int dest)
{
    source = src;
    std::queue<int> queue;
    queue.push(source);
    dist[source] = 0;
    while(!queue.empty())
    {
        int v = queue.front();
        queue.pop();
        for(int j = 0; j < AdjList[v].size(); j++)
        {
            int next = AdjList[v][j].first;
            if(dist[next] == INF)
            {
                dist[next] = dist[v] + 1;
                parent[next] = v;
                queue.push(next);
            }
        }
    }
    printPath(dest);
}
