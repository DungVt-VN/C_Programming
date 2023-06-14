#include<stdio.h>
#include<stdlib.h>

int random(int m,int M){
    return m + (int)(rand()%(M - m + 1));
}

int main(){
    char c[100];
    int n = -1, a[100], m, M;
    printf("Nhap ten file: ");
    gets(c);
    FILE *f = fopen(c,"r+");
    if(f == NULL){
        printf("Khong co file");
        FILE *f2 = fopen(c,"w+");
        while(n <= 0){
            printf("\nNhap n: ");
            scanf("%d",&n);
        }
        printf("\nNhap m: ");
        scanf("%d",&m);
        printf("\nNhap M: ");
        scanf("%d",&M);
        for (int i = 0; i < n ; i++ ){
            a[i] = random(m , M);
        }
        for(int i = 1; i < n; i++){
            int last = a[i];
            int k = i;
            while(k > 0 && a[k-1] > last){
                a[k] = a[k-1];
                a[k-1] = last;
                k--;
            }
        }
        for(int i = 0; i < n; i++){
            fprintf(f2, "%d  ", a[i]);
        }
        fclose(f2);
    }else {
        fscanf(f,"%d",&n);
        for(int i = 0; i < n; i++){
            fscanf(f,"%d",&a[i]);
        }
        for(int i = 1; i < n; i++){
            int last = a[i];
            int k = i;
            while(k > 0 && a[k-1] > last){ 
                a[k] = a[k-1];
                a[k-1] = last;
                k--;
            }
        }
        fprintf(f,"\n");
        for(int i = 0; i < n; i++){
            fprintf(f, "%d  ", a[i]);
        }
    }
    fclose(f);
}