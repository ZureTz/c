#include <iostream>
#include <stdlib.h>
using std::cin;
using std::cout;

int *find_c(int length, int *a_array)
{
    int *c_array = (int *)malloc(sizeof(int) * (length + 1));
    c_array[0] = 1;
    for (int i = 1; i <= length; i++)
    {
        c_array[i] = c_array[i - 1] * a_array[i - 1];
    }
    return c_array;
}

int *find_b(int mystery_code, int length, int *c_array)
{
    int *b_array = (int *)malloc(sizeof(int) * length);
    b_array[0] = mystery_code % c_array[1];
    for (int i = 1; i < length; i++)
    {
        b_array[i] = ((mystery_code % c_array[i + 1]) - (mystery_code % c_array[i])) / c_array[i];
    }
    return b_array;
}

int main(int argc, char const *argv[])
{
    int *a_array, *b_array, *c_array;
    int length, mystery_code;

    cin >> length >> mystery_code;
    a_array = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        cin >> a_array[i];
    }

    c_array = find_c(length, a_array);
    b_array = find_b(mystery_code, length, c_array);

    for (int i = 0; i < length - 1; i++)
    {
        cout << b_array[i] << ' ';
    }
    cout << b_array[length - 1];

    free(a_array);
    free(b_array);
    free(c_array);

    return 0;
}
