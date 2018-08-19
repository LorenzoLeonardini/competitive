/**
	UVa 256 - Quirksome Squares
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.780 C++
*/

#include <stdio.h>

typedef unsigned long long int uli;

int main(void)
{
    int digits;
    while(scanf("%d", &digits) != EOF)
    {
        uli max = 1;
        uli half = 1;
        for(int i = 0; i < digits; i++) max *= 10;
        for(int i = 0; i < digits / 2; i++) half *= 10;

        int a, b;
        char *out;
        if(digits == 2) out = "%02d\n";
        else if(digits == 4) out = "%04d\n";
        else if(digits == 6) out = "%06d\n";
        else if(digits == 8) out = "%08d\n";

        for(uli i = 0; i < max; i++)
        {
            a = i / half;
            b = i % half;
            if((a + b) * (a + b) == i)
                printf(out, i);
        }
    }

    return 0;
}
