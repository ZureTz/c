// Problem Statement
// We define sequences S_n as follows.

// S_1 is a sequence of length 1 containing a single 1.
// S_n (n is an integer greater than or equal to 2) is a sequence obtained by concatenating S_{n-1}, n, S_{n-1}in this order.
// For example, S_2 and S_3 is defined as follows.

// S_2 is a concatenation of S_1,2, and S_1, in this order, so it is 1,2,1
// S_3S is a concatenation of S_2, 3 and S_2 , in this order, so it is 1,2,1,3,1,2,1
// Given N, print the entire sequence S_N

// Constraints

// N is an integer.
// 1≤N≤16

// Input
// NN

// Output
// Print S_N, with spaces in between.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sequence(int n)
{
    char *str, *temp;
    int length;
    str = (char *)malloc(sizeof(char) * 10000000);

    if (n == 1)
    {
        strcpy(str, "1");
        return str;
    }

    temp = sequence(n - 1);
    length = strlen(temp);
    strcpy(str, temp);
    strcat(str, " ");
    if (1 < n && n < 10)
    {
        str[length + 1] = '0' + n;
        str[length + 2] = '\0';
    }
    else if (n >= 10)
    {
        str[length + 1] = '1';
        str[length + 2] = '0' + (n % 10);
        str[length + 3] = '\0';
    }
    strcat(str, " ");
    strcat(str, temp);

    return str;
}

int main(int argc, char const *argv[])
{
    int N;

    scanf("%d", &N);
    printf("%s", sequence(N));

    return 0;
}