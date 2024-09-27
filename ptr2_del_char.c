// Problem Description
// 编写函数Fun，其功能是：将字符串s中除了下标为奇数，同时 ASCII 值也为奇数的字符之外，其余的所有字符都删除，将剩余字符所形成的一个新串存放在数组t中。

// Input
// 仅一行。字符串s（长度不超过1000）。

// Output
//        仅一行。处理完后的字符串。
#include <stdio.h>
#define N 1000
void Fun(char *s, char *t);

void Fun(char *s, char *t)
{
    for (int i = 0, j = 0; s[i]; i++)
    {
        if ((i % 2) && (s[i] % 2))
        {
            t[j++] = s[i];
            t[j] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    char s[N + 5], t[N + 5];
    scanf("%s", s);
    Fun(s, t);
    printf("%s\n", t);
    return 0;
}