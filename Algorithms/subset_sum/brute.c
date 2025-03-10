#include <stdio.h>

int subsetSumBrute(int *S, int t, int n)
{
    if (n == 0) return 0;

    if (t < S[n - 1]) {
        return subsetSumBrute(S, t, n - 1);
    } else if (t == S[n - 1]) {
        return 1 + subsetSumBrute(S, t, n - 1);
    } else {
        return subsetSumBrute(S, t, n - 1) + subsetSumBrute(S, t - S[n - 1], n - 1);
    }
}