#include <vector>
#include <utility>
#include <algorithm>

int vertex_count;

std::vector<std::vector<std::pair<int, int>>> AdjList; // <- Pair : vertex, edge weight
std::vector<int> dfs_num(vertex_count, -1), dfs_low(vertex_count, 0), dfs_parent(vertex_count, 0), articulationPoint(vertex_count, 0);

int dfsCounter = 0;
int rootChildren = 0;
int dfsRoot;

void articulationPointAndBridge(int index)
{
    dfs_low[index] = dfs_num[index] = dfsCounter++;
    for(int j = 0; j < AdjList[index].size(); j++)
    {
        std::pair<int, int> next = AdjList[index][j];
        if(dfs_num[next.first] == -1)
        {
            dfs_parent[next.first] = index;
            if(index == dfsRoot)
                rootChildren++;
            articulationPointAndBridge(next.first);
            if(dfs_low[next.first] >= dfs_num[index])
                articulationPoint[next.first] = 1;// IT'S AN ARTICULATION POINT
            if(dfs_low[next.first] > dfs_num[index])
                printf("BRIDGE!\n");// IT'S A BRIDGE
            dfs_low[index] = std::min(dfs_low[index], dfs_low[next.first]);
        }
        else if(next.first != dfs_parent[index])
            dfs_low[index] = std::min(dfs_low[index], dfs_low[next.first]);
    }
}

void findArticulationPointsAndBridges()
{
    dfsCounter = 0;
    for(int vertex = 0; vertex < vertex_count; vertex++)
    {
        if(dfs_num[vertex] == -1)
        {
            dfsRoot = vertex;
            rootChildren = 0;
            articulationPointAndBridge(vertex);
            // DO WHATEVER YOU WANT WITH THE RESULTS
            // IF rootChildren > 1 THEN ROOT IS AN ARTICULATION POINT
        }
    }
}
