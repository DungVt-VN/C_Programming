#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int check = 0;
int check2 = 0;
//b

void getN(int* N){
	check++;
	printf("\nNhap so N (4 <= N <= 10): ");
	scanf("%d",N);
	while( *N < 4 || *N > 10){
		printf("\nSo N khong hop le! Nhap lai N: ");
		scanf("%d",N);
	}
}
//c 
void getArray(float X[], float Y[], int N){
	check2++;
	for(int i = 0; i < N ;i++){
		printf("\nNhap x[%d] va y[%d]: ",i+1,i+1);
		scanf("%d",&X[i]);scanf("%d",&Y[i]);
	}
}

//f
int checkArray(float X[], float Y[], int N){
	int check3 = 0;
	for(int i = 0 ;i < N;i++){
		if( X[i] == X[i+1] || Y[i] == Y[i+1])
			check3++;
	}
	if(check3 == N-1){
		return 1;
	}else
		return 0;
}

int main(){
	int n;
	char n2;
	int N;
	float X[1000],Y[1000];
	while(1){  
	printf("\n*----------------------------------------------------------------------------------*\n");
	printf("*  [ 1 ] Nhap vao so N (4 <= N <= 10)                                              *\n");
	printf("*  [ 2 ] Nhap vao mang N phan tu la cac diem co toa do (x, y)                      *\n");
	printf("*  [ 3 ] Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?*\n");
	printf("*  [ 4 ] Thoat                                                                     *\n");
	printf("*----------------------------------------------------------------------------------*\n");
	printf("\n\n Nhap lua chon cua ban:   ");
	scanf("%d",&n);
		system("cls");
	if(n == 4){
		printf("\nBYE");
		break;
	}else if(n < 1 || n > 4){
			printf("\nLua chon khong hop le nhap lai: ");
	}else{
	switch(n){
		case 1:
			getN(&N);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 2:
			if(check == 0){
				printf("\nVui long nhap N tai chuc nang 1 de tiep tuc: ");
			}else
				getArray(X,Y,N);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 3:
			if(check == 0 || check2 == 0){
				printf("\nHay thuc hien chuc nang 1 va 2. ");
			}else{
				printf("\n3 is done!");
				printf("\n%d",checkArray(X,Y,N));
			}
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
			}		
    	}
    }
getch();
}
