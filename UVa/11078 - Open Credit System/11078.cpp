/**
	UVa 11078 - Open Credit System
	by Lorenzo Leonardini
	Submitted: 2018-08-19
	Accepted 0.040 C++
*/

#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int students;
        scanf("%d", &students);

        int values[students];
        for(int i = 0; i < students; i++)
            scanf("%d", values + i);

        int max = -1000000, max_diff = -1000000;

        for(int i = 0; i < students - 1; i++)
        {
            if(values[i] > max)
                max = values[i];
            if(max - values[i + 1] > max_diff)
                max_diff = max - values[i + 1];
        }

        printf("%d\n", max_diff);
    }

    return 0;
}
