#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int random(int m,int M){
    return m + (int)(rand()%(M - m + 1));
}

int main(){
    int n, m, M;1
    int a[100];
    printf("\nNhap n, m, M: ");
    scanf("%d %d %d",&n ,&m, &M);
    while ( m > M){
        printf("\nNhap n, m, M: ");
        scanf("%d %d %d",&n ,&m, &M);
    }
    for (int i = 1; i <= n ; i++ ){
        a[i] = random(m , M);
    }
    FILE *f = fopen("sapxep.txt","w");
    fprintf(f,"%d\n",n);
    for (int i = 1; i <= n ; i++ ){
        fprintf(f,"%d ",a[i]);
    }
    fclose(f);
}