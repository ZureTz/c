// Problem Description
// 程序通过定义学生结构体变量，存储了学生的学号、姓名和 3 门课的成绩。建立函数 fun对所指结构体变量中的数据进行修改 , 最后在主函数中输出修改后的数据。程序代码在提示(Hint)中给出，只需要填写空缺部分。

// Input
// 无。

// Output
// 修改后的学生信息。

#include <stdio.h>
#include <string.h>

struct student_information
{
    long StudentNumber;
    char StudentName[10];
    float StudentScores[3];
};

void change_information(struct student_information *info)
{
    info->StudentNumber = 10004;
    strcpy(info->StudentName, "LiJie");
}

int main(int argc, char const *argv[])
{
    struct student_information info_0 = {10002, "ZhangQi", {93, 85, 87}};
    int i;

    change_information(&info_0);
    printf("No: %ld  Name: %s\nScores:", info_0.StudentNumber, info_0.StudentName);
    for (i = 0; i < 3; i++)
    {
        printf("%6.2f", info_0.StudentScores[i]);
    }
    printf("\n");

    return 0;
}