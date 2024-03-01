// Problem Description
// 编写函数Fun，其功能是：统计指定子字符串substr在字符串str中出现的次数。

// Input
// 有两行。第1行是字符串str（长度不超过1000）。第2行是子串substr（长度不大于原串的长度）。

// Output
// 仅一行。一个整数，表示子串在原字符串中出现的次数。

#include <stdio.h>
#include <string.h>
#define N 1000

void Fun(const char *str, const char *substr, int *count)
{
    int length_str = strlen(str);
    int length_substr = strlen(substr);

    *count = 0;
    for (int i = 0; i < length_str - (length_substr - 1); i++)
    {
        for (int j = 0; j < length_substr; j++)
        {
            if (str[i + j] != substr[j])
            {
                break;
            }
            else if (j == length_substr - 1)
            {
                (*count)++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    char str[N + 5], substr[N + 5];
    int count;
    gets(str);
    gets(substr);
    Fun(str, substr, &count);
    printf("%d\n", count);
    return 0;
}
