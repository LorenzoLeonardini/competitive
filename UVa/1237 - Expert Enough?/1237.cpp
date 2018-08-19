/**
	UVa 1237 - Expert Enough?
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.010 C++
*/

#include <stdio.h>

typedef struct
{
    char name[21];
    unsigned int l;
    unsigned int h;
} db_entry;

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int db_size;
        scanf("%d", &db_size);
        db_entry db[db_size];

        for(int i = 0; i < db_size; i++)
            scanf("%s %d %d", (db + i)->name, &(db + i)->l, &(db + i)->h);

        int queries;
        scanf("%d", &queries);

        while(queries--)
        {
            int index = -1;

            int price;
            scanf("%d", &price);

            for(int i = 0; i < db_size; i++)
            {
                if(price < db[i].l || price > db[i].h) continue;
                if(index == -1)
                {
                    index = i;
                    continue;
                }
                index = -1;
                break;
            }

            if(index == -1)
                printf("UNDETERMINED\n");
            else
                printf("%s\n", db[index].name);
        }
        if(t)
            printf("\n");
    }

    return 0;
}
