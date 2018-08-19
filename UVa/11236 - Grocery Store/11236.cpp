/**
	UVa 11236 - Grocery Store
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.460 C++
*/

#include <stdio.h>

int main(void)
{
    for(int a = 1; a + a + a + a <= 2000; a++)
    for(int b = a; a + b + b + b <= 2000; b++)
    for(int c = b; a + b + c + c <= 2000; c++)
    {
        long long p = (long long) a * b * c;
        long long s = a + b + c;
        if (p <= 1000000) continue;
        if ((s * 1000000) % (p - 1000000)) continue;
        int d = (s * 1000000) / (p - 1000000);
        if (s + d > 2000 || d < c)   continue;
        printf("%.2f %.2f %.2f %.2f\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
    }
    return 0;
}
