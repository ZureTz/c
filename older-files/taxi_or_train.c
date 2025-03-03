#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, A, B;

    scanf("%d %d %d", &N, &A, &B);
    if (N * A <= B)
    {
        printf("%d", N * A);
    }
    else
    {
        printf("%d", B);
    }

    return 0;
}