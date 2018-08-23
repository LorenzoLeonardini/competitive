/**
	UVa 12210 - A Match Making Problem
	by Lorenzo Leonardini
	Submitted: 2018-08-23
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <algorithm>
#include <functional>
#include <math.h>

int main(void)
{
    int b, s;
    int t = 0;
    while(1)
    {
        scanf("%d %d", &b, &s);
        if(b == 0 && s == 0) break;
        int bachelor[b];
        int spinster[s];
        bool taken[s] = { 0 };

        for(int i = 0; i < b; i++) scanf("%d", bachelor + i);
        for(int i = 0; i < s; i++) scanf("%d", spinster + i);

        std::sort(bachelor, bachelor + b, std::greater<int>());
        std::sort(spinster, spinster + s, std::greater<int>());

        for(int i = b - 1; i >= 0; i--)
        {
            int diff = 100;
            int j = s - 1;
            while(1)
            {
                if(j < 0) break;
                if(!taken[j])
                {
                    if(std::abs(spinster[j] - bachelor[i]) < diff)
                        diff = std::abs(spinster[j] - bachelor[i]);
                    else
                        taken[j] = true;
                        {
                        break;
                    }
                }
                j--;
            }
            if(j < 0) break;
        }

        if(s - b >= 0)
            printf("Case %d: 0\n", ++t);
        else
            printf("Case %d: %d %d\n", ++t, b - s, bachelor[b - 1]);
    }

    return 0;
}
