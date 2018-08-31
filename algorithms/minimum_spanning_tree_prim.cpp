#include <vector>
#include <utility>
#include <queue>

std::vector<std::vector<std::pair<int, int>>> AdjList; // <- Pair : vertex, edge weight

std::vector<int> taken;
std::priority_queue<std::pair<int, int>> pq;

void process(int vertex)
{
    taken[vertex] = 1;
    for(int j = 0; j < AdjList[vertex].size(); j++)
    {
        std::pair<int, int> next = AdjList[vertex][j];
        if(!taken[next.first])
            pq.push(std::pair<int, int>(-next.second, -next.first));
    }
}

void mst()
{
    process(0);
    int mst_cost = 0;
    while(!pq.empty())
    {
        std::pair<int, int> front = pq.top();
        pq.pop();
        int u = -front.second;
        int w = -front.first;
        if(!taken[u])
        {
            mst_cost += w;
            process(u);
        }
    }
}
