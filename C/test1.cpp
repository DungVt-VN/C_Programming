#include <stdio.h>

int main(){
	int n,A[100];
	int dem = 0;
	printf("Nhap n: ");
	scanf("%d",&n);

	while(n != 0){
		A[dem] = n%2;
		n = n/2;
		dem ++;
	}
	for(int i = dem - 1; i >= 0 ; --i){
		printf("%d", A[i]);
	}
}