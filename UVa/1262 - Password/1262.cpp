/**
	UVa 1262 - Password
	by Lorenzo Leonardini
	Submitted: 2018-08-21
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

int k;
std::set<char> common[5];
char grids[2][5][6];
char s[6];

std::vector<std::string> passwords;

void genPW(int index)
{
    if(index == 5)
    {
        std::string str(s);
        passwords.push_back(str);
        return;
    }
    for(std::set<char>::iterator it = common[index].begin(); it != common[index].end(); it++)
    {
        s[index] = *it;
        genPW(index + 1);
    }
}

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        for(int i = 0; i < 5; i++)
            common[i].clear();
        passwords.clear();
        scanf("%d", &k);
        for(int i = 0; i < 2; i++)
        for(int y = 0; y < 6; y++)
        {
            std::cin.ignore(100, '\n');
            for(int x = 0; x < 5; x++)
                scanf("%c", &(grids[i][x][y]));
        }

        for(int x = 0; x < 5; x++)
        for(int y1 = 0; y1 < 6; y1++)
        for(int y2 = 0; y2 < 6; y2++)
            if(grids[0][x][y1] == grids[1][x][y2])
            {
                common[x].insert(grids[0][x][y1]);
                break;
            }

        int max = 1;
        for(int i = 0; i < 5; i++)
            max *= common[i].size();
        if(k > max)
        {
            printf("NO\n");
            continue;
        }

        genPW(0);
        std::sort(passwords.begin(), passwords.end());
        printf("%s\n", passwords[k - 1].c_str());
    }

    return 0;
}
