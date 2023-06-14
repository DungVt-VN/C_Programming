#include <stdio.h>
#include <stdlib.h>

int maxArrayValue(int *a, int n)
{
    int sumValue = 0;
    int MaxSum = 0;

    for (int i = 0; i < n; i++)
    {
        sumValue += a[i];

        if (sumValue > MaxSum)
        {
            MaxSum = sumValue;
        }
        if (sumValue < 0)
        {
            sumValue = 0;
        }
    }

    return MaxSum;
}

int maxArrayValueandvt(int *a, int n)
{
    int head = 0, head2 = 1;
    int tail = 0;
    int sumValue = -1e9;
    int MaxSum = 0;

    for (int i = 0; i < n; i++)
    {
        sumValue += a[i];
        if (sumValue >= MaxSum)
        {
            head = head2;
            tail = i + 1;
            MaxSum = sumValue;
        }
        if (sumValue < 0)
        {
            sumValue = 0;
            head2 = i + 2;
        }
    }
    printf("Max la: %d tu a[%d] den a[%d]", MaxSum, head, tail);
}

int main()
{
    int a[] = {-1, 3, 6, -12, 4, 4, -12, 3, 4, 2, -5};
    int n = 11;
    printf("Tong max la: %d\n\n", maxArrayValue(a, n));
    maxArrayValueandvt(a, n);

    return 0;
}