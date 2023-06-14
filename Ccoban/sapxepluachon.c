#include<stdio.h>
#include<stdlib.h>

int main(){
    int n = -1;
    int a[100];
    char c[100];
    printf("Nhap ten file: ");
    fflush(stdin);
    FILE *f = fopen( c , "r+");
    if(f == NULL) {
        printf("Error");
        break;
    }
    fscanf(f, "%d",n);
    if(n == -1) {   
        printf("\nFile trong!");
        n = 0;
        while(n <= 0){
            printf("\nNhap n:");
            scanf("%d",&n);
        }
        for(int i = 0; i < n; i++){
            printf("\nNhap so thu %d: ", i+1);
            scanf("%d",&a[i]);
        }
    }else {
        fscanf(f,"%d",&n);
        for(int j = 0; j < n; j++){
            fscanf(f, "%d", &a[j]);
        }
    }
    int min;
    for(int i = 0; i < n-1; i++){
        min = a[i];
        for(int j = i+1; j < n; j++){
            if(a[j] < min) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        fprintf(f,"%d ",a[i]);
    }
    fclose(f);
}