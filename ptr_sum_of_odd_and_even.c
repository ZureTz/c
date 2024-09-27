/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#define N 1000

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void Fun(int *array, int length, int *odd_sum, int *even_sum)
{
    *odd_sum = *even_sum = 0;

    for (int i = 0; i < length; i++)
    {
        *odd_sum += (array[i] % 2) * array[i];
        *even_sum += !(array[i] % 2) * array[i];
    }
}

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main(int argc, char const *argv[])
{
    int a[N + 5], i, n, odd, even, *p1, *p2;
    p1 = &odd;
    p2 = &even;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    Fun(a, n, p1, p2);
    printf("The sum of odd numbers:%d\n", odd);
    printf("The sum of even numbers:%d\n", even);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */