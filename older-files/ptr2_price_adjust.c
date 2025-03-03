// Problem Description
// 在石专西南门外的燕平路上，有n个卖菜的商店，按1至n的顺序排成一排，这些商店都卖一种蔬菜。
// 第一天，每个商店都自己定了一个价格。店主们希望自己的菜价和其他商店的一致，第二天，每一家商店都会根据他自己和相邻商店的价格调整自己的价格。具体的，每家商店都会将第二天的菜价设置为自己和相邻商店第一天菜价的平均值（用去尾法取整）。
// 注意，编号为1的商店只有一个相邻的商店2，编号为n的商店只有一个相邻的商店n-1，其他编号为i的商店有两个相邻的商店i-1和i+1。
// 给定第一天各个商店的菜价，请计算第二天每个商店的菜价。

// Input
// 输入的第一行包含一个整数n，表示商店的数量。
// 第二行包含n个整数，依次表示每个商店第一天的菜价。

// Output
// 输出一行，包含n个正整数，依次表示每个商店第二天的菜价。

#include <stdio.h>
#include <stdlib.h>

#define N 1002

void Fun(int *p, int n)
{
    int *temp;
    temp = (int *)malloc(sizeof(int) * n);

    temp[0] = (p[0] + p[1]) / 2;
    temp[n - 1] = (p[n - 1] + p[n - 2]) / 2;
    for (int i = 1; i < n - 1; i++)
    {
        temp[i] = (p[i - 1] + p[i] + p[i + 1]) / 3;
    }
    for (int i = 0; i < n; i++)
    {
        p[i] = temp[i];
    }
    
    free(temp);
}

int main(int argc, char const *argv[])
{
    int a[N], n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    Fun(a, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}