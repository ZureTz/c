// 题目描述
// 天气太冷，外面冷得像冰库，真郁闷！小明实在无聊，冻得哪儿都去不了，只能玩玩字符游戏，他想把ab变成aba，把123变成12321，你来帮帮他的忙吧。

// 输入
// 若干行。每行一个字符串，最长为200位，最短为2位。

// 输出
// 镜像文字，如输入124，则输出12421。

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[201];

    while (scanf("%s", str) == 1)
    {
        printf("%s", str);
        for (int i = strlen(str) - 2; i >= 0; i--)
        {
            putchar(str[i]);
        }
        printf("\n");
    }

    return 0;
}