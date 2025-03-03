// Problem Statement
// You are given two strings S and T. Determine whether it is possible to make S equal T by performing the following operation some number of times (possibly zero).

// Between two consecutive equal characters in S, insert a character equal to these characters. That is, take the following three steps.

// Let N be the current length of S, and S=S_1S_2…S_N.
// Choose an integer i between 1 and N−1 (inclusive) such that S_i=S_{i+1}. (If there is no such i, do nothing and terminate the operation now, skipping step 3.)
// Insert a single copy of the character S_i(=S_{i+1})between the i-th and (i+1)-th characters of S. Now, S is a string of length N+1: S_1S_2…S_iS_iS_{i+1}…S_NN+1.
// Constraints

// Each of SS and TT is a string of length between 22 and 2×10^5(inclusive) consisting of lowercase English letters.
// Input
// S
// T

// Output
// If it is possible to make S equal T, print Yes; otherwise, print No. Note that the judge is case-sensitive.

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[200001], str2[200001];

    scanf("%s\n%s", str1, str2);
    for (int i = 0; str2[i] != '\0'; i++)
    {
        if (str2[i] == str2[i + 1] && str2[i] == str2[i + 2])
        {
            for (int j = i; str2[j]!='\0'; j++)
            {
                str2[j] = str2[j + 1];
            }
            i--;
        }
    }
    printf("%s", !(strcmp(str1, str2)) ? "Yes" : "No");

    return 0;
}