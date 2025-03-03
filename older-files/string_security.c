// Problem Statement
// Snuke实验室的门是用安全密码锁住的。
// 安全密码是一个4位数字。当安全代码包含两个相同的连续数字时，我们称它为很难进入的。
// 你将得到当前的安全密码S。如果S为很难进入的，打印Bad'；否则，打印Good'。

// Constraints

// SS是一个由数字组成的44个字符的字符串。

// Sample Input 1
// 3776
// Sample Output 1
// Bad

// 第二和第三位数字是一样的，所以3776是很难进入的。

// Sample Input 2
// 8080
// Sample Output 2
// Good

// 没有两个连续的数字是相同的，所以8080不是很难进入的。

// Sample Input 3
// 1333
// Sample Output 3
// Bad

// Input
// S
// Output
// 如果S为很难进入的，打印Bad'；否则，打印Good'。

#include <stdio.h>

int main(void)
{
    char pwd[5];

    scanf("%s", pwd);
    for (int i = 0; i < 4 - 1; i++)
    {
        if (pwd[i] == pwd[i + 1])
        {
            printf("Bad");
            break;
        }
        else if (i == 4 - 1 - 1)
        {
            printf("Good");
            break;
        }
    }

    return 0;
}