// 题目描述
// 字符串匹配是计算机科学中最古老、研究最广泛的问题之一。它的应用包括生物信息学、信息检索、拼写检查、语言翻译、数据压缩、网络入侵检测。
// 输入一个主串str和一个要查找的子串substr，输出子串substr在主串str中首次出现的位置。例如主串str为：ababcabababab,子串为ababa，则子串在主串中首次出现的位置为5。

// 输入
//        有两行。第1行为主串str，第2行为要查找的子串substr。主串长度不超过100，子串长度小于等于主串长度。

// 输出
//        子串substr在主串str中首次出现的位置，如果没有出现，输出-1。

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[101], substr[101];
    int flag = 0;

    scanf("%s %s", str, substr);
    for (int i = 0; i < strlen(str) - strlen(substr) + 1 && flag == 0; i++)
    {
        for (int j = 0; j < strlen(substr); j++)
        {
            if (str[i + j] != substr[j])
            {
                break;
            }
            else if (j == strlen(substr) - 1)
            {
                flag = i;
            }
        }
    }
    printf("%d", (flag == 0) ? -1 : flag);

    return 0;
}