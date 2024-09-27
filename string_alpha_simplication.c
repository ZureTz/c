// 题目描述
// 给出一串全部为小写英文字母的字符串，要求把这串字母简化。简化规则是：统计连续出现的字母数，输出时先输出个数，再输出字母。比如：aaabbbaa，则简化为3a3b2a；而zzzzeeeeea，则简化为4z5e1a。

// 输入
// 有多行。第一行为一个整数n，表示共有n组测试数据（1≤n≤100）。接下来有n行，每行第一个数为字符串长度t（t≤1000），然后为一个长度为t的字符串。

// 输出
// 简化后的字符串，每组测试用例占一行。

#include <stdio.h>

int main(void)
{
    int strings;
    scanf("%d", &strings);
    char str[strings][1001], alphas_count_in_string[strings][100], chars[strings][100], kinds_of_alphas[strings];
    int length[strings];

    for (int i = 0; i < strings; i++)
    {
        scanf("%d %s", &length[i], str[i]);
        for (int j = 0, count = 0, sum = 0; j < length[i]; j++)
        {
            if (j == length[i] - 1 || str[i][j] != str[i][j + 1])
            {
                chars[i][count] = str[i][j];
                alphas_count_in_string[i][count] = j + 1 - sum;
                sum += alphas_count_in_string[i][count];
                count++;
            }
            kinds_of_alphas[i] = count;
        }
    }
    for (int i = 0; i < strings; i++)
    {
        for (int j = 0; j < kinds_of_alphas[i]; j++)
        {
            printf("%d%c", alphas_count_in_string[i][j], chars[i][j]);
        }
        putchar('\n');
    }

    return 0;
}