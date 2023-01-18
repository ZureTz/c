// Problem Statement
// N balls are lined up in a row from left to right. Initially, the i-th (1≤i≤N) ball from the left has an integer i written on it.

// Takahashi has performed Q operations. The i-th (1≤i≤Q) operation was as follows.

// Swap the ball with the integer x_i written on it with the next ball to the right. If the ball with the integer x_i written on it was originally the rightmost ball, swap it with the next ball to the left instead.
// Let a_i be the integer written on the i-th (1≤i≤N) ball after the operations. Find a_1,…,a_N
// Constraints

// 2≤N≤2×10^5
// 1≤Q≤2×10^5
// 1≤x_i≤N
// All values in input are integers.
// Input
// N Q
// x_i
// ⋮
// x_Q

// Output
// Print a_1,…,a_N , with spaces in between.

#include <stdio.h>
#include <stdlib.h>

void swap(int pos1, int pos2, int *array, int *index)
{
    int temp;

    index[array[pos1] - 1]++;
    index[array[pos2] - 1]--;

    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

int main(int argc, char const *argv[])
{
    int n, q, *array, *index;

    scanf("%d %d", &n, &q);
    array = (int *)malloc(sizeof(int) * n);
    index = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
        index[i] = i;
    }
    for (int i = 0, temp; i < q; i++)
    {
        scanf("%d", &temp);

        if (index[temp - 1] != n - 1)
        {
            swap(index[temp - 1], index[temp - 1] + 1, array, index);
        }
        else
        {
            swap(index[temp - 1] - 1, index[temp - 1], array, index);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d", array[n - 1]);

    free(array);

    return 0;
}