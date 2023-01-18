// Problem Description
// 编写一个函数 Fun，其的功能是：分别求出数组中所有奇数之和以及所有偶数之和。

// Input
// 有两行。第1行是整数n（0<n≤1000），表示数组中有n个元素。第2行有n个整数。

// Output
// 有两行。第1行是数组中奇数的和，第2行是数组中偶数的和。

#include <stdio.h>
#define N 1000

void Fun(int *p, int n, int *p1, int *p2)
{
    *p1 = *p2 = 0;
    for (int i = 0; i < n; i++)
    {
        *p1 += (p[i] % 2) ? p[i] : 0;
        *p2 += !(p[i] % 2) ? p[i] : 0;
    }
}

int main(int argc, char const *argv[])
{
    int a[N + 5];
    int n, odd, even;
    int *p1 = &odd;
    int *p2 = &even;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    Fun(a, n, p1, p2);
    printf("The sum of odd numbers:%d\n", odd);
    printf("The sum of even numbers:%d\n", even);

    return 0;
}
