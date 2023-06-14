#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define maxlen 7

void incauhinh();


//chuc nang 1:
int N = 2 ;

void nhapN(){
    printf("Nhap 3 <= N <= 7:  ");
    scanf("%d",&N);
    while (N > 7 || N < 3){
        printf("Nhap lai N, 3 <= N <= 7: ");
        scanf("%d",&N);
    }
}

//chuc nang 2:
int ar[maxlen][maxlen];


int game(){
    if(N == 2){
        printf("\nHay nhap N truoc: 3 <= N <- 7 :  ");
        scanf("%d",&N);
        while (N > 7 || N < 3){
            printf("Nhap lai N, 3 <= N <= 7: ");
            scanf("%d",&N);
        }
    }
    for(int i= 0; i < N;i++){
        for(int j= 0; j < N; j++){
            printf("Nhap so cho vi tri [%d][%d]: ", i+1,j+1);
            scanf("%d",&ar[i][j]);
            fflush(stdin);
            if(ar[i][j] < 0){
                printf("Nhap lai so cho vi tri [%d][%d]: ", i+1,j+1);
                scanf("%d",&ar[i][j]);
            }
        }
    }
    
}


//chuc nang 3:
char rb[1000];
int check2 = 0;
    

void dichuyen(int *VTx, int *VTy){
    fflush(stdin);
    char C;
    do {
        char x;
        printf("\n (1) 'U' di chuyen o trong len tren.");
        printf("\n (2) 'D' di chuyen o trong xuong duoi.");
        printf("\n (3) 'L' di chuyen o trong sang trai.");
        printf("\n (4) 'R' di chuyen o trong sang phai.");
        printf("\n (5) 'Q' thoat khoi chuc nang 3.");
        printf("\nNhap ki tu cua ban: " );
        scanf("%c", &C);
        fflush(stdin);
        while(C != 'U' && C!= 'D' && C!= 'L' && C!='R' && C!= 'Q'){
            printf("Khong hop le! Nhap lai ki tu cua ban: " );
            fflush(stdin);
            scanf("%c", &C);
        }
        switch (C) {
            case 'R':
                if ( *VTx == N-1) {
                    printf("Khong the di chuyen sang phai:\n");
                }
                else {
                    ar[*VTy][*VTx] = ar[*VTy][*VTx+1];
                    ar[*VTy][*VTx+1] = 0;
                    *VTx++;
                    printf("\nChuyen thanh cong!\n");
                    incauhinh();
                }
                break;
            case 'L':
                if ( *VTx == 0) {
                    printf("Khong the di chuyen sang trai:\n");
                }
                else {
                    ar[*VTy][*VTx] = ar[*VTy][*VTx-1];
                    ar[*VTy][*VTx-1] = 0;
                    *VTx--;
                    printf("\nChuyen thanh cong!\n");
                    incauhinh();
                }
                break;
            case 'D':
                if ( *VTy == N-1) {
                    printf("Khong the di chuyen xuong duoi:\n");
                }
                else {
                    ar[*VTy][*VTx] = ar[*VTy+1][*VTx];
                    ar[*VTy+1][*VTx] = 0;
                    *VTy++;
                    printf("\nChuyen thanh cong!\n");
                    incauhinh();
                }
                break;
            case 'U':
                if ( *VTy == 0) {
                    printf("Khong the di chuyen len tren:\n");
                }
                else {
                    ar[*VTy][*VTx] = ar[*VTy-1][*VTx];
                    ar[*VTy-1][*VTx] = 0;
                    *VTy--;
                    printf("\nChuyen thanh cong!\n");
                    incauhinh();
                }
                break;
            case 'Q':
                printf("Bye!");
                break;
            }
    } while (C != 'Q');

        rb[check2] = C;
        check2 ++;
}

//chuc nang 4:

void rollback(int *VTx, int *VTy){
    int x;
    char C;
    printf("\nNhap vao so buoc can rollback: ");
    scanf("%d", &x);
    for(int i = check2-1; i > check2 -1-x;i--){
        switch (C) {
            case 'L':
                ar[*VTy][*VTx] = ar[*VTy][*VTx+1];
                ar[*VTy][*VTx+1] = 0;
                *VTx+1;
                printf("\nChuyen thanh cong!\n");
                incauhinh();
            case 'R':
                    ar[*VTy][*VTx] = ar[*VTy][*VTx-1];
                    ar[*VTy][*VTx-1] = 0;
                    printf("\nChuyen thanh cong!\n");
                    incauhinh();
            case 'D':
                    ar[*VTy][*VTx] = ar[*VTy+1][*VTx];
                    ar[*VTy+1][*VTx] = 0;
                    printf("\nChuyen thanh cong!\n");
                    incauhinh();
            case 'U':
                    ar[*VTy][*VTx] = ar[*VTy-1][*VTx];
                    ar[*VTy-1][*VTx] = 0;
                    printf("\nChuyen thanh cong!\n");
                    incauhinh();
        }

    } 
}

//chuc nang 5:
void incauhinh(){
    printf("\n");
    for(int i=0; i < 2*N +1; i++){
        printf("*");
    }
    printf("\n*");
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
                printf("%d*",ar[i][j]);
        }
        printf("\n*");
    }
    for(int i=0; i < 2*N; i++){
        printf("*");
    }
    printf("\n");
}

int main(){
	int n;
	char n2;
    int *VTx, *VTy;
	while(1){
	printf("\n*--------------------------------------------------*\n");
	printf("*  [ 1 ] Nhap so N                                 *\n");
	printf("*  [ 2 ] Nhap so cho cac o trong                   *\n");
	printf("*  [ 3 ] Nhap thao tac di chuyen U, D, L, R        *\n");
	printf("*  [ 4 ] Nhap so luong can rollback                *\n");
	printf("*  [ 5 ] In cau hinh hien taij cua game            *\n");
	printf("*  [ 6 ] Thoat                                     *\n");
	printf("*--------------------------------------------------*\n");
	printf("\n\n Nhap lua chon cua ban:   ");
	scanf("%d",&n);
		system("cls");
	if(n == 6){
		printf("Good Bye!");
        break;
	}else if(n < 1 || n > 6){
			printf("\nLua chon khong hop le nhap lai: ");
	}else{
	switch(n){
		case 1:
            nhapN();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 2:
            game();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 3:
            for(int i=0; i < N; i++){
                for(int j=0; j < N; j++){
                    if(ar[i][j] == 0){
                        *VTy = i;
                        *VTx = j;
                    }
                }
            }

            dichuyen(&VTx,&VTy);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 4:
            rollback(&VTx,&VTy);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 5:
            incauhinh();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
	}
    }
}
getch();
}