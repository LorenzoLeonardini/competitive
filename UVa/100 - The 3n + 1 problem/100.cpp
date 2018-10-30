#include <stdio.h>

int main(void) {
    int i, j;
    while(scanf("%lld %lld", &i, &j) != EOF) {
        long long int max = 0;
        int l = i < j ? i : j;
        int h = j > i ? j : i;
        for(int k = l; k <= h; k++) {
            int q = k;
            int c = 1;
            while(q != 1) {
                c++;
                if(q % 2 == 0)
                    q /= 2;
                else
                    q = q * 3 + 1;
            }
            if(c > max)
                max = c;
        }
        printf("%d %d %lld\n", i, j, max);
    }
}
