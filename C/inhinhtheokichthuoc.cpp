#include<stdio.h>

int main(){
	int a, b;
	printf("Nhap a, b: ");
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		for(int j = 0; j <b;j++){
			printf("* ");
		}
		printf("\n");
	}
}
