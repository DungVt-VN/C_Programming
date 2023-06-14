#include<stdio.h>
#include<string.h>

char n[100];

int check(char x){
    if(x == '0' || x == '3' || x =='6' || x == 9){
        return 1;
    }
    return 0;
}

char xoaxau(char xn[]){
    int dem = strlen(xn);
    do{
        if(check(xn[0]) == 1){
            for(int i = 0; i < dem; i++){
                xn[i] = xn[i + 1];
            }
            dem--;
            continue;
        }else if(check(xn[dem-1]) == 1){
            dem--;
            continue;
        }else if(((int)xn[0] + (int)xn[dem-1])%3 == 0){
            for(int i = 0; i < dem; i++){
                xn[i] = xn[i + 1];
            }
            dem = dem-2;
            continue;
        }
        break;
    }while(1);
    for(int i = 0; i < dem; i++){
        printf("%c",xn[i]);
    }
}


int main(){
    char xn[] = "123";
    xoaxau(xn);
}