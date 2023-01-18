/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int intPow10(int n)
{
    int result = 1;

    for (int i = 0; i < n; i++)
    {
        result *= 10;
    }

    return result;
}

void Fun(int a, int b, int *merged)
{
    int a_digit[2], b_digit[2];

    for (int i = 0; i < 2; i++)
    {
        a_digit[i] = (a / intPow10(2 - (i + 1))) % 10;
        b_digit[i] = (b / intPow10(2 - (i + 1))) % 10;
    }

    *merged = a_digit[1] * 1000 + b_digit[1] * 100 + a_digit[0] * 10 + b_digit[0];
}

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main(int argc, char const *argv[])
{
    int a, b, c, *pc;
    pc = &c;
    scanf("%d,%d", &a, &b);
    Fun(a, b, pc);
    printf("%d\n", c);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */