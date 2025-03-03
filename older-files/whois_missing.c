// Problem Description
// 问题描述

// 我们有44张牌, 上面写着整数1, 4张牌写着2, ..., 4张牌写着N元, 总共有4N张牌

// 高桥洗了这些牌, 去掉了其中一张, 然后给你一堆剩下的4N-1的牌。这堆牌中的第ii张牌(1≤i≤4N-1)上有一个整数A_i
// 求被高桥抽走的那张牌上的整数。

// 约束条件

// 1≤N≤10^5
// 1≤A_i≤N
// (1≤i≤4N-1)
// 对于每个k(1≤k≤N), 至多有44个指数ii, 使A_i=k
// 输入的所有数值都是整数。

// Input
// N
// A_1 A_2 … A_{4N-1}

// Output
// 输出结果

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N, *range;

    scanf("%d", &N);
    range = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        range[i] = 0;
    }

    for (int i = 0; i < 4 * N - 1; i++)
    {
        int temp;
        scanf("%d", &temp);
        range[temp - 1]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (range[i] != 4)
        {
            printf("%d", i + 1);
            break;
        }
    }

    free(range);

    return 0;
}