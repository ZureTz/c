// Problem Description
// 对N个字符串进行处理：
// 如果包含x或X，在字符串末尾插入YES，并把x或X替换为空格
// 如果不含，则在末尾插入NO；
// 将所有字符串按字典排序升序排列输出，每个字符串占一行
// 每个字符串最多包含一个x或X

// Input
// 第一行：正整数N表示字符串个数（N<101）
// 接下来N行，每行一个字符串

// Output
// N行，处理后的字符串排序

#include <stdio.h>
#include <iso646.h>
#include <string.h>

#define Y "YES"
#define N "NO"

void sort(int strings, char str[strings][1000])
{
    char temp[1000];

    for (int i = 0; i < strings - 1; i++)
    {
        for (int j = 0; j < strings - 1 - i; j++)
        {
            if (str[j][0] > str[j + 1][0])
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }
}

int main(void)
{
    int strings;
    scanf("%d", &strings);
    char str[strings][1000];

    for (int i = 0; i < strings; i++)
    {
        int flag = 0;
        scanf("%s", str[i]);
        for (int j = 0; j < strlen(str[i]); j++)
        {
            str[i][j] = (str[i][j] == 'x' or str[i][j] == 'X') ? ' ' : str[i][j];
            flag += str[i][j] == ' ' ? 1 : 0;
        }
        if (flag >= 1)
        {
            strcat(str[i], Y);
        }
        else
        {
            strcat(str[i], N);
        }
    }
    sort(strings, str);
    for (int i = 0; i < strings; i++)
    {
        puts(str[i]);
    }

    return 0;
}