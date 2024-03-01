// 题目描述
// 输入两个字符串s1和s2，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”。

// 输入
// 两个字符串 s1 和 s2。

// 输出
// 删除后的字符串 s1。

#include <stdio.h>
#include <string.h>

int main(void)
{
    char ch[50], str[80];

    scanf("%[^\n]s", str);
    scanf("%s", ch);
    for (int i = 0; i < strlen(ch); i++)
    {
        for (int j = 0; j < strlen(str); j++)
        {
            if (str[j] == ch[i])
            {
                for (int k = j; str[k] != '\0'; k++)
                {
                    str[k] = str[k + 1];
                }
                j--;
            }
        }
    }
    printf("%s", str);

    return 0;
}