#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int N,H,C,A,B;

typedef struct information{
	char name[256];
	int year = 0;
	char brand[256];
}information;

information S[100][100];

//cau a;

void parking() {
	fflush(stdin);
	printf("\nHay nhap so o do xe: ");
	scanf("%d",&N);
	printf("\nNhap so cot de dau xe: ");
	scanf("%d",&C);
	while(N >= 100 || N%C != 0 || C > N) {
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

void input() {
	static int a = 0,b = H-1;
	char n,n1 = '_';
	fflush(stdin);
	while(1) {
		if(S[0][C-1].year != 0 ) {
			printf("\nKhong con cho trong!\n");
			break;
		}else {
			printf("\nNhap bien so xe: ");
			scanf("%s",&S[b][a].name);
			printf("\nNhap nam san xuat: ");
			scanf("%d",&S[b][a].year);
			printf("\nNhap hang san xuat: ");
			scanf("%s",&S[b][a].brand);
			fflush(stdin);
			printf("\nBan muon nhap them xe? Nhap Y/N:  ");
			scanf("%c",&n);
			A = a;
			B = b;
			if(b == 0) {
				a ++;
			  	b = H;
		 		}
			b--;
		}
		if(n == 'y' || n == 'Y') {
			continue;
		}else 
			break;
	}
	for(int i = 0 ; i < H ; i ++) {
		for(int j = 0 ; j < C; j++) {
			if(S[i][j].year==0) {
				printf("%10c",n1);
			}else 
				printf("%10s",S[i][j].name);
		}
		printf("\n");
	}
}

//cau c;

void search(){
	char bsx[100];
	fflush(stdin);
	printf("\nNhap bien so xe can tim: ");
	gets(bsx);
	for(int i = 0 ; i < H ; i ++) {
		for(int j = 0 ; j < C; j++) {
			if(strcmp(S[i][j].name, bsx)==0){
				printf("\nXe dang o hang %d cot %d.\nNam san xuat: %d.\nThuoc hang: %s ",i+1,j+1,S[i][j].year,S[i][j].brand);
			}
		}
	}
	
}


//cau d;

void caud(){
	char bsx[100];
	char n1 = '_';
	information tmp1;
	printf("\nTruoc khi lay xe:\n");
	for(int i = 0 ; i < H ; i ++) {
		for(int j = 0 ; j < C; j++) {
			if(S[i][j].year==0) {
				printf("%10c",n1);
			}else 
				printf("%10s",S[i][j].name);
		}
		printf("\n");
	}
	fflush(stdin);
	printf("\nNhap bien so xe can lay ra: ");
	gets(bsx);
	for(int i = 0 ; i < H ; i ++) {
		for(int j = 0 ; j < C; j++) {
			if(strcmp(S[i][j].name, bsx)==0){
				information tmp = S[i][j];
				S[i][j] = S[B][A];
				S[B][A] = tmp1;
				
			}
		}
	}
	printf("\nSau khi lay xe:\n");
	for(int i = 0 ; i < H ; i ++) {
		for(int j = 0 ; j < C; j++) {
			if(S[i][j].year==0) {
				printf("%10c",n1);
			}else 
				printf("%10s",S[i][j].name);
		}
		printf("\n");
	}
}

int main() {
	int n, N , C, H;
	char n2;
	while(1) {
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
	if(n == 5) {
		printf("\nThoat chuong trinh!");
		break;
	}else if(n < 1 || n > 5) {
			printf("\nLua chon khong hop le nhap lai: ");
	}else{
	switch(n) {
		case 1:
			parking();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 2:
			input();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 3:
			search();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 4:
			caud();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
	}
    }
}
getch();
}
