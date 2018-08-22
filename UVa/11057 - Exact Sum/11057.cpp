/**
	UVa 10567 - Helping FIll Bates
	by Lorenzo Leonardini
	Submitted: 2018-08-22
	Accepted 0.010 C++
*/

#include <stdio.h>
#include <algorithm>

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int books[n];
        for(int i = 0; i < n; i++)
            scanf("%d", books + i);

        std::sort(books, books + n);
        int price;
        scanf("%d", &price);
        int *p1;
        int *p2;
        p1 = std::lower_bound(books, books + n, price / 2);
        while(true)
        {
            p2 = std::lower_bound(p1 + 1, books + n, price - *p1);
            if(*p1 + *p2 == price) break;
            p1--;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", *p1, *p2);
    }

    return 0;
}
