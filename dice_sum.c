// Problem Statement
// How many integer sequences of length N, A=(A_1,…,A_N) satisfy all of the conditions below?

// 1≤A_i≤M (1≤i≤N)

// sum(A) <= K

// Since the count can get enormous, find it modulo 998244353.

// Constraints

// 1≤N,M≤50
// N≤K≤NM
// All values in input are integers.
// Input
// N M K

// Output
// Print the answer.

#include <stdio.h>
#define MOD 998244353

int main(int argc, char const *argv[])
{
    int N, M, K;
    int array[51][2501] = {0};
    int ans = 0;

    scanf("%d %d %d", &N, &M, &K);
    array[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < K; j++)
        {
            for (int k = 1; k <= M; k++)
            {
                if (j + k <= K)
                {
                    array[i + 1][j + k] += array[i][j];
                    array[i + 1][j + k] %= MOD;
                }
            }
        }
    }
    for (int i = 0; i <= K; i++)
    {
        ans += array[N][i];
        ans %= MOD;
    }
    printf("%d", ans);

    return 0;
}