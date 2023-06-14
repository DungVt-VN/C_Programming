#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct test{
    char name[100];
    char mssv[100];
    float dtb;
}test;

void docfile(test t[],FILE *f){
    fscanf(f,"%s %s %f",&t[0].name,&t[0].mssv,&t[0].dtb);
    printf("%s",t[0].name);
}






int main(){
    FILE *f = fopen("filein.txt", "r+");
    test t[1];
    docfile(t,f);
    printf("\n%s",t[0].name);
    fclose(f);
}