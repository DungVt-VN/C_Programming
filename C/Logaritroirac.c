#include <stdio.h>

// logarit(a,b) = g

void TimLogaritRoiRac (int a, int b, int N)
{
    int k=1, i=0;
    while (k!=b)
    {
        k *= a;
        k = k%N;
        i++;
        if (i>N)
        {
            printf ("Khong tim thay!\n");
            return;
        }
    }
    printf ("Dap an:\t%d",i%N);
}

int main ()
{
    int a, b;
    int N;
    printf ("Nhap co so a: ");
    scanf ("%d",&a);
    printf ("Nhap co so b: ");
    scanf ("%d",&b);
    printf ("Nhap modulo N: ");
    scanf ("%d",&N);
    TimLogaritRoiRac (a,b,N);
}