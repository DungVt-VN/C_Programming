#include<stdio.h>

int gt(int n){
	if(n == 0)
		return 1;
	else return n*gt(n-1);
}

int main(){
	int n;
	printf("Nhap n >= 0: ");
	scanf("%d",&n);
	printf("\nGiai thua la: %d", gt(n));
}
