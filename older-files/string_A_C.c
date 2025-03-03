// Problem Description
// Problem Statement
// AtCoder Inc. holds a contest every Saturday.
// There are two types of contests called ABC and ARC, and just one of them is held at a time.
// The company holds these two types of contests alternately: an ARC follows an ABC and vice versa.
// Given a string SS representing the type of the contest held last week, print the string representing the type of the contest held this week.

// Constraints
// S is ABC or ARC.

// Input
// Input is given from Standard Input in the following format:
// S

// Output
// Print the string representing the type of the contest held this week.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char S[4];

    scanf("%s", S);
    printf("%s", strcmp(S, "ARC") == 0 ? "ABC" : strcmp(S, "ABC") == 0 ? "ARC" : "Undefined");

    return 0;
}