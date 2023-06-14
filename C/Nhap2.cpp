#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
 
void inratatcadaycon(int a[], int n){
    int i,j,k;

    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            printf("\n");
            for(k=i;k<=j;k++)
                printf("%d ",a[k]);
        }
    }
}
 

int timtrongluongmax(int a[], int n){
    int i,j,k;

    int maxSum=a[0];

    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            int sum=0;
            for(k=i;k<=j;k++)
                sum+=a[k];
            if(sum>maxSum)
                maxSum=sum;
        }
    }


    return maxSum;
}
 
int timtrongluongmax2(int a[],int n)
{
    int i,j;

    int maxSum=a[0];

    for(i=0;i<n;i++){
        int sum=0;
        for(j=i;j<n;j++){
            sum+=a[j];
            if(sum>maxSum)
                maxSum=sum;
        }
    }

    return maxSum;
}
 
int main(){
    int A[6]={-2, 11, -4, 13, -5, 2};

    inratatcadaycon(A,6);

    int m = timtrongluongmax(A,6);

    printf("\nTrong luong lon nhat la:%d\n",m);

    //getch();
    return 1;
}
