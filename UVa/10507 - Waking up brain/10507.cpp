/**
	UVa 10507 - Waking up brain
	by Lorenzo Leonardini
	Submitted: 2018-08-18
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <iostream>
#include <bitset>

int main(void)
{
    int slept, connections;
    while(1)
    {
        if(scanf("%d %d", &slept, &connections) == EOF) break;
        std::bitset<26 * 26> brain;
        std::bitset<26> awake;

        std::cin.ignore(100, '\n');

        char c;
        while(1)
        {
            scanf("%c", &c);
            if(c < 'A' || c > 'Z')
            {
                if(c != '\n')
                    std::cin.ignore(100, '\n');
                break;
            }
            awake[c - 'A'] = 1;
            slept--;
        }

        char a, b;
        for(int i = 0; i < connections; i++)
        {
            scanf("%c %c", &a, &b);
            a -= 'A';
            b -= 'A';
            brain[a + b * 26] = 1;
            brain[b + a * 26] = 1;
            std::cin.ignore(100, '\n');
        }


        int prevSlept;
        int years = 0;

        while(1)
        {
            if(!slept)
            {
                printf("WAKE UP IN, %d, YEARS\n", years);
                break;
            }
            prevSlept = slept;

            std::bitset<26> newAwake;
            for(int i = 0; i < 26; i++)
            {
                if(awake[i]) continue;
                int neig = 0;
                for(int j = 0; j < 26; j++)
                {
                    if(neig >= 3) break;
                    if(brain[i + j * 26] == 1)
                        if(awake[j] == 1)
                            neig++;
                }
                if(neig >= 3)
                {
                    // printf("\t %c wakes up", 'A' + i);
                    newAwake[i] = 1;
                    slept--;
                }
            }
            for(int i = 0; i < 26; i++)
                if(newAwake[i] == 1)
                    awake[i] = 1;


            if(prevSlept == slept)
            {
                printf("THIS BRAIN NEVER WAKES UP\n");
                break;
            }
            years++;
            // printf("\t new year %d\n", slept);
        }
    }

    return 0;
}
