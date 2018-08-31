#include <vector>
#include <utility>
#include <queue>

int graph_size;

std::vector<std::vector<std::pair<int, int>>> AdjList; // <- Pair : vertex, edge weight
std::vector<int> distance(graph_size, -1);

void bfs(int source)
{
    distance[source] = 0;
    std::queue<int> queue;
    queue.push(source);

    while(!queue.empty())
    {
        int u = queue.front();
        queue.pop();
        for(int i = 0; i < AdjList[u].size(); i++)
        {
            std::pair<int, int> v = AdjList[u][j];
            if(distance[v.first] == -1)
            {
                distance[v.first] = distance[u] + 1;
                queue.push(v.first);
            }
        }
    }
}
