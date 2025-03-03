// Problem Description
// 请编写函数 Fun ，其功能是求出数组的最大元素在数组中的下标并存放在 k 中。

// Input
// 仅一行。10个整数。

// Output
// 两个整数，第1个整数表示最大值的下标，第2个整数是最大值，以逗号分隔。

#include <stdio.h>
#include <limits.h>

void Fun(const int *vals, const int length, int *index)
{
    int max = INT_MIN;
    *index = -1;

    for (int i = 0; i < length; i++)
    {
        if (vals[i] > max)
        {
            max = vals[i];
            *index = i;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[10], k;
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    Fun(a, 10, &k);
    printf("%d,%d\n", k, a[k]);
    return 0;
}
