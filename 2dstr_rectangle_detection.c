// Problem Description
// Problem Statement
// Takahashi generated 10 strings S_1,S_2,…,S_{10} as follows.

// First, let S_i (1≤i≤10)= .......... (10 .s in a row).
// Next, choose four integers A, B, C and D satisfying all of the following.
// 1≤A≤B≤10.
// 1≤C≤D≤10.
// Then, for every pair of integers (i,j) satisfying all of the following, replace the j-th character of S_i with #.
// A≤i≤B.
// C≤j≤D.
// You are given S_1,S_2,…,S_{10} generated as above. Find the integers A, B, C and D Takahashi chose.
// It can be proved that such integers A, B, C and D uniquely exist (there is just one answer) under the Constraints.

// Constraints

// S_1,S_2,…,S_{10} are strings, each of length 10, that can be generated according to the Problem Statement.
// Input
// S_1
// S_2
// ⋮
// S_{10}​

// Output
// A B
// C D

#include <stdio.h>

int main(void)
{
    char str[10][11];
    int A, B, C, D;

    A = C = 10;
    B = D = 1;
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", str[i]);
        for (int j = 0; j < 10; j++)
        {
            C = ((str[i][j] == '#') && (j + 1 < C)) ? j + 1 : C;
            D = ((str[i][j] == '#') && (j + 1 > D)) ? j + 1 : D;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        A = ((str[i][C - 1] == '#') && (i + 1 < A)) ? i + 1 : A;
        B = ((str[i][C - 1] == '#') && (i + 1 > B)) ? i + 1 : B;
    }
    printf("%d %d\n%d %d", A, B, C, D);

    return 0;
}