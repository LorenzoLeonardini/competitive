/**
	UVa 574 - Sum It Up
	by Lorenzo Leonardini
	Submitted: 2018-08-20
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

int n, t;
std::map<int, int> list;

std::vector<std::vector<int>> sums;
std::vector<int> sum;

void generate(int s)
{
    if(s > t) return;
    if(s == t)
    {
        std::vector<int> v = sum;
        sums.push_back(v);
    }
    for(std::map<int, int>::iterator it = list.begin(); it != list.end(); it++)
    {
        if(!it->second) continue;
        if(s && it->first > sum.back()) continue;
        sum.push_back(it->first);
        it->second--;
        generate(s + it->first);
        it->second++;
        sum.pop_back();
    }
}

int main(void)
{
    while(scanf("%d %d", &t, &n))
    {
        if(n == 0) break;

        list.clear();
        sums.clear();
        sum.clear();
        int k;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &k);
            if(list.find(k) == list.end())
                list[k] = 0;
            list[k]++;
        }

        generate(0);
        printf("Sums of %d:\n", t);
        if(sums.size())
        {
            for(int i = sums.size() - 1; i >= 0; i--)
            for(int j = 0; j < sums[i].size(); j++)
                printf(j < sums[i].size() - 1 ? "%d+" : "%d\n", sums[i][j]);
        }
        else
            printf("NONE\n");
    }
}
