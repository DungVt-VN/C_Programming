#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct danhsachhoso{
    char ho[10], dem[10], ten[10];
    int ngay, thang, nam;
}ds;

char ho[][20]={"Nguyen","Le","Tran","Li","Hoang"};
char dem[][20]={"Van","Trung","Hieu","Cong","Tuan","Vien"};
char ten[][20]={"Hung","Dat","Cuong","Ngoc","An","Bao","Dung"};

int random(int min, int max){
    return min +rand()%(max+1-min);
}

void random_ds(char s[100], int n){
    FILE *f=fopen(s,"w+");
    if(f == NULL){
        printf("Error");
    }
    for(int i = 0; i< n;i++){
        fprintf(f,"%s %s %s\n%d-%02d-%02d\n", ho[random(0,4)], dem[random(0,5)], ten[random(0,6)], random(1970,2002), random(3,12), random(1,30));
    }
    fprintf(f,"%c",'#');
    fclose(f);
}

void readfile(char s[100]){
    FILE *f=fopen(s,"w+");
    if(f == NULL){
        printf("Error");
    }
    fprintf(f,"%c",'#');
    fclose(f);
}
int main(){
    srand(time(NULL));
    int n;
    char s[100];
    printf("Nhap so luong nhan vien: ");
    scanf("%d",&n);
    fflush(stdin);
    printf("\nNhap ten file: ");
    gets(s);
    random_ds(s,n);
}