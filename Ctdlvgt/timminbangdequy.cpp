#include<stdio.h>

int timminle(int a[],int n){
           if(n==1) {
               if(a[0]%2==0) return 0;
               else return a[0];
           }
           else {
               int k=timminle(a,n-1);
               if(a[n-1]%2==0) return k;
               else{
                   if(k==0) return a[n-1];
                   else {
                       if(k<a[n-1]) return k;
                       else return a[n-1];
                   }
               }
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
	int a[6] = { 1 , 2 ,2,4,6,2};
	printf("\nMin la: %d",timminD_C(a,0,6));
}
