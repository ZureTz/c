//题目描述
//小明所在的合唱队共有N 个人（N为奇数）。为了准备一次演出，老师开始为他们安排合唱队形了。 
//大家都知道，合唱队形通常是中间高两端低的。老师是这样安排他们的队形的：
//先让所有的同学按高个儿在前的顺序排成一队。然后，最高的那位同学单独站出来， 这是合唱队形的中心，
//再让第二位同学站在他的右手边，让第三位同学站在他的左手边，再依次向两端安排其他人…… 

//事先给定所有人的身高，请输出他们站成合唱队形之后的身高顺序。

//输入
//有两行。第1行是一个正整数N（N<1000），表示合唱队的总人数，已知N为奇数。第2行是N 个整数，表示以厘米为单位的所有人的身高。

//输出
//仅一行。N个整数，表示他们按老师的要求站成合唱队形之后的身高顺序。

#include <stdio.h>

void bobblesort(int n,int *arr)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else
            {
                continue;
            }
            
        }
        
    }
    
}

int neg1_pow(int n)
{
    int result;

    result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= -1;
    }

    return result;
}

int main(void)
{
    int num;
    int pos;

    scanf("%d", &num);
    int arr[num];
    int arr1[num];
    pos = (num - 1) / 2;

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    bobblesort(num, arr);

    for (int i = 0; i < num; i++)
    {
        pos += neg1_pow(i + 1) * i;
        arr1[pos] = arr[num - 1 - i];
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr1[i]);
    }
    

    return 0;
}