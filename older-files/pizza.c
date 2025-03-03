// 问题描述
// 我们有一个圆形的比萨饼。

// 高桥将用一个长度为N的序列A，按照以下程序切割这个比萨饼。

// 首先，从中心向12点方向切一刀。
// 接下来，做NN次操作。第ii次操作如下。
// 将比萨饼顺时针旋转A_i度
// 然后，从中心向12点方向切一刀。

// 找到切割后最大的比萨饼的中心角。

// 约束条件

// 输入的所有数值都是整数。
// 1≤N≤359
// 1≤A_i≤359
// 在同一位置不会有多次切割。

#include <stdio.h>

void bbsort(int length, int array[length + 1])
{
    int temp;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int sum(int length, int array[length], int pos)
{
    int result = 0;

    for (int i = 0; i < pos + 1; i++)
    {
        result += array[i];
    }

    return result;
}

int main(void)
{
    int n;
    int max = 0;

    scanf("%d", &n);
    int temp[n];
    int pizza[n + 1];

    pizza[0] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp[i]);
        pizza[i + 1] = (sum(n, temp, i) % 360);
    }
    bbsort(n, pizza);
    for (int i = 0; i < n; i++)
    {
        max = (pizza[i + 1] - pizza[i]) > max ? (pizza[i + 1] - pizza[i]) : max;
    }
    max = (360 - (pizza[n] - pizza[0])) > max ? (360 - (pizza[n] - pizza[0])) : max;
    printf("%d", max);

    return 0;
}