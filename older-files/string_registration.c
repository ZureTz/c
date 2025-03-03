// Problem Description
// Problem Statement
// Takahashi wants to be a member of some web service.
// He tried to register himself with the ID S, which turned out to be already used by another user.
// Thus, he decides to register using a string obtained by appending one character at the end of S as his ID.
// He is now trying to register with the ID T. Determine whether this string satisfies the property above.

// Constraints
// S and T are strings consisting of lowercase English letters.
// 1⩽∣S∣⩽10
// ∣T∣=∣S∣+1

// Input
// Input is given from Standard Input in the following format:
// S
// T

// Output
// If T satisfies the property in Problem Statement, print Yes; otherwise, print No.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char S[11], T[12];

    scanf("%s\n%s", S, T);
    for (int i = 0; i < strlen(S); i++)
    {
        if (T[i] != S[i])
        {
            printf("No");
            break;
        }
        else if (i == strlen(S) - 1)
        {
            printf("Yes");
        }
    }

    return 0;
}