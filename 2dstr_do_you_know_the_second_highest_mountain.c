// Problem Description
// The Republic of AtCoder has N mountains. The i-th mountain has a name S_i
// and a height of T_i.

// Return the name of the second highest mountain there. It is guaranteed that all the mountains have different names and different heights.

// Constraints
// 2≤N≤1000
// 1≤(the length of S_i)≤15
// 1≤T_i≤10^5

// S_i!=S_j
// T_i!=T_j
// S_i consists of uppercase English letters, lowercase English letters, and digits.
// N and T_i are integers.

// Input
// Input is given from Standard Input in the following format:

// NN

// S_1 T_1
// ​S_2 T_2
// ​⋮
// S_N T_N

// Output
// Print the name of the second highest mountain.

#include <stdio.h>
#include <string.h>

void sort(int n, char names[n][16], int array[n])
{
    int temp_num;
    char temp_string[16];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp_num = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp_num;

                strcpy(temp_string, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp_string);
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    char mountain_names[n][16];
    int heights[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", mountain_names[i], &heights[i]);
    }
    sort(n, mountain_names, heights);
    printf("%s", mountain_names[n - 2]);

    return 0;
}