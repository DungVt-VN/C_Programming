#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int check=0 ,slh= 0;
typedef struct{
	int classid;
	char coursename[30];
	char room[10];
	int day;
	char slots[10];
}classroom;
//bai 1
void bosunglophoc(classroom a[]){
	check = check + 1;
	int static ctn;
	int cl;
	ctn = slh ;
	if(check ==1 ){
		printf("\nNhap so lop hoc can bo sung: ");
		scanf("%d",&cl);
		slh += cl;
		if(cl < 1 || cl >200){
			printf("\nNhap lai so lop hoc can o sung, toi da 200 lop: ");
			scanf("%d",&cl);
		}
	}else {
		printf("\nNhap so lop hoc can them: ");
		scanf("%d",&cl);
		slh += cl;
		if(slh > 200){
			slh -= cl;
			printf("\nSo lop hoc them duoc toi da la: %d", 200-slh);
			printf("\nNhap lai so lop hoc can them :");
			scanf("%d",&cl);
		}
	slh += cl;	
	}
	for(int i=ctn; i< slh;i++){
		printf("\nNhap ma lop hoc: ");
	    scanf("%d",&a[i].classid);
	    fflush(stdin);
	    printf("\nNhap ten mon hoc:");
	    gets(a[i].coursename);
	    printf("\nNhap ten phong: ");
	    gets(a[i].room);
	    printf("\nNhap ngay hoc trong tuan: ");
	    scanf("%d",&a[i].day);
	    fflush(stdin);
	    while(1){
	    	if(a[i].day > 7 || a[i].day <2){
	    	    printf("\nThu khong hop le, nhap lai: ");
	    	    scanf("%d",&a[i].day);
	        }else break;
		}
		fflush(stdin);
//nhap so tiet
		int dai, check2 = 0,d ,b,check3;
	    printf("\nNhap tiet hoc: ");
        gets(a[i].slots);
        dai = strlen(a[i].slots);
        for(int j=0;j<dai ; j++){
        	if(a[i].slots[j] == '-'){
			check2++;
			check3 = j;
			}
		}
		do{
		if(check3=2){
			d = ((int)a[i].slots[0]-48)*10+(int)(a[i].slots[1]-48);
			b = ((int)a[i].slots[4]-48)+10+((int)a[i].slots[3]-48);
		}else if(check3 == 1|| dai == 3){
			d = (int)a[i].slots[0]-48;
			b = (int)a[i].slots[2]-48;
		}else if(check3 == 1|| dai== 3){
			d = (int)a[i].slots[0]-48;
			b = ((int)a[i].slots[3]-48)*10+(a[i].slots[2]-48);
		}else if(d >b){
			printf("\nLoi nhap lai tiet co dang a-b, a<b, voi a,b thuoc [1,12]:");
			gets(a[i].slots);
		}
		else{
		printf("\nLoi nhap lai tiet co dang a-b, a<b, voi a,b thuoc [1,12]:");
		gets(a[i].slots);
		}
	    }while( d < b);
	    printf("%dai %d %d" ,d,b,dai);
    }
}
//bai 2

void inthongtin(classroom a[]){
	printf("%-10s%-30s%-10s%-5s%-10s\n","Ma lop","Ten mon hoc","Ten phong","Thu","Tiet hoc");
	for(int i= 0 ;i<slh ;i++){
		printf("%-10d%-30s%-10s%-5d%-10s",a[i].classid,a[i].coursename,a[i].room,a[i].day,a[i].slots);
	}
}

//bai3
void timkiem(classroom a[]){
    char lopid[10];
    int check=0;
	printf("\nNhap ma lop hoc can tim kiem: ");
	gets(lopid);
	printf("%-10s%-30s%-10s%-5s%-10s\n","Ma lop","Ten mon hoc","Ten phong","Thu","Tiet hoc");
	for(int i= 0 ;i <=slh;i++){
		if(strcmp(lopid,a[i].room) == 0){
			check ++ ;
			printf("%-10d%-30s%-10s%-5d%-10s",a[i].classid,a[i].coursename,a[i].room,a[i].day,a[i].slots);
		}
	}
	if(check == 0) printf("\nKhong ton tai phong %s trong danh sach",lopid);
}

int main(){
	int n;
	char batki;
	classroom a[200];
	while(1){
	printf("*--------------------------------------------*\n");
	printf("* [1] Bo sung lop hoc                        *\n");
	printf("* [2] In thong tin cac lop hoc               *\n");
	printf("* [3] Tim kiem cac lop hoc                   *\n");
	printf("* [4] Thoat                                  *\n");
	printf("*--------------------------------------------*\n");
	printf("\n\nNhap lua chon cua ban ... :");
	scanf("%d",&n);
	if(n == 4) 
	    break;
	system("cls");
	switch(n){
		case 1:
			bosunglophoc(a);
			printf("\nChon phim bat ki de ve menu...");
			scanf("%s",&batki);
			system("cls");
			continue;
		case 2:
			inthongtin(a);
			printf("\nChon phim bat ki de ve menu...");
			scanf("%s",&batki);
			system("cls");
			continue;
		case 3:
			timkiem(a);
			printf("\nChon phim bat ki de ve menu...");
			scanf("%s",&batki);
			system("cls");
			continue;
	}
	}
	getch();
}
