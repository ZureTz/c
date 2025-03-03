/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

#include <math.h>

void Fun(double a, double *h)
{
    if ((int)(fmod(a, 0.01) * 1000) <= 4)
    {
        *h = a - fmod(a, 0.01);
    }
    else
    {
        *h = a - fmod(a, 0.01) + 0.01;
    }
}

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main(void)
{
    double a, h;
    scanf("%lf", &a);
    Fun(a, &h);
    printf("The result:%lf\n", h);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */