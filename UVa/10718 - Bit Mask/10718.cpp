/**
	UVa 10718 - Bit Mask
	by Lorenzo Leonardini
	Submitted: 2018-08-23
	Accepted 0.000 C++
*/

#include <stdio.h>

int main(void)
{
    unsigned int n, l, u;
    while(scanf("%u %u %u", &n, &l, &u) != EOF)
    {
        unsigned int m = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(m + (1 << i) - 1 < l && m + (1 << i) <= u)
                m += 1 << i;
            else if(!((n >> i) & 1) && m + (1 << i) <= u)
                m += 1 << i;
        }
        printf("%u\n", m);
    }

    return 0;
}
