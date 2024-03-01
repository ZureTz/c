// Problem Description
// You are given a sequence of N integers between 1 and N (inclusive): A=(A_1,A_2,…,A_N).
// Determine whether A is a permutation of (1,2,…,N).
// Constraints
// 1≤N≤10^3
// 1≤A_i≤N
// All values in input are integers.

// Input
// Input is given from Standard Input in the following format:
// -------------------------------------------------------------
// N
// A_1 A_2 … A_N
// -------------------------------------------------------------

// Output
// If A is a permutation of (1,2,…,N), print Yes; otherwise, print No.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int *status;
    int length, temp;

    scanf("%d", &length);
    status = (int *)malloc(sizeof(int) * length);

    memset(status, 0, sizeof status);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &temp);
        for (int j = 0; j < length; j++)
        {
            if (j + 1 == temp)
            {
                status[j] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (!status[i])
        {
            printf("No");
            break;
        }
        else if (i == length - 1)
        {
            printf("Yes");
        }
    }

    return 0;
}