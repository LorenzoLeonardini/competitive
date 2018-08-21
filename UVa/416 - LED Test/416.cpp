/**
	UVa 416 - LED Test
	by Lorenzo Leonardini
	Submitted: 2018-08-21
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <iostream>

char numbers[10] = { 63, 6, 91, 79, 102, 109, 125, 7, 127, 111 };
bool match;

int n;
int value[11];
char a;

void solve(int index, int current, int burnt)
{
    if(index == n) match = true;
    else if(!(value[index] & burnt))
        if(((numbers[current] ^ value[index]) & value[index]) == 0)
            solve(index + 1, current - 1, (numbers[current] ^ value[index]) | burnt);
}

int main(void)
{
    while(1)
    {
        scanf("%d", &n);
        if(!n) break;

        for(int j = 0; j < n; j++)
        {
            std::cin.ignore(100, '\n');
            value[j] = 0;
            for(int i = 0; i < 7; i++)
            {
                scanf("%c", &a);
                if(a == 'Y')
                    value[j] |= (1 << i);
            }
        }
        match = false;
        for(int i = 9; i >= n - 1 && !match; i--)
            solve(0, i, 0);
        printf(match ? "MATCH\n" : "MISMATCH\n");
    }

    return 0;
}
