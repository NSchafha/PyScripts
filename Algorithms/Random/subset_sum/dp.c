#include <stdio.h>

int subsetSumDP(int *S, int t, int n)
{
    int T[n + 1][t + 1];

    for (int j = 1; j <= t; j++)
        T[0][j] = 0;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= t; j++) 
        {
            if (j < S[i - 1]) T[i][j] = T[i - 1][j];
            else if (j == S[i - 1]) T[i][j] = 1 + T[i - 1][j];
            else T[i][j] = T[i - 1][j] + T[i - 1][j - S[i - 1]];
        }
    }
    return T[n][t];
}
