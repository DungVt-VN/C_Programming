#include <stdio.h>
#include <string.h>
void xoasau(char a[]){
    int n=1;
    int n1,n2,n3;
    n= strlen(a);
    do{
        n1=n2=n3=0;
        if(a[0]=='0' || a[0]=='3'|| a[0]=='6'|| a[0]=='9'){
            n1=1;
            for(int i = 0; i< n;i++){
                a[i]=a[i+1];
            }
            n--;
             printf("%s \n",a);
        }

        else if(a[n-1]=='0' || a[n-1]=='3' ||a[n-1]=='6'|| a[n-1]=='9'){
            n--;
            n2=1;
        }

        else if(((int)a[0] + (int)a[n-1])%3==0 ){
            n3=0;
            for(int i = 0; i< n;i++){
                a[i]=a[i+1];
            }
            n-=2;
        }
        else{
            break;
        }
        char b[n];
        strcpy(b,a);
        strcpy(a,b);
        printf("\n %d \n",strlen(a));
    } while(n1+n2+n3!= 0);
    printf("%s %d",a,n);
}

int main(){
    char a[]="63923";
    xoasau(a);

}