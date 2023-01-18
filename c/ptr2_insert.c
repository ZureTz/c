// Problem Description
// 有 n 个人（每个人有一个唯一的编号，用 1~n 之间的整数表示）在一个水龙头前排队准备接水，现在第 n 个人有特殊情况，经过协商，大家允许他插队到第 x 个位置。输出第 n 个人插队后的排队情况。

// Input
// 第一行 1 个正整数 n，表示有 n 个人，2<n≤100。

// 第二行包含 n 个正整数，之间用一个空格隔开，表示排在队伍中的第 1~ 第 n 个人的编号。

// 第三行包含 1 个正整数 x，表示第 n 个人插队的位置，1≤x<n。

// Output
// 一行包含 n 个正整数，之间用一个空格隔开，表示第 n 个人插队后的排队情况。

#include <stdio.h>
#define N 105

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void Insert(int *p, int n, int x)
{
    for (int i = n - 1; i >= x; i--)
    {
        swap(&p[i - 1], &p[i]);
    }
}

int main(int argc, char const *argv[])
{

    int a[N], n, x;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    Insert(a, n, x);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
