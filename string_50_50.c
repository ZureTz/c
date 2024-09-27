// 问题描述

// 给你一个由大写英文字母组成的4个字符的字符串S。请确定S是否正好由两种字符组成，并且都在S中出现两次。

// 限制条件

// S的长度是4。
// S由大写的英文字母组成。
// 样例输入 1

// ASSA
// 样例输出 1

// Yes

// Input
// S
//
// Output
// 如果S正好由两种字符组成，并且都在S中出现两次，则输出Yes；否则，输出No。

#include <stdio.h>

int main(void)
{
    char str[5], temp;
    int count_char[4] = {0};
    
    scanf("%s", str);
    for (int i = 0, j = 0, temp = str[0]; i < 4; i++)
    {
        if (str[i] != temp && str[i] != str[0])
        {
            temp = str[i];
            count_char[++j]++;
        }
        else if (str[i] != temp && str[i] == str[0])
        {
            temp = str[i];
            count_char[--j]++;
        }
        else
        {
            count_char[j]++;
        }
    }
    printf("%s", (count_char[0] == 2 && count_char[1] == 2) ? "Yes" : "No");

    return 0;
}