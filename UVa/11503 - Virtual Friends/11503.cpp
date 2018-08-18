/**
	UVa 11503 - Virtual Friends
	by Lorenzo Leonardini
	Submitted: 2018-08-18
	Accepted 0.560 C++
*/

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>

class UnionFind
{
private:
    std::vector<int> p, rank, size;
public:
    UnionFind(int n)
    {
        rank.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; i++)
            p[i] = i;
        size.assign(n, 1);
    }

    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    int unionSet(int i, int j)
    {
        if(isSameSet(i, j))
            return size[findSet(i)];
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y])
        {
            p[y] = x;
            size[y] += size[x];
            size[x] = size[y];
            return size[y];
        }
        p[x] = y;
        size[x] += size[y];
        size[y] = size[x];
        if(rank[x] == rank[y])
            rank[y]++;
        return size[x];
    }
};

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int connections;
        scanf("%d", &connections);

        int currentId = 0;
        std::map<std::string, int> id;
        UnionFind web(connections * 2);

        for(int i = 0; i < connections; i++)
        {
            std::string a, b;
            std::cin >> a >> b;
            if(id.find(a) == id.end())
                id[a] = currentId++;
            if(id.find(b) == id.end())
                id[b] = currentId++;

            printf("%d\n", web.unionSet(id[a], id[b]));
        }
    }

    return 0;
}
