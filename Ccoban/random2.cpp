
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool lapktra(int a[], int n, int value)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(a[i] == value)
		{
			return false;
		}
	}
	return true;
}

int main()
{
    int i,n,a,array[4],dem,s;
    for (i=1;i<=4;i++)
    {
        array[i] = 0;
    }
    srand((int)time(0));
    a = 1 + rand() % 4;
    array[1]=a;
    dem=2;
    s=0;
    while (dem != 5)
    {
        a = 1 + rand() % 4;
        if (lapktra(array,dem,a))
        {
            array[dem] = a;
            dem++;
        }
    }
    for (i=1;i<=4;i++)
    {
        cout << array[i] << ", ";
    }
    return 0;
}
