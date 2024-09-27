// Problem Statement
// Takahashi is participating in a programming contest called AXC002, and he has just submitted his code to Problem A.
// The problem has NN test cases.
// For each test case i (1≤i≤N), you are given a string S_i representing the verdict for that test case. Find the numbers of test cases for which the verdict is AC, WA, TLE, and RE, respectively.
// See the Output section for the output format.

// Constraints
// 1⩽N⩽10^5

// S_i is AC, WA, TLE, or RE.

// Input
// Input is given from Standard Input in the following format:
// N
// S_1
// ⋮
// S_N

// Output
// Let C_0, C_1, C_2, and C_3 be the numbers of test cases for which the verdict is AC, WA, TLE, and RE, respectively. Print the following:
// AC x C_0
// ​WA x C_1
// TLE x C_2
// RE x C_3

#include <stdio.h>
#include <string.h>

#define S0 "AC"
#define S1 "WA"
#define S2 "TLE"
#define S3 "RE"

int main(void)
{
    int strings;
    int c0, c1, c2, c3;
    char str[4];

    c0 = c1 = c2 = c3 = 0;
    scanf("%d", &strings);
    for (int i = 0; i < strings; i++)
    {
        scanf("%s", str);
        c0 += strcmp(str, S0) == 0 ? 1 : 0;
        c1 += strcmp(str, S1) == 0 ? 1 : 0;
        c2 += strcmp(str, S2) == 0 ? 1 : 0;
        c3 += strcmp(str, S3) == 0 ? 1 : 0;
    }
    printf("AC x %d\nWA x %d\nTLE x %d\nRE x %d\n", c0, c1, c2, c3);

    return 0;
}