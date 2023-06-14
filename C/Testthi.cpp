#include <stdlib.h>
#include<stdio.h>




int main(){
    int X;
    char aX[100];
    FILE *f = fopen("X.txt","r+");
    int i = 0;
    fscanf(f,"%d\n",&X);
    printf("\n%d",X);
    while(!feof(f)){
        fscanf(f,"%c",&aX[i]);
        i++;
    }
    for(int j=0; j < i; j++){
        if(aX[j] < 58 && aX[j] > 47){
            printf("\n%c",aX[j] );
        }
    }
    fclose(f);
}