// 题目描述
//        从字符串s中删除指定的字符c。

// 输入
//        共2行，第一行为一个字符串s（长度小于80），第二行一个字符c。

// 输出
//        删除之后的字符串

#include <stdio.h>
#include <string.h>

int main(void)
{
    char ch, str[80];

    scanf("%[^\n]s", str);
    getchar();
    ch = getchar();
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ch)
        {
            for (int j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
            i--;
        }
    }
    printf("%s", str);

    return 0;
}