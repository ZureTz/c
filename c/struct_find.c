// Problem Description
// 学生的记录由学号和成绩组成，N名学生的数据已在主函数中放入结构体数组s中, 结构体STREC和main函数已给出，请编写函数fun，它的功能是：把指定分数范围内的学生数据放在h所指的数组中，分数范围内的学生人数由函数值返回。

// Input
// 两个整数，表示分数范围。

// Output
// 在指定分数范围的学生学号和成绩。

// Sample Input

// 60 69

// Sample Output

// The student's data between 60--69 :
// GA002   69
// GA008   64
// GA012   64
// GA017   64
// GA018   64

#include <stdio.h>
#define N 16

typedef struct
{
    char num[10];
    int s;
} STREC;

int fun(STREC *src, STREC *dest, int leftbound, int rightbound)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (leftbound <= src[i].s && src[i].s <= rightbound)
        {
            dest[count++] = src[i];
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    STREC Original_data[N] = {
        {"GA005", 85}, {"GA003", 76}, {"GA002", 69}, {"GA004", 85}, {"GA001", 96}, {"GA007", 72}, {"GA008", 64}, {"GA006", 87}, {"GA015", 85}, {"GA013", 94}, {"GA012", 64}, {"GA014", 91}, {"GA011", 90}, {"GA017", 64}, {"GA018", 64}, {"GA016", 72}};
    STREC InRange_data[N];
    int numbers_in_range, LeftBoundary, RightBoundary;

    scanf("%d %d", &LeftBoundary, &RightBoundary);
    if (RightBoundary < LeftBoundary)
    {
        int temp;
        temp = RightBoundary;
        RightBoundary = LeftBoundary;
        LeftBoundary = temp;
    }
    numbers_in_range = fun(Original_data, InRange_data, LeftBoundary, RightBoundary);
    printf("The student's data between %d--%d :\n", LeftBoundary, RightBoundary);
    for (int i = 0; i < numbers_in_range; i++)
    {
        printf("%s %4d\n", InRange_data[i].num, InRange_data[i].s);
    }
    return 0;
}