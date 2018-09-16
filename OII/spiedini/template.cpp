#include <string.h>
#include <algorithm>
#include <stdio.h>

int solve(int *S, int start, int end, int val, int k)
{
    if(end < 0) return 0;
    if(start > end) return 0;
    if(start == end) return 0;
    if(val > k) return 0;
    if(S[start] == 0)
        return 1 + solve(S, start + 1, end, val, k);
    if(S[end] == 0)
        return 1 + solve(S, start, end - 1, val, k);
    return std::max(solve(S, start + 1, end, val + S[start], k), solve(S, start, end - 1, val + S[end], k));
}



int solve(int N, int K, int* S)
{
    return solve(S, 0, N - 1, 0, K);
}
