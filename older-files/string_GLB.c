// 题目描述
//        只要一个字符串中包含大写“GLB”，高老板就认为这是一个GLB串。现在给你一些字符串，请你帮高老板判断这些字符串是不是GLB串。

// 输入
//        有多行。第1行一个整数T，表示T行数据。接下来有T行，每行一个字符串（只包括大小写字母），长度小于100。

// 输出
//        如果是GLB串输出YES，否则输出NO。

#include <stdio.h>
#include <string.h>

int main(void)
{
    int strings;
    scanf("%d", &strings);
    char str[strings][100];
    int status[strings];

    for (int i = 0; i < strings; i++)
    {
        status[i] = 0;
        scanf("%s", str[i]);
        if (strlen(str[i]) > 2)
        {
            for (int j = 0; j < strlen(str[i]) - 2; j++)
            {
                if (str[i][j] == 'G' && str[i][j + 1] == 'L' && str[i][j + 2] == 'B')
                {
                    status[i] = 1;
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < strings; i++)
    {
        if (status[i] == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}