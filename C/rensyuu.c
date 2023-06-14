#include <stdlib.h>
#include <stdio.h>

int a[] = {1, 3, 5, 21, 2, 535, 4, 53};
int n = 8;

void sapxepchen()
{
    int i, j, last;
    for (int i = 1; i < n; i++)
    {
        last = a[i];
        j = i - 1;
        while (j > 0 && a[j] > last)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = last;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sapxepchon()
{
    for (int i = 1; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(&a[i], &a[min]);
    }
}
void sapxepnoibot()
{
    int i, j;
    do
    {
        j = 1;
        for (i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                j = 0;
            }
        }
    } while (j == 0);
}

// sapxeptron:

void merge(int A[], int first, int mid, int last)
{   
    int tmp[100];
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;
    int i = first;
    for (; first1 <= last1 && first2 <= last2; i++)
    {
        if (A[first1] < A[first2])
        {
            tmp[i] = A[first1];
            first1++;
        }
        else
        {
            tmp[i] = A[first2];
            first2++;
        }
    }
    for (; first1 <= last1;first1++, i++)
    {
        tmp[i] == A[first1];
    }
    for (; first2 <= last2;first2++,i++)
    {
        tmp[i] = A[first2];
    }
    for (int j = first; j <= last; j++)
    {
        A[j] = tmp[j];
    }
}

void sapxeptron(int A[], int p, int r)
{
    if (p < r)
    {
        int mid = (p + r) / 2;
        sapxeptron(A, p, mid);
        sapxeptron(A, mid + 1, r);
        merge(A, p, mid, r);
    }
}

// sapxepnhanh　QuickSort

int Privotion(int A[], int left, int right)
{
    int privot = left;
    int L = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (A[i] < A[privot])
        {
            L++;
            swap(&a[i], &a[L]);
        }
    }
    swap(&A[privot], &A[L]);
    return L;
}

void QuickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int L = Privotion(A, p, r);
        QuickSort(A, p, L - 1);
        QuickSort(A, L + 1, r);
    }
}

int main()
{
    //    sapxepchen();
    //    sapxepchon();
    //    sapxepnoibot();
    sapxeptron(a, 0, 7);
    //    QuickSort(a, 0, 7);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}