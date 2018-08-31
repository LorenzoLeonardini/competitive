#pragma once

#include <vector>

class UnionFind
{
private:
    std::vector<int> p, rank;
public:
    UnionFind(int N);
    int findSet(int i);
    bool isSameSet(int i, int j);
    void unionSet(int i, int j);
}
