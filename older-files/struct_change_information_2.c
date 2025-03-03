// Problem Description
// 给定程序通过定义并赋初值的方式，利用结构体变量存储了一名学生的学号、姓名和3门课的成绩。函数fun的功能是将该学生的各科成绩都乘以一个系数a。 请在程序的下划线处填入正确的内容，使程序得出正确的结果。
// 函数在提示(Hint)中给出

// Input
// 系数a。

// Output
//        修改后的学生信息。

#include <stdio.h>

typedef struct
{
    int number;
    float scores[3];
    char name[9];

} StudentInfo;

void output(StudentInfo *info)
{
    printf("%d %s : ", info->number, info->name);
    for (int i = 0; i < 3; i++)
    {
        printf("%5.1f", info->scores[i]);
    }
    printf("\n");
}

void modify(StudentInfo *info, float scale)
{
    for (int i = 0; i < 3; i++)
    {
        info->scores[i] *= scale;
    }
}

int main(int argc, char const *argv[])
{
    StudentInfo student_0 = {1, 76.5, 78.0, 82.0, "Zhanghua"};
    float scale;

    scanf("%f", &scale);
    modify(&student_0, scale);
    output(&student_0);

    return 0;
}