#include <stdio.h>

void Fun(const int num, int *factors, int *num_of_factors)
{
    factors[0] = 1;
    for (int i = 2, j = 1; i <= num; i++)
    {
        if (num % i == 0 && i % 2)
        {
            factors[j] = i;
            *num_of_factors = ++j;
        }
    }
}

int main(int argc, char const *argv[])
{
    int x, factors[1000], num_of_factors;

    scanf("%d", &x);
    Fun(x, factors, &num_of_factors);

    for (int i = 0; i < num_of_factors; i++)
    {
        printf(" %d", factors[i]);
    }
    putchar('\n');

    return 0;
}