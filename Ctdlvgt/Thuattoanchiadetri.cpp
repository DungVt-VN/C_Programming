#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int Fact(int n)
{
    printf("Goi ham voi n=%d\n", n);
    if (n == 0)
    {
        printf("Ket thuc ham voi n=%d, tra ve 1 \n", n);
        return 1;
    }
    else
    {
        int k = Fact(n - 1);
        printf("Ket thuc ham voi n=%d, tra ve %d \n", n, n * k);
        return (n * k);
    }
}

int power(int a, int n)
{
    if ((a < 0) || (n < 0))
        return -1;
    if (n == 0)
        return 1;
    else
        return a * power(a, n - 1);
}

int FibRec(int n)
{
    if (n <= 1)
        return n;
    else
        return FibRec(n - 1) + FibRec(n - 2);
}

int C(int n, int k)
{
    if ((k == 0) || (k == n))
        return 1;
    else
        return C(n - 1, k - 1) + C(n - 1, k);
}

int solanchuyen = 0;
void HanoiTower(int n, char a, char b, char c)
{
    if (n == 1)
        printf("\n%d:chuy?n 1 dia truc tiep t? c?c %c sang c?c %c", ++solanchuyen, a, c);
    else
    {
        HanoiTower(n - 1, a, c, b);
        HanoiTower(1, a, b, c);
        HanoiTower(n - 1, b, a, c);
    }
}

int tongdaydequi(int a[], int n)
{
    if (n == 1)
        return a[0];
    else
        return tongdaydequi(a, n - 1) + a[n - 1];
}

int timmin(int a[], int n)
{
    if (n == 1)
        return a[0];
    else
    {
        int k = timmin(a, n - 1);
        if (k < a[n - 1])
            return k;
        else
            return a[n - 1];
    }
}

int timminle(int a[], int n)
{
    if (n == 1)
    {
        if (a[0] % 2 == 0)
            return 0;
        else
            return a[0];
    }
    else
    {
        int k = timminle(a, n - 1);
        if (a[n - 1] % 2 == 0)
            return k;
        else
        {
            if (k == 0)
                return a[n - 1];
            else
            {
                if (k < a[n - 1])
                    return k;
                else
                    return a[n - 1];
            }
        }
    }
}

int timminD_C(int a[], int l, int r)
{
    if (l == r)
    {
        return a[l];
    }
    else
    {
        int q = (l + r) / 2;
        int minl = timminD_C(a, l, q);
        int minr = timminD_C(a, q + 1, r);
        if (minl < minr)
            return minl;
        else
            return minr;
    }
}

int main()
{
    printf("%d\n", Fact(5));
    printf("%d\n", FibRec(8));
    printf("%d\n", C(5, 3));
    printf("%d\n", power(2, 5));
    HanoiTower(1, 'A', 'B', 'C');

    int A[5] = {4, 1, -5, 2, -10};

    int m = tongdaydequi(A, 5);
    printf("\n\ntongday=%d\n", m);
    m = timmin(A, 5);
    printf("\n\ntimmin=%d\n", m);
    m = timminle(A, 5);
    printf("\n\ntimminle=%d\n", m);
    m = timminD_C(A, 0, 4);
    printf("\n\nminday=%d\n", m);

    // getch();
    return 1;
}
