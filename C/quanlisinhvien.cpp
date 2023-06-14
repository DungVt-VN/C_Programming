#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int sl = 0;
float avg = 0;
typedef struct{
	char name[30];
	char id[12];
	char address[30];
	float GPA;
}student;

//bai1
void sinhvien( student a[]){
	static int check1=0;
	static float sum = 0;
	check1++;
	int check3=0;
	int slsv1,slsv2;
	slsv2 = sl;
	if(check1 == 1){
		printf("\nNhap so luong sinh vien: ");
		scanf("%d",&slsv1);
		fflush(stdin);
		while(slsv1 <= 0){
			printf("\nSo luong sinh vien loi nhap lai so luong sinh vien: ");
			scanf("%d",&slsv1);
			fflush(stdin);
		};
		sl = slsv1;
	}else{
		printf("Nhap so luong sinh vien moi: ");
		scanf("%d",&slsv1);
		fflush(stdin);
		while(slsv1 <= 0){
			printf("\nSo luong sinh vien loi nhap lai so luong sinh vien: ");
			scanf("%d",&slsv1);
			fflush(stdin);
		};
		sl += slsv1;
	}
	for(int i = slsv2 ; i < sl; i++){
		printf("\nNhap ten sinh vien %d:  ",i+1);
		gets(a[i].name);
		
		printf("\nNhap ma so sinh vien: ");
		gets(a[i].id);
        for(int j= 0; j<i;j++){
        	if(strcmp(a[i].id,a[j].id)==0){
        		printf("\nMa so sinh vien error, nhap lai: ");
        		gets(a[i].id);
        		j=-1;
			}
		}
		
		printf("\nNhap que quan sinh vien: ");
		gets(a[i].address);
		
		printf("\nNhap GPA: ");
		scanf("%f",&a[i].GPA);
		fflush(stdin);
		while(a[i].GPA<0 || a[i].GPA >4){
			    printf("\nGPA khong dung, nhap lai GPA: ");
                scanf("%f",&a[i].GPA);
        }
        fflush(stdin);
		sum +=a[i].GPA;
		avg = float(sum/sl);
	}
};

//bai 2

void thongtin(student a[]){
	if(sl == 0){
    printf("\nDanh sach trong. ");
    }else{
	    printf("\n*%-5s*%-30s*%-12s*%-30s*%-5s","STT","Ten","MSSV","QueQuan","GPA");
	    for(int i= 0; i<sl; i++){
		printf("\n*%-5d*%-30s*%-12s*%-30s*%-5.2f",i+1,a[i].name,a[i].id,a[i].address,a[i].GPA);
	    }
	    printf("\n\n\nDiem trung binh cua sinh vien la: %0.3f",avg);
    }
}

//bai 3

void search1(student a[]){
	char tk[1000];
	int check4=0;
	fflush(stdin);
	printf("\nNhap ma so sinh vien can tim: ");
	gets(tk);
	for(int i=0;i<sl;i++){
		if(strcmp(a[i].id,tk)==0){
			check4++;
		}
	}
	if(check4 == 0){
		printf("\nKhong tim thay sinh vien.");
	}else{
		printf("\n*%-5s*%-30s*%-12s*%-30s*%-5s","STT","Ten","MSSV","QueQuan","GPA");
		for(int i=0;i<sl;i++){
		    if(strcmp(a[i].id,tk)==0){
		    printf("\n*%-5d*%-30s*%-12s*%-30s*%-5.2f",i+1,a[i].name,a[i].id,a[i].address,a[i].GPA);
		    }
	    }
	}
}

//bai 4 

void search2(student a[]){
	char tk2[1000];
	int check5=0;
	fflush(stdin);
	printf("\nNhap que quan sinh vien: ");
	gets(tk2);
	strlwr(tk2);
	printf("\n*%-5s*%-30s*%-12s*%-30s*%-5s","STT","Ten","MSSV","QueQuan","GPA");
	for(int i=0; i<sl ;i++){
		strlwr(a[i].address);
		if(strcmp(tk2,a[i].address)==0 && a[i].GPA > avg){
			printf("\n*%-5d*%-30s*%-12s*%-30s*%-5.2f",i+1,a[i].name,a[i].id,a[i].address,a[i].GPA);
			check5++;
		}
	}
	if(check5 == 0){
			printf("\nKhong tim thay sinh vien: ");
		}
}

//bai5

void sapxep(student a[]){
	student cmp;
	for(int i= 0;i<sl-1 ; i++){
		for(int j=i ; j<sl; j++){
			if(a[j].GPA > a[i].GPA ){
				cmp = a[i];
				a[i] = a[j];
				a[j] = cmp;
			}
		}
	}
	printf("\n*%-5s*%-30s*%-12s*%-30s*%-5s","STT","Ten","MSSV","QueQuan","GPA");
	for(int i= 0; i<sl; i++){
		printf("\n*%-5d*%-30s*%-12s*%-30s*%-5.2f",i+1,a[i].name,a[i].id,a[i].address,a[i].GPA);
	}
}

int main(){
	int n;
	char n2;
	student st[10000];
	while(1){
	printf("\n*--------------------------------------------------*\n");
	printf("*  [ 1 ] Nhap thong tin sinh vien                  *\n");
	printf("*  [ 2 ] In thong tin cac sinh vien                *\n");
	printf("*  [ 3 ] Tim kiem theo ma so sinh vien             *\n");
	printf("*  [ 4 ] Tim kiem theo GPA va que quan             *\n");
	printf("*  [ 5 ] Sap xep theo GPA                          *\n");
	printf("*  [ 6 ] Thoat                                     *\n");
	printf("*--------------------------------------------------*\n");
	printf("\n\n Nhap lua chon cua ban:   ");
	scanf("%d",&n);
		system("cls");
	if(n == 6){
		break;
	}else if(n < 1 || n > 6){
			printf("\nLua chon khong hop le nhap lai: ");
	}else{
	switch(n){
		case 1:
			sinhvien(st);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 2:
			thongtin(st);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 3:
			search1(st);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 4:
			search2(st);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 5:
			sapxep(st);
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
	}
    }
}
getch();
}
