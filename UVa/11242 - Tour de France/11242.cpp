/**
	UVa 11242 - Tour de France
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <algorithm>

int main(void)
{
    int f, r;

    while(scanf("%d %d", &f, &r) == 2)
    {
        float ratios[r * f];
        int front[f];
        int rear[r];

        for(int i = 0; i < f; i++)
            scanf("%d", front + i);
        for(int i = 0; i < r; i++)
            scanf("%d", rear + i);

        float max = 0;

        for(int i = 0; i < f; i++)
            for(int j = 0; j < r; j++)
                ratios[i + j * f] = (float) rear[j] / (float) front[i];

        std::sort(ratios, ratios + f * r);

        for(int k = 0; k < f * r - 1; k++)
            if(ratios[k + 1] / ratios[k] > max)
                max = ratios[k + 1] / ratios[k];

        printf("%0.2f\n", max);
    }

    return 0;
}
