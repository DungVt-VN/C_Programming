#include<stdio.h>

int main(){

//ý a
	float a[100][100];
    int n;
    printf("Nhap n: ");scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("Nhap a[%d][%d] : ",i,j);scanf("%f",&a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        printf("\n");
        for(int j = 1; j <= n; j++){
            printf("%0.1f  ",a[i][j]);
        }
    }
//ý b
    int check = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[i][j] != 0){
                check ++;
            }
        }
    }
    if(check == 0) printf("\nDay la ma tran tam giac.");
    else printf("\nDay khong phai ma tran tam giac!");
//ý c
    float max = a[1][2];
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i][j] > max){
                max = a[i][j];
            }
        }
    }
    printf("\nMax = %0.2f",max);
}
