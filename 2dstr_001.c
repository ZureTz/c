// Problem Description
//        在一个字符串王国里生活着许许多多的字符串，如:abcde、adfsddf、dss等等。当然他们也同人类一样有许许多多的种族。如果两个字符串有共同的前缀，那么他们就拥有共同的祖先，便认为他们是同一族的。现在给你一份王国所有成员的名单，请你找出王国里有多少个种族！

// Input
//        第一行输入一个奇数n，表示有n个字符串(n<=100)。

// Output
//        输出种族的个数

#include <stdio.h>

int main(void)
{
    int n;
    int count = 0;
    int alphas[26] = {0};
    char ch;

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        ch = getchar();
        alphas[ch - 'a'] = 1;
        while (getchar() != '\n')
        {
            continue;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        count += alphas[i];
    }
    printf("%d", count);

    return 0;
}