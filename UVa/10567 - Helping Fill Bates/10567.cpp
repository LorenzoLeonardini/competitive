/**
	UVa 10567 - Helping FIll Bates
	by Lorenzo Leonardini
	Submitted: 2018-08-22
	Accepted 0.040 C++
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> ppl[60];
std::vector<char> query;
std::vector<int> match;

int main(void)
{
    char c;
    scanf("%c", &c);
    int index = 0;
    while(c != '\n')
    {
        ppl[c - 'A'].push_back(index++);
        scanf("%c", &c);
    }

    int q;
    scanf("%d", &q);
    std::cin.ignore(100, '\n');
    while(q--)
    {
        query.clear();
        scanf("%c", &c);
        while(c != '\n')
        {
            query.push_back(c);
            scanf("%c", &c);
        }

        match.clear();
        int lastIndex = -1;
        bool possible = true;
        for(int i = 0; i < query.size() && possible; i++)
        {
            auto ind = std::lower_bound(ppl[query[i] - 'A'].begin(), ppl[query[i] - 'A'].end(), lastIndex + 1);
            if(*ind > lastIndex)
            {
                match.push_back(*ind);
                lastIndex = *ind;
            }
            else
                possible = false;
        }
        if(!possible)
            printf("Not matched\n");
        else
        {
            printf("Matched %d %d\n", match[0], match[match.size() - 1]);
        }
    }

    return 0;
}
