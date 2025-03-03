// 题目描述
// 从键盘输入一个字符串（长度小于等于1000），再输入一个特定字符ch，判断ch在字符串中的出现次数。

// 输入
// 共两行。第1行为一个字符串，第2行为一个特定字符ch。

// 输出
//  ch在字符串中的出现次数。

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[50], ch;
    int count = 0;

    gets(str);
    ch = getchar();
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ch)
        {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}