#include<stdio.h>
#include<stdlib.h>

int main(){
    int n ;
    FILE *f = fopen("file.txt", "r+");
    fscanf(f, "%d", &n);
    printf("%d\n", n);
    fclose(f);
}