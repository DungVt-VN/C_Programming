#include<stdio.h>

float timphantuY(int k, float X[],float lambda);

int main(){
	int n;
	float X[1000];
	float lambda;
//a
	printf("Nhap so n tu ban phim 1 <= n <= 6: ");
	scanf("%d",&n);
	while(n < 1 || n >6 ){
		printf("\nSo n phai lon hon bang 1 va nho hon bang 6, hay nhap lai n: ");
		scanf("%d",&n);
	}
//b 
	printf("\nNhap n so tu ban phim: ");
	for(int i = 0 ; i < n ; i++){
		scanf("%f",&X[i]);
	}
//c 
	printf("Nhap so lambda tu ban phim 0 < lambda < 1: ");
	scanf("%f",&lambda);
	while(lambda <= 0 || lambda >=1 ){
		printf("\nSo lambda 0 < lambda < 1, hay nhap lai lambda: ");
		scanf("%f",&lambda);
	}
//d 
	float Y[1000];
	for(int k = 0; k < n; k++){
		Y[k] = timphantuY(k,X,lambda);
	}
	printf("\nPhan tu trong mang Y la: ");
	for(int k = 0; k< n; k++){
		printf("%0.2f  ",Y[k]);
	}
//e 
	float a;
	printf("\nNhap vao so thuc a bat ki: ");
	scanf("%f",&a);
	printf("\nSo thuc vua nhap la: %0.2f",a);
//f 
    lambda = 0.4;
	for(int k = 0; k < n; k++){
		Y[k] = timphantuY(k,X,lambda);
	}
	printf("\nPhan tu cuoi trong mang Y la: ");
		printf("%0.2f  ",Y[n-1]);
}

float timphantuY(int k, float X[],float lambda){
	if(k == 0) 
		return X[0];
	else 
		return (1 - lambda)*timphantuY(k -1,X,lambda) + lambda*X[k];
}

