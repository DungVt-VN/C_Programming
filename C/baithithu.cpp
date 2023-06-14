#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

 

int Fact( int n){
        printf("Goi ham voi n=%d\n",n);
        if( n == 0){
                printf("Ket thuc ham voi n=%d, tra ve 1 \n",n);
                return 1;
        } 
         else{
                int k=Fact(n-1);
                printf("Ket thuc ham voi n=%d, tra ve %d \n",n,n*k);
                return ( n * k);
        }
}

 

int FibRec(int n){
    if (n<=1)return n;
    else return FibRec(n-1)+FibRec(n-2);
}

 

int C(int n, int k){
    if ((k==0)||(k==n)) return 1;
    else return C(n-1,k-1)+C(n-1,k);
}

 

int solanchuyen=0;
void HanoiTower(int n, char a, char b, char c){
    if (n==1) printf("\n%d:chuyen 1 dia truc tiep tu coc %c sang coc %c",++solanchuyen,a,c);
    else{
        HanoiTower(n-1,a,c,b);
        printf("\n");
        HanoiTower(1,a,b,c);
        printf("\n");
        HanoiTower(n-1,b,a,c);
    }
}

 

int timminD_C(int a[], int l, int r){
    if(l==r){
        return a[l];
    }
    else{
        int q=(l+r)/2;
        int minl=timminD_C(a,l,q);
        int minr=timminD_C(a,q+1,r);
        if(minl<minr)
            return minl;
        else return minr;
    }
}

 


int main(){
    // printf("%d\n",Fact(5));
    // printf("%d\n",FibRec(8));
    // printf("%d\n",C(5,3));
    
    HanoiTower(5,'A','B','C');
    
    /*int A[5]={4,1,3,2,8};
    
    int m=timminD_C(A,0,4);
    printf("\n\nminday=%d\n",m);*/
    
    //getch();
    return 1;
}