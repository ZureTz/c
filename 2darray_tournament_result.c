// Problem Statement
// N players played a round-robin tournament.

// You are given an N-by-N table A containing the results of the matches. Let A_{i,j} denote the element at the i-th row and j-th column of A.
// A_{i,j} is - if i=j, and W, L, or D otherwise.
// A_{i,j} is W if Player i beat Player j, L if Player i lost to Player j, and D if Player i drew with Player j.

// Determine whether the given table is contradictory.

// The table is said to be contradictory when some of the following holds:

// There is a pair (i,j) such that Player i beat Player j, but Player j did not lose to Player i;
// There is a pair (i,j) such that Player i lost to Player j, but Player j did not beat Player i;
// There is a pair (i,j) such that Player i drew with Player j, but Player j did not draw with Player i.
// Constraints

// 2≤N≤1000
// A_{i,i}is -.
// A_{i,j} is W, L, or D, for i != j

// Input
// N
// A_{1,1} A_{1,2} ... A_{1,N}
// A_{2,1} A_{2,2} ... A_{2,N}
// ⋮
// A_{N,1} A_{N,2} ... A_{N,N}

// Output
// If the given table is not contradictory, print correct; if it is contradictory, print incorrect.

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n;
    bool stop = false;
    scanf("%d", &n);
    char array[n][n + 1];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", array[i]);
    }
    for (int i = 1; i < n && !stop; i++)
    {
        for (int j = 0; j < i && !stop; j++)
        {
            if 
            (
                ! ((array[i][j] == 'W' && array[j][i] == 'L') 
                || (array[i][j] == 'L' && array[j][i] == 'W') 
                || (array[i][j] == 'D' && array[j][i] == 'D'))
            )
            {
                printf("incorrect");
                stop = true;
            }
            else if (i == n - 1 && j == n - 2)
            {
                printf("correct");
            }
        }
    }

    return 0;
}