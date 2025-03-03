// Problem Statement
// There is a grid with H horizontal rows and W vertical columns, in which two distinct squares have a piece.

// The state of the squares is represented by H strings S_1,…,S_H of length W.
// S_{i,j} = o means that there is a piece in the square at the i-th row from the top and j-th column from the left;
// S_{i,j} = - means that the square does not have a piece. Here, S_{i,j} denotes the j-th character of the string S_i.

// Consider repeatedly moving one of the pieces to one of the four adjacent squares. It is not allowed to move the piece outside the grid. How many moves are required at minimum for the piece to reach the square with the other piece?

// Constraints

// 2≤H,W≤100
// H and W are integers.
// S_i(1≤i≤H) is a string of length W consisting of o and -.
// There exist exactly two pairs of integers 1≤i≤H,1≤j≤W such that S_{i,j} = o.
// Input
// H W
// S_1
// ⋮
// S_H

// Output
// Print the answer.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int h, w, count = 0;
    int pos[2][2];
    char ch;
    scanf("%d %d", &h, &w);
    char array[h][w];

    getchar();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            array[i][j] = (ch = getchar());
            if (ch == 'o')
            {
                pos[count][0] = i;
                pos[count][1] = j;
                count++;
            }
        }
        getchar();
    }
    printf("%d", abs(pos[0][0] - pos[1][0]) + abs(pos[0][1] - pos[1][1]));

    return 0;
}