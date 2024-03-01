#include <stdio.h>

void Fun(const int num, double *sum)
{
    *sum = 0.0;
    for (int i = 1; i < num + 1; i++)
    {
        *sum += (!(i % 5) || !(i % 9)) ? 1.0 / (double)i : 0.0;
    }
}

int main(int argc, char const *argv[])
{
    int num;
    double recip_sum;

    scanf("%d", &num);
    Fun(num, &recip_sum);
    printf("%lf\n", recip_sum);

    return 0;
}