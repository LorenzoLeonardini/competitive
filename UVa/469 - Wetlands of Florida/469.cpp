/**
	UVa 469 - Wetlands of Florida
	by Lorenzo Leonardini
	Submitted: 2018-08-27
	Accepted 0.050 C++
*/

#include <stdio.h>
#include <iostream>
#include <string.h>

char land[100][100];
int w, h;

int movx[8] = { 1, 1, 0, -1, -1, -1,  0,  1};
int movy[8] = { 0, 1, 1,  1,  0, -1, -1, -1};

int color(int x, int y, char original, char replace)
{
    if(x < 0 || x >= w || y < 0 || y >= h) return 0;
    if(land[x][y] != original) return 0;
    int ans = 1;
    land[x][y] = replace;
    for(int i = 0; i < 8; i++)
        ans += color(x + movx[i], y + movy[i], original, replace);
    return ans;
}

int main(void)
{
    int t;
    scanf("%d", &t);

    std::cin.ignore(100, '\n');
    std::cin.ignore(100, '\n');

    while(t--)
    {
        std::string row;
        w = -1;
        h = 0;
        do
        {
            std::getline(std::cin, row);
            if(w == -1)
                w = row.size();
            for(int i = 0; i < w; i++)
                land[i][h] = row[i];
            h++;
        }
        while(row[0] == 'L' || row[0] == 'W');

        h--;
        int a, b;
        do
        {
            sscanf(row.c_str(), "%d %d", &b, &a);
            a--;
            b--;
            for(int i = 0; i < w; i++)
            for(int j = 0; j < h; j++)
                if(land[i][j] == '.') land[i][j] = 'W';
            int ans = color(a, b, 'W', '.');
            printf("%d\n", ans);
            std::getline(std::cin, row);
        }
        while(row[0] != '\0');

        if(t) printf("\n");
    }

    return 0;
}
