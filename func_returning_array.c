#include <stdio.h>
#include <stdlib.h>

int intpow10(int pow)
{
    int result = 1;
    for (int i = 0; i < pow; i++)
    {
        result *= 10;
    }
    return result;
}

int *find_digits(int n)
{
    int *array;
    array = (int *)malloc(sizeof(int) * 3);

    for (int i = 0; i < 3; i++)
    {
        array[i] = (n / intpow10(3 - 1 - i)) % 10;
    }

    return array;
}

int main(int argc, char const *argv[])
{
    for (int i = 100; i < 334; i++)
    {
        int status[9] = {0};
        int *digits_times[3];

        for (int j = 0; j < 3; j++)
        {
            digits_times[j] = find_digits((j + 1) * i);
        }

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                status[digits_times[j][k] - 1] = 1;
            }
        }

        for (int j = 0; j < 9; j++)
        {
            if (status[j] == 0)
            {
                break;
            }
            else if (j == 8)
            {
                printf("%d %d %d", i, 2 * i, 3 * i);
                putchar('\n');
            }
        }

        for (int j = 0; j < 3; j++)
        {
            free(digits_times[j]);
        }
    }

    return 0;
}