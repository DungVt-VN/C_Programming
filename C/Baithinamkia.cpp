#include<stdio.h>
#include<conio.h>
#include<string.h>

int num;

typedef struct{
	char name[30];
	struct{
		float T,L,H,avg;
	}diem;
}student;

//bai 1

void Nhapdanhsach(student a[]){
	    int i=0;
	do{ 
	    num = i+1;
		printf("Nhap ten sinh vien %d: ",i+1);
		fflush(stdin);
		gets(a[i].name);
		if(strlen(a[i].name)==0){
			break;
		}else{
		printf("\nNhap diem Toan Ly Hoa cua %s :",a[i].name);
		scanf("%f%f%f",&a[i].diem.T,&a[i].diem.L,&a[i].diem.H);
		while(a[i].diem.T>10 || a[i].diem.T<0 || a[i].diem.L>10 || a[i].diem.L<0|| a[i].diem.H>10 || a[i].diem.H<0){
			printf("\nDiem error, nhap lai diem: ");
			scanf("%f%f%f",&a[i].diem.T,&a[i].diem.L,&a[i].diem.H);
		}
		a[i].diem.avg = a[i].diem.T + a[i].diem.H + a[i].diem.L ;
		i++;
		}
	}while(1);
}
//bai 2

void dstrungtuyen(student a[]){
	float dc;
	int dem2= 0;
	printf("\nNhap diem chuan : ");
	scanf("%f",&dc);
	do{
	if(dc<0 ||dc>30){
		printf("\nDiem khong hop le nhap lai:");
		scanf("%f",&dc);
	}else break;
}while(1);
	fflush(stdin);
	printf("\nDanh sach thi sinh trung tuyen la:");
		printf("\n------------------------------------");
	for(int i=0; i<num ; i++){
		if(a[i].diem.avg >= dc && a[i].diem.T!=0 && a[i].diem.L!=0 && a[i].diem.H!=0 ){
			printf("\nTen sinh vien:  %20s",a[i].name);
			printf("\n------------------------------------\n\n");
			dem2 ++;
		}
	}
	if(dem2 ==0){
		printf("\nKhong co thi sinh trung tuyen.\n------------------------------------\n\n");
	}
}
//bai 3

void diemcaonhat(student a[]){

float max;
int check;
max = 0; 
for(int j=0 ;j<num ; j++){
	if(a[j].diem.avg > max ){
		max = a[j].diem.avg;
		check = j;
	}
}
for(int j=0 ;j<num ; j++){
	if(a[j].diem.avg == a[check].diem.avg ){
		printf("\nThu khoa la : %s \n\n",a[j].name);
	}
}
}

//bai 4

void timdiemchuan(student a[]){
	int ct,dem4=0;
	student tmp,change[100];
	for(int i=0 ;i<num;i++){
		for(int j=i+1;j<num-1;j++){
			if(a[j].diem.avg > a[i].diem.avg){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	printf("\nNhap chi tieu: ");
	scanf("%d",&ct);
	
	for(int i=0 ;i<num ; i++){
		int dem3 = 0;
	   for(int j=i+1;j<num-1;j++){
	   	if(a[j].diem.avg==a[i].diem.avg){
	   		a[j]=a[j+1];
	   		num--;
			dem3++;
		   }
	   }
	   if(dem3==1){
	   	change[dem4]=a[i];
	   	dem4++;
	   }
	}
	
	printf("\nDiem chuan la: %.2f ",a[ct-1].diem.avg);
	printf("\nDanh sach sinh vien trung tuyen la:");
	for(int k=0;k<dem4;k++){
		printf("\nName:  %20s",a[k].name);
	}
	
}

int main(){
	student a[1000];
	Nhapdanhsach(a);
	dstrungtuyen(a);
	diemcaonhat(a);
	timdiemchuan(a);
	getch();
}
