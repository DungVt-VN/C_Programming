#include<stdio.h>
#include<string.h>

int tinhmu(int a,int n){
	if(a< 0 ||n <0) return -1;
	if(n==0)
		return 1;
	else
		return a*tinhmu(a,n-1);
}

int tinhtong(int arr[] , int n1){
	if(n1 == 0){
		return arr[0];
	}else 
		return arr[n1] + tinhtong(arr,n1-1);
}

int timmin(int arr[],int n){
       if(n==1) return arr[0];
       else {
           int k=timmin(arr,n-1);
           if(k<arr[n-1]) return k;
           else return arr[n-1];
    }
}

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

int main(){
	//printf("\nKet qua la: %d",tinhmu(2,2));
	int arr[5] = {10,100,8,6,1};
	printf("\nKet qua la: %d",tinhtong(arr,5));
	printf("\nKet qua la: %d",timmin(arr,5));
	printf("\nKet qua la: %d",timminle(arr,5));
	
}
