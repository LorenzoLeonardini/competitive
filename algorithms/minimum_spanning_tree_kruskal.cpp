#include <vector>
#include <utility>
#include <algorithm>
#include "union_find.h"

std::vector<std::pair<int, std::pair<int, int>>> EdgeList; // weight, v1, v2

void mst()
{
    std::sort(EdgeList.begin(), EdgeList.end());
    int mst_cost = 0;
    UnionFind UF(V);
    for(int i = 0; i < E; i++)
    {
        std::pair<int, std::pair<int, int>> front = EdgeList[i];
        if(!UF.isSameSet(front.second.first, front.second.second))
        {
            mst_cost += front.first;
            UF.unionSet(front.second.first, front.second.second);
        }
    }
}
