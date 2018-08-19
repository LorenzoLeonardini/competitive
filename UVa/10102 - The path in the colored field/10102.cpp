/**
	UVa 10102 - The path in the colored field
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.030 C++
*/

#include <stdio.h>
#include <math.h>
#include <iostream>

int main(void)
{
    int m;
    while(scanf("%d", &m) != EOF)
    {
        std::cin.ignore(100, '\n');
        char field[m][m];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++)
                scanf("%c", &field[j][i]);
            std::cin.ignore(100, '\n');
        }

        int max = 0;

        for(int x = 0; x < m; x++)
            for(int y = 0; y < m; y++)
            {
                if(field[x][y] != '1') continue;
                int min = m * 2;
                for(int xx = 0; xx < m; xx++)
                    for(int yy = 0; yy < m; yy++)
                    {
                        if(field[xx][yy] != '3') continue;
                        int dist = abs(x - xx) + abs(y - yy);
                        if(dist < min)
                            min = dist;
                    }
                if (min > max)
                    max = min;
            }

        printf("%d\n", max);
    }

    return 0;
}
