#include<stdio.h>
#include<math.h>
int giaithua(int gt){
	if(gt==0)
	return 1;
	else {
		return gt*giaithua(gt-1);
	}
}
int main(){
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	printf("%d",giaithua(n));
	return 0;
}
