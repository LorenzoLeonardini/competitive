/**
	UVa 10976 - Fractions Again?!
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <vector>

int main(void)
{
    int k;
    while(scanf("%d", &k) != EOF)
    {
        std::vector<int> xs, ys;
        for(int y = k + 1; y <= 2 * k; y++)
        {
            int x = (-k * y) / (k - y);
            if((-k * y) % (k - y) == 0)
            {
                ys.push_back(y);
                xs.push_back((int) x);
            }
        }

        printf("%d\n", xs.size());
        for(int i = 0; i < xs.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n", k, xs[i], ys[i]);
    }

    return 0;
}
