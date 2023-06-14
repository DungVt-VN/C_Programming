#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int N,H,C;

typedef struct information{
	char name[256];
	int year = 0;
	char brand[256];
}information;

information S[100][100];

//cau a;

void parking(){
	fflush(stdin);
	printf("\nHay nhap so o do xe: ");
	scanf("%d",&N);
	printf("\nNhap so cot de dau xe: ");
	scanf("%d",&C);
	while(N >= 100 || N%C != 0 || C > N){
		printf("\nSo o va so cot khong hop le!\n\nXin nhap lai du lieu:\n\n");
		printf("\nHay nhap so o do xe: ");
		scanf("%d",&N);
		printf("\nNhap so cot de dau xe: ");
		scanf("%d",&C);
	}
	printf("\nSo o la: %d",N);
	printf("\nSo cot la: %d",C);
	H = N/C;
	printf("\nSo hang la: %d",H);
}

//cau b;

void input(information S[100][100]){
	static int a = 0,b = H-1;
	char n;
	fflush(stdin);
	while(1){
		a++;
		b--;
		if(S[H-1][C-1].year != 0 ){
			printf("\nKhong con cho trong!");
			}
		printf("\nNhap bien so xe: ");
		scanf("%s",&S[a][b].name);
		printf("\nNhap nam san xuat: ");
		scanf("%d",&S[a][b].year);
		printf("\nNhap hang san xuat: ");
		scanf("%s",&S[a][b].brand);
		fflush(stdin);
		printf("\nBan muon nhap them xe? Nhap Y/N");
		scanf("%c",&n);
		if(a == C) a=0;
		if(b == 0) b = H-1; 
		if(n == 'y' || n == 'Y') {
			continue;
		}else break;
	}
	for(int i = 0 ; i < C ; i ++){
		for(int j = H-1 ; j >= 0; j--){
			if(S[j][i].year==0){
				printf("_");
			}else 
				printf("%s",S[j][i].name);
		}
		printf("\n");
	}
}

int main(){
	int n, N , C, H;
	char n2;
	while(1){
	printf("\n*=========Program for management car parking=========*\n");
	printf("*  [ 1 ] Numbers of Parking lot & columns:           *\n");
	printf("*  [ 2 ] Insert new car:                             *\n");
	printf("*  [ 3 ] Search:                                     *\n");
	printf("*  [ 4 ] Remove a car:                               *\n");
	printf("*  [ 5 ] Quit                                        *\n");
	printf("*====================================================*\n");
	printf("\n\n Nhap lua chon cua ban:   ");
	scanf("%d",&n);
		system("cls");
	if(n == 5){
		printf("\nThoat chuong trinh!");
		break;
	}else if(n < 1 || n > 5){
			printf("\nLua chon khong hop le nhap lai: ");
	}else{
	switch(n){
		case 1:
			parking();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 2:
			input(S);
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
