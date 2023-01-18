#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int intPow10(int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= 10;
    }
    return result;
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

int *find_every_digits(int digits, int n)
{
    int *array;
    array = (int *)malloc(sizeof(int) * digits);

    for (int i = 0; i < digits; i++)
    {
        array[i] = (n / intPow10(digits - 1 - i)) % 10;
    }

    return array;
}

bool isPalindrome(int digits, int *array)
{
    for (int i = 0; i < digits / 2; i++)
    {
        if (array[i] != array[digits - 1 - i])
        {
            break;
        }
        else if (i == digits / 2 - 1)
        {
            free(array);
            return true;
        }
    }
    free(array);
    return false;
}

int main(int argc, char const *argv[])
{
    int n, digits;

    scanf("%d", &n);
    while (n % 10 == 0 && n > 0)
    {
        n /= 10;
    }
    digits = findigits(n);
    printf("%s", ((0 <= n && n < 10) || isPalindrome(digits, find_every_digits(digits, n))) ? "Yes" : "No");

    return 0;
}