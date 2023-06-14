#include<stdio.h>

int mu(int n, int a){
	if(n == 0)
		return 1;
	else 
		return a*mu(n-1,a);
}
int main(){
	int a, n;
	printf("Nhap a va n: ");
	scanf("%d %d",&a ,&n);
	printf("\nKet qua la: %ld", mu(n,a));
}
