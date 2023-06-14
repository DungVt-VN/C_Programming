#include<stdio.h>
#include<string.h>
int trang11(int a[], int b[], int N){
	int check0 = 0;
	for(int i= 0 ; i< N; i++){
		if(a[i] != b[i])
			check0++;
	}
	if(check0 == 0){
		return 1;
	}else return 0;
}

void trang19(char c[], char d, char e){
	fflush(stdin);
	int a = strlen(c);
	for(int i = 0; i < a;i++){
		if(c[i] == d)
			c[i] = e;
	}
	printf("\nString sau khi thay doi la:  ");
	puts(c);
}

void trang25(double f){
	int a;
	double b;
	a = f/1;
	b = f - a*1.0;
	printf("\nPhan nguyen cua so la: %d",a);
	printf("\nPhan thap phan cua so la: %0.2lf",b);	
}

void trang33(){
	float a,b,S,P;
	printf("\nNhap so do 2 canh: ");
	scanf("%f",&a);
	scanf("%f",&b);
	S = a*b;
	P = (a+b)*2;
	printf("\nDien tich hinh chu nhat la: %0.2f",S);
	printf("\nChu vi hinh chu nhat la: %0.2f",P);
}


void trang35(){
	
}

int main(){
//bai trang 11
	int N,a[1000],b[1000];
	printf("Nhap chieu dai mang: ");
	scanf("%d",&N);
	printf("\nNhap mang a: ");
	for(int i = 0; i < N ;i++){
		scanf("%d",&a[i]);
	}
	printf("\nNhap mang b: ");
	for(int i = 0; i < N ;i++){
		scanf("%d",&b[i]);
	}
	printf("\nGia tri tra ve la: %d",trang11(a,b,N));

//bai trang 19
    fflush(stdin);
	char c[1000], d ,e;
	printf("\nNhap string: ");
	gets(c);
	printf("\nNhap ki tu can thay the: ");
	scanf("%c",&d);
	fflush(stdin);
	printf("\nNhap ki tu thay the: ");
	scanf("%c",&e);
	fflush(stdin);	
	trang19(c,d,e);

//bai trang 25
	double f;
	printf("\nNhap so thap phan bat ki: ");
	scanf("%lf",&f);
	trang25(f);

//bai trang 33
    trang33();

}
