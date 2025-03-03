// 问题描述

// 给你一个由小写英文字母组成的字符串SS。
// 将S开头的第a个和第b个字符互换，并打印出结果字符串。

// 约束条件

// S 是一个由小写英文字母组成的字符串。
// S 的长度，∣S|，满足2≤∣S∣≤10
// 1≤a<b≤∣S∣
// a 和 b 是整数。

#include <stdio.h>

int main(void)
{
    char str[11], temp;
    int pos1, pos2;

    scanf("%s", str);
    scanf("%d %d", &pos1, &pos2);
    temp = str[pos1 - 1];
    str[pos1 - 1] = str[pos2 - 1];
    str[pos2 - 1] = temp;
    printf("%s", str);

    return 0;
}