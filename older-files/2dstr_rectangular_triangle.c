// Problem Description
// 现在需要你打印一个m行的直角三角形，要求每一行和每一列的字母都按按字典序升序排列,第一行的字母为A,第二行的字母为BC,第三行的字母为CDE

// Input
// 输入共一行,包含一个整数m, 0≤m≤13

// Output
// 输出为m行，第i行有i个按要求顺序排列的字符。

#include <stdio.h>

int main(void)
{
    int rows;

    scanf("%d", &rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%c", 'A' + i + j);
        }
        putchar('\n');
    }
    
    return 0;
}