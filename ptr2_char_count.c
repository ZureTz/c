// Problem Description
// 请编写函数 Fun ，它的功能是：统计形参 s 所指字符串中数字字符出现的次数，并存放在形参t中。

// Input
// 仅一行。一个字符串，长度小于80。

// Output
// 一个整数，表示数字字符的出现次数。

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 81

void Fun(char *p, int *t)
{
    *t = 0;
    for (int i = 0; p[i]; i++)
    {
        *t += (_Bool)isdigit(p[i]);
    }
}

int main(int argc, char const *argv[])
{
    char s[N];
    int t;

    fgets(s, N, stdin);
    s[strlen(s) - 1] = '\0';
    Fun(s, &t);
    printf("%d\n", t);

    return 0;
}