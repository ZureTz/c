#include <stdio.h>

int main(void)
{
    printf("hello, world!\n");

    for (int i = 0; i < 123; i++)
    {
        i++;
        printf("%d", i++);
    }
    
    return 0;
}