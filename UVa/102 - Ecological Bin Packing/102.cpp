/**
	UVa 102 - Ecological Bin Packaging
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.010 C++
*/

#include <stdio.h>
#include <algorithm>

// Yeah... I over-complicated everything...

int main(void)
{
    int bottles[9];
    while(scanf("%d %d %d %d %d %d %d %d %d", bottles, bottles + 1, bottles + 2, bottles + 3, bottles + 4, bottles + 5, bottles + 6, bottles + 7, bottles + 8) != EOF)
    {
        char better[4] = "BCG";
        char def[4] = "asd";
        int min = -1;

        int moves;
        int indexes[3];
        do
        {
                 if(better[0] == 'B') indexes[0] = 0;
            else if(better[1] == 'B') indexes[0] = 1;
            else if(better[2] == 'B') indexes[0] = 2;
                 if(better[0] == 'G') indexes[1] = 0;
            else if(better[1] == 'G') indexes[1] = 1;
            else if(better[2] == 'G') indexes[1] = 2;
                 if(better[0] == 'C') indexes[2] = 0;
            else if(better[1] == 'C') indexes[2] = 1;
            else if(better[2] == 'C') indexes[2] = 2;

            moves = 0;

            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(indexes[i] == j) continue;
                    moves += bottles[i + j * 3];
                }
            }

            if(moves < min || min == -1)
            {
                min = moves;
                def[0] = better[0];
                def[1] = better[1];
                def[2] = better[2];
            }
        }
        while(std::next_permutation(better, better + 3));

        printf("%s %d\n", def, min);
    }
}
