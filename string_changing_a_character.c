// Problem Description
// Problem Statement
// You are given a string S of length N consisting of A, B and C, and an integer K which is between 1 and N (inclusive). Print the string S after lowercasing the K-th character in it.

// 给你一个长度为N的字符串S，由A、B和C组成，以及一个介于1和N（包括）之间的整数K。将字符串S中的第K个字符小写后打印出来。

// Input
// Input is given from Standard Input in the following format:
// N K
// S

// Constraints
// 1⩽N⩽50
// 1⩽K⩽N
// S is a string of length N consisting of A, B and C.
// S 是一个长度为NN的字符串，由AA、BB和CC组成。

// Output
// Print the string S after lowercasing the K-th character in it.

// 将字符串S中的第K个字符小写后打印出来。

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int length, pos;
    char str[51];

    scanf("%d %d", &length, &pos);
    scanf("%s", str);
    str[pos - 1] = tolower(str[pos - 1]);
    printf("%s", str);

    return 0;
}