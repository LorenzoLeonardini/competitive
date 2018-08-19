/**
	UVa 735 - Dart-a-Mania
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.410 C++
*/

#include <stdio.h>
#include <vector>
#include <set>

int main(void)
{
    std::vector<int> points;
    std::set<int> asd;
    for(int i = 0; i <= 20; i++)
    {
        asd.insert(i);
        asd.insert(i * 2);
        asd.insert(i * 3);
    }
    asd.insert(50);
    for(std::set<int>::iterator it = asd.begin(); it != asd.end(); it++)
        points.push_back(*it);

    int score;
    while(scanf("%d", &score) != EOF)
    {
        if(score == 0) break;
        int comb = 0, perm = 0;
        int darts[65][65][65] = { 0 };

        for(int i = 0; i < points.size(); i++)
        for(int j = 0; j < points.size(); j++)
        for(int k = 0; k < points.size(); k++)
        {
            if(points[i] + points[j] + points[k] == score)
            {
                perm++;
                if(!darts[points[i]][points[j]][points[k]])
                {
                    darts[points[i]][points[j]][points[k]] = darts[points[i]][points[k]][points[j]] = 1;
                    darts[points[j]][points[i]][points[k]] = darts[points[j]][points[k]][points[i]] = 1;
                    darts[points[k]][points[i]][points[j]] = darts[points[k]][points[j]][points[i]] = 1;
                    comb++;
                }
            }
        }

        if(perm == 0)
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        else
        {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, comb);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, perm);
        }
        for(int i = 0; i < 70; i++) printf("*");
        printf("\n");
    }

    printf("END OF OUTPUT\n");

    return 0;
}
