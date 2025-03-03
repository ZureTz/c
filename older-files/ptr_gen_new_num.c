#include <stdio.h>
#include <stdlib.h>

int Pow_10(int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= 10;
    }
    return result;
}

int *find_A_digit(int n, int digits)
{
    int *digit;
    digit = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < digits; i++)
    {
        digit[i] = (n / Pow_10(digits - i - 1)) % 10;
    }
    return digit;
}

int findigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

void Fun(int *n)
{
    int digits = findigits(*n);
    int *digit = find_A_digit(*n, digits);

    *n = 0;
    for (int i = digits - 1, j = 1; i > -1; i--)
    {
        if (digit[i] % 2)
        {
            *n += digit[i] * j;
            j *= 10;
        }
    }
    free(digit);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    Fun(&n);
    printf("%d\n", n);
    return 0;
}