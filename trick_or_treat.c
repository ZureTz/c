#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N, K, *status;
    int count = 0;

    scanf("%d %d", &N, &K);
    status = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        status[i] = 1;
    }

    for (int i = 0; i < K; i++)
    {
        int temp1, temp2;
        scanf("%d", &temp1);
        for (int j = 0; j < temp1; j++)
        {
            scanf("%d", &temp2);
            status[temp2 - 1] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        count += status[i];
    }
    printf("%d", count);

    free(status);

    return 0;
}