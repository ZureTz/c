#include <stdio.h>

int recursion(int n)
{
    return n < 3 ? 1 : recursion(n - 1) + recursion(n - 2);
}

int main(void)
{
    int num;

    scanf("%d", &num);
    printf("%d", recursion(num));

    return 0;
}