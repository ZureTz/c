// Problem Description
// 编写函数Fun，其功能是：将数组s存放的字符串中的所有数字字符移到所有非数字字符之后，并保持数字字符串和非数字字符串原有的先后次序。

// Input
// 仅一行。字符串s（长度不超过1000）。

// Output
// 仅一行。处理完后的字符串。

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 1000

void Fun(char *str)
{
    int length = strlen(str);
    char temp;

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (isdigit(str[j]) && isalpha(str[j + 1]))
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    char s[N + 5];

    gets(s);
    Fun(s);
    puts(s);

    return 0;
}
