/**
	UVa 10567 - Helping FIll Bates
	by Lorenzo Leonardini
	Submitted: 2018-08-22
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <math.h>

#define EPS 4e-6

int p, q, r, s, t, u;

float solve(float x)
{
    return p * std::pow(M_E, -x) + q * std::sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main(void)
{
    float x;
    float change;
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
    {
        if(solve(0) < 0 || solve(1) > 0)
        {
            printf("No solution\n");
            continue;
        }
        x = 0.5;
        change = 0.25;
        while(true)
        {
            float r = solve(x);
            if(std::abs(r) < EPS) break;
            if(r > 0) x+=change;
            else x-=change;
            change /= 2;
        }
        printf("%.4f\n", x);
    }

    return 0;
}
