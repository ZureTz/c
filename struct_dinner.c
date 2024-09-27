// Problem Description
// 天下历圈圈年，A国与C国发生了战争。C国完胜后开始了狂欢。突然某人大喝一声“我消灭了最多的敌人！”。众人均不服，都把自己在每场战役中消灭的敌人数目晒了出来，可是大家七嘴八舌的，最后也没搞清楚到底谁杀敌的总数最多。现在就需要你来帮忙统计战功，找出功劳最大的英雄。

// Input
// 首先输入一个整数n(1<n<100)，表示有n个人参与评选。 接下来n行，每行输入一个姓名和5个整数，表示该将领在每场仗战役中消灭敌人的数目。姓名不包含空格。

// Output
// 输出英雄的名字，以及总的杀敌数量。测试数据保证满足条件的英雄唯一。

#include <stdio.h>
typedef struct hero
{
    char name[30];
    int kill[5];
    int sum;
} HERO;

typedef struct
{
    int value;
    int positon;
} MAX;

HERO Fun(HERO *countries, int numbers)
{
    MAX max_information;

    max_information.value = max_information.positon = 0;
    for (int i = 0; i < numbers; i++)
    {
        countries[i].sum = 0;
        for (int j = 0; j < 5; j++)
        {
            countries[i].sum += countries[i].kill[j];
        }

        if (countries[i].sum > max_information.value)
        {
            max_information.value = countries[i].sum;
            max_information.positon = i;
        }
    }

    return countries[max_information.positon];
}

int main(int argc, char const *argv[])
{
    int T, i, j;
    scanf("%d", &T);
    HERO h[T], champion;
    for (i = 0; i < T; i++)
    {
        scanf("%s", h[i].name);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &h[i].kill[j]);
        }
    }
    champion = Fun(h, T);
    printf("%s %d\n", champion.name, champion.sum);
    return 0;
}