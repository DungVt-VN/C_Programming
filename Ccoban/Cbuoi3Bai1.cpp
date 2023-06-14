#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int N;
//cn1
int nhapN(){
	fflush(stdin);
	printf("\nNhap vao so computers: ");
	scanf("%d",&N);
	while(N < 1 || N >= 100 ){
		printf("\nVui long nhap so computers lon hon 0 va nho hon 100: ");
		scanf("%d",&N);
	}
	
	printf("\nSo N hop le vua nhap la: %d",N);
}

//cn2
void updateID(int a[]){
	int n;
	printf("\nNhap ID cua may can cap nhat: ");
	scanf("%d",&n);
	fflush(stdin);
	while( n < 1 || n > N){
		printf("\nID cua may khong hop le! Nhap lai ID: ");
		scanf("%d",&n);
	}
	fflush(stdin);
	printf("Nhap so core moi cua may %d: ",n);
	scanf("%d",&a[n-1]);
	while( a[n-1] != 2 && a[n-1]!=4 && a[n-1]!=6 && a[n-1]!=8 && a[n-1]!=10){
		printf("\nSo cua core khong hop he! Nhap lai: ");
		scanf("%d",&a[n-1]);
	}
	for(int i=n; i<=N-1 ; i++){
		printf("Nhap so core moi cua may %d: ",i+1);
		scanf("%d",&a[i]);
		while( a[i] != 2 && a[i]!=4 && a[i]!=6 && a[i]!=8 && a[i]!=10){
			printf("\nSo cua core khong hop he! Nhap lai: ");
			scanf("%d",&a[i]);
		}
	}
	
	for(int j= 0; j<= N-1;j++){
		printf("\n%d     %d",j+1,a[j]);
	}
}

int main(){
	int n;
	int a[100];
	char n2;
	while(1){
	printf("\n*=========Program for management computers=========*\n");
	printf("*                                                  *\n");
	printf("*  [ 1 ] Number of Computers:                      *\n");
	printf("*  [ 2 ] Update number of cores:                   *\n");
	printf("*  [ 3 ] Update Ram info:                          *\n");
	printf("*  [ 4 ] Search:                                   *\n");
	printf("*  [ 5 ] Quit                                      *\n");
	printf("*                                                  *\n");
	printf("*--------------------------------------------------*\n");
	printf("\n\n Nhap lua chon cua ban:   ");
	scanf("%d",&n);
		system("cls");
	if(n == 5){
		break;
	}else if(n < 1 || n > 5){
			printf("\n\nLua chon khong hop le nhap lai:\n\n ");
	}else{
	switch(n){
		case 1:
 			nhapN();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 2:
			updateID(a);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 3:

			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 4:

			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
	}
    }
}
getch();
}
