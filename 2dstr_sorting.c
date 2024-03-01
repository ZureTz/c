// Problem Description
// 我们知道计算学院的每个精英班有10名学生，老师会依次给出10名学生的名字(均为不含有空格的英文字符串)。你需要将这些名字按照字典序从小到大进行输出。

// Input
// 输入10行不含有空格的字符串，分别对应十个学生的姓名(字符串长度均大于0且小于20

// Output
// 输出为10行，为排序后的10个学生姓名，每个学生姓名单独占一行。

#include <stdio.h>
#include <string.h>

void sort(char str[10][20])
{
    char temp[20];

    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
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
    char str[10][20];

    for (int i = 0; i < 10; i++)
    {
        scanf("%s", str[i]);
    }
    sort(str);
    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", str[i]);
    }
    
    return 0;
}