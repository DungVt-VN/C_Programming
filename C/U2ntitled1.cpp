#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int N;
float queue[10][100];
int rear[] = {0,0,0,0,0,0,0,0,0,0}, arraySize;
float check[1000];
//y a
void nhapN(){
    printf("\nNhap gia tri N duong > 10 : ");
    scanf("%d",&N);
    while(N <=0 || N >= 10){
        printf("\nNhap lai N: ");
        scanf("%d",&N);
    }
    arraySize = N;
}

//y b

int caub(){
    int i , i1;
    float j, j1;
    int check0 = 0;
    printf("\nNhap i, j: ");scanf("%d %f",&i,&j);
    if(i >= N || j <=0) check0 ++;
    for(int k = 0; k < rear[i]; k++){
        if(queue[i][k] == j) check0++;
    }
    if(check0 != 0){
        return 0;
    }else{
        printf("\nConfirm i, j: ");
        scanf("%d %f",&i1,&j1);
        while(i1 != i || j1 != j){
            printf("\nConfirm i, j: ");
            scanf("%d %d",&i1,&j1);
        }
        queue[i][rear[i]] = j;
        rear[i] ++;
    }
    for(int k = 0; k < rear[i] ;k++){
        printf("%0.2f  ",queue[i][k]);
    }
}
//y C

int cauC(){
    int i;
    printf("\nNhap i: ");
    scanf("%d",&i);
    while(i >= N){
        printf("\nNhap lai i < %d: ",N);
        scanf("%d",&i);
    }
    for(int k = 0; k < rear[i] ; k++){
        if(rear[i] == 0) printf("\nHang doi rong!");
        else printf("%0.2f --> ",queue[i][k]);
    }
    printf("NULL");
}
//y D

void UCV(){
    static int i = 0;
    
}

int cauD(){
    for(int m = 0; m < N; m++){
        for(int n = 0; n < rear[m]; n++){

        }
    }
}

int main(){
	int n;
	char n2;
	while(1){
        printf("\n*======Nhap vao so bat ky de thuc hien chuc nang=======*\n");
        printf("*  [ 1 ] Nhap vao gia tri N (so luong cac queue)       *\n");
        printf("*  [ 2 ] Nhap (i, j) de chen j vao queue i (i < N)     *\n");
        printf("*  [ 3 ] Hien thi cac phan tu trong queue i            *\n");
        printf("*  [ 4 ] Kiem tra va xoa phan tu trung lap (neu co)    *\n");
        printf("*  [ 5 ] Thoat                                         *\n");
        printf("*------------------------------------------------------*\n");
        printf("\n\n Nhap lua chon cua ban:   ");
        scanf("%d",&n);
            system("cls");
        if(n == 5){
            printf("\nGood bye!\n");
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
                    caub();
                    printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
                    scanf("%s",&n2);
                    system("cls");
                    continue;
                case 3:
                    cauC();
                    printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
                    scanf("%s",&n2);
                    system("cls");
                    continue;
                case 4:
                    cauD();
                    printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
                    scanf("%s",&n2);
                    system("cls");
                    continue;
            }
        }
    }
getch();
}

