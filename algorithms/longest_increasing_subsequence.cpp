#include <algorithm>

int size;

int seq[size];
int lis[size];

int LIS_recursive(int index)
{
    if(index == 0)
        return 1;
    if(lis[index] != -1) return lis[index];
    int max = 0;
    for(int i = 0; i < index; i++)
    {
        current = LIS_recursive(i);
        if(current > max)
            max = current;
    }
    return lis[index] = max + 1;
}

int LIS_iterative()
{
    int len = 0;
    for(int i = 0; i < size; i++)
    {
        index = std::lower_bound(lis, lis + len, seq[i]) - lis;
        lis[index] = seq[i];
        if(index == len)
            len++;
    }
    return len;
}
