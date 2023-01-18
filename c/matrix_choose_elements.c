#include <stdio.h>
#include <stdlib.h>

void matrix_multiplication_to_mat1(int n, int dest[2 * n][2 * n], int src[2 * n][2 * n])
{
    int result[2 * n][2 * n];

    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            for (int k = 0; k < 2 * n; k++)
            {
                result[i][j] += dest[i][k] * src[k][j];
            }
        }
    }
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            dest[i][j] = result[i][j];
        }
    }
}

int main(int argc, char const *argv[])
{
    int N, K;
    int count = 0;
    scanf("%d %d", &N, &K);
    int arr[2][N], mat[2 * N][2 * N];
    int result[2 * N][2 * N];

    for (int i = 0; i < 2 * N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
        {
            mat[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (abs(arr[j][i] - arr[k][i + 1]) <= K)
                {
                    mat[N * j + i][N * k + (i + 1)] = 1;
                }
            }
        }
    }
    for (int i = 0; i < 2 * N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
        {
            result[i][j] = mat[i][j];
        }
    }
    for (int i = 0; i < N - 2; i++)
    {
        matrix_multiplication_to_mat1(N, result, mat);
    }
    count += result[0][N - 1] + result[0][2 * N - 1] + result[N][N - 1] + result[N][2 * N - 1];
    printf("%s", count > 0 ? "Yes" : "No");

    return 0;
}