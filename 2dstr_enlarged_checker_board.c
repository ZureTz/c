// Problem Statement
// Tiles are aligned in N horizontal rows and N vertical columns. Each tile has a grid with A horizontal rows and B vertical columns. On the whole, the tiles form a grid XX with (A×N)(A×N) horizontal rows and (B×N) vertical columns.
// For 1≤i,j≤N, Tile (i,j) denotes the tile at the ii-th row from the top and the j-th column from the left.

// Each square of XX is painted as follows.

// Each tile is either a white tile or a black tile.
// Every square in a white tile is painted white; every square in a black tile is painted black.
// Tile (1,1) is a white tile.
// Two tiles sharing a side have different colors. Here, Tile (a,b) and Tile (c,d) are said to be sharing a side if and only if ∣a−c∣+∣b−d∣=1 (where ∣x∣ denotes the absolute value of x).
// Print the grid XX in the format specified in the Output section.

// Constraints

// 1≤N,A,B≤10
// All values in input are integers.
// Input
// N A B

// Output
// Print (A×N) strings
// S_1,…,S_{A×N} that satisfy the following condition, with newlines in between.

// Each of S_1,…,S_{A×N} is a string of length (B×N) consisting of . and #.
// For each i and j (1≤i≤A×N,1≤j≤B×N), the j-th character of S_i is . if the square at the i-th row from the top and j-th column from the left in grid X is painted white; the character is # if the square is painted black.

#include <stdio.h>

void inchar(int n, int a, int b, int row, int col, char tiles[n * a][n * b], char ch)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            tiles[row * a + i][col * b + j] = ch;
        }
    }
}

int main(void)
{
    int n, a, b;
    int flag = 1;
    scanf("%d %d %d", &n, &a, &b);
    char tiles[n * a][n * b];

    for (int i = 0; i < n; i++, flag *= (n % 2 == 0) ? -1 : 1)
    {
        for (int j = 0; j < n; j++, flag *= -1)
        {
            if (flag == 1)
            {
                inchar(n, a, b, i, j, tiles, '.');
            }
            else
            {
                inchar(n, a, b, i, j, tiles, '#');
            }
        }
    }
    for (int i = 0; i < n * a; i++)
    {
        for (int j = 0; j < n * b; j++)
        {
            putchar(tiles[i][j]);
        }
        putchar('\n');
    }

    return 0;
}