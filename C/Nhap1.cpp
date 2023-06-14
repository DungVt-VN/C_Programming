#include<stdio.h>
#include<string.h>
#include<conio.h>

//cau a
void getData(int , int );
void getData(int *M , int *N){
	printf("Nhap vao hai so M va N: ");
	scanf("%d%d",M,N);
}
int main(){
    int M,N;
    getData(&M , &N);
//cau b	
	int diem[M][N];
	for(int i = 0; i<M ; i++){
		for(int j=0 ; j<N; j++){
			printf("\nNhap diem so cua hoc sinh %d cua to %d la: ", j+1 , i+1);
			scanf("%d",&diem[i][j]);
			while(diem[i][j] < 0 || diem[i][j]>10){
				printf("\nDiem khong hop le nhap lai diem: ");
				scanf("%d",&diem[i][j]);
			}
		}
	}   
	for(int i = 0; i<M ; i++){
		for(int j=0 ; j<N; j++){
			printf("%d  ",diem[i][j]);
		}
		printf("\n");
	} 
//cau c
	int max = 0;
    for(int i = 0; i<M ; i++){
		if(diem[i][0] > max){
			max = diem[i][0];
	    }
	}
				
	printf("\nDiem cao nhat trong cac to truong la: %d", max);
	
//cau d
	int min = 10;
    for(int i = 0; i<M ; i++){
		if(diem[i][1] < min) {
			min = diem[i][1];
		}
	}
	printf("\nDiem thap nhat trong cac to pho la: %d", min);
	
//cau e
    int sum=0;
	for(int i = 0; i<M ; i++){
		for(int j=0 ; j<N; j++){
			if(diem[i][j]> diem[0][2]) sum++;
		}
	}   
	printf("\nSo ban co diem cao hon ban lop truong la: %d",sum);
	
    return 0;
}
