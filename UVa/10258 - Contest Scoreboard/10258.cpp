/**
	UVa 10258 - Contest Scoreboard
	by Lorenzo Leonardini
	Submitted: 2018-08-05
	Accepted 0.000 C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>

typedef struct
{
	int id = -1;
	int solvedCount = 0;
	int totalPenalty = 0;
	int solved[10] = { 0 };
	int penalty[10] = { 0 };
} player;

int cmp(const void *a, const void *b)
{
	player A = *(player*)a;
	player B = *(player*)b;

	if(A.solvedCount != B.solvedCount)
		return B.solvedCount - A.solvedCount;

	if(A.totalPenalty != B.totalPenalty)
		return A.totalPenalty - B.totalPenalty;

	return A.id - B.id;
}

int main(void)
{
	int t;
	scanf("%d\n\n", &t);
	while(t--)
	{
		std::string in;
		int pl, pr, ti;
		std::string l;

		std::stringstream ss;

		player players[100];

		while(getline(std::cin, in))
		{
			if(in.empty()) break;
			ss.clear();
			ss << in;
			ss >> pl >> pr >> ti >> l;
			pl--;
			players[pl].id = pl;
			if(l != "C" && l != "I") continue;
			if(players[pl].solved[pr]) continue;
			if(l == "C")
			{
				players[pl].solvedCount++;
				players[pl].solved[pr] = 1;
				players[pl].penalty[pr] += ti;
				continue;
			}
			players[pl].penalty[pr] += 20;
		}

		for(int i = 0; i < 100; i++)
			for(int j = 0; j < 10; j++)
				players[i].totalPenalty += players[i].penalty[j] * players[i].solved[j];

		qsort(players, 100, sizeof(player), cmp);

		for(int i = 0; i < 100; i++)
		{
			if(players[i].id == -1) continue;
			printf("%d %d %d\n", players[i].id + 1, players[i].solvedCount, players[i].totalPenalty);
		}
		if(t > 0) printf("\n");
	}

	return 0;
}
