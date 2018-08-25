/**
	UVa 481 - What goes up
	by Lorenzo Leonardini
	Submitted: 2018-08-25
	Accepted 0.020 C++
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

int seq[1000000], lis[100000], lis_id[1000000], p[1000000];

void print(int end)
{
    if(end < 0) return;
    print(p[end]);
    printf("%d\n", seq[end]);
}

int main(void)
{
    int index = 0;
    int l = 0, end = 0;
    for(int i = 0; scanf("%d", seq + i) != EOF; i++)
    {
        int index = std::lower_bound(lis, lis + l, seq[i]) - lis;
        lis[index] = seq[i];
        lis_id[index] = i;
        p[i] = index > 0 ? lis_id[index - 1] : -1;
        if(index == l)
        {
            l++;
            end = i;
        }
    }

    printf("%d\n-\n", l);
    print(end);

    return 0;
}
