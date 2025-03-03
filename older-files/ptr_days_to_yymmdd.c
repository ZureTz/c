// Input
// 一个整数n，表示2014年的第几天。

// Output
// 输出对应的是几月几日。

#include <stdio.h>

void fun(const int days, int *month, int *day)
{
    const int month_days_sum[13] =
        {
            0,
            31,
            31 + 28,
            31 * 2 + 28,
            31 * 2 + 30 + 28,
            31 * 3 + 30 + 28,
            31 * 3 + 30 * 2 + 28,
            31 * 4 + 30 * 2 + 28,
            31 * 5 + 30 * 2 + 28,
            31 * 5 + 30 * 3 + 28,
            31 * 6 + 30 * 3 + 28,
            31 * 6 + 30 * 4 + 28,
            31 * 7 + 30 * 4 + 28};

    for (int i = 0; i < 12; i++)
    {
        if (month_days_sum[i] < days && month_days_sum[i + 1] >= days)
        {
            *month = i + 1;
            *day = days - month_days_sum[i];
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, month, day;
    scanf("%d", &n);
    fun(n, &month, &day);
    printf("%d月%d日\n", month, day);
    return 0;
}
