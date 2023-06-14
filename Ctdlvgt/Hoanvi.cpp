#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
 
 
 
int dem=0;
int n=6;
int x[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
 
 
 
void ghinhan(){
    int i;
    printf("\ndem=%d:  ",++dem);
    for(i=0;i<n;i++){
        printf("%d ",x[i]);
    }
}
 
 
 
void Indaynhiphan(int k){
    int i;
    for(i=0;i<2;i++){
        x[k-1]=i;
        if(k==n) ghinhan();
        else Indaynhiphan(k+1);
    }
}
 
 
 

int UCV(int i, int k){
    int j;
    for(j=0;j<k-1;j++){
        if(x[j]==i) return 0;
    }
    return 1;
}
 
 
 

void Inhoanvi_n_so(int k){
    int i;
    for(i=1;i<n+1;i++){
        if(UCV(i,k)==1){
            x[k-1]=i;
            if(k==n) ghinhan();
            else Inhoanvi_n_so(k+1);
        }
    }
}
 
 
 
int main(){
    //Indaynhiphan(1);
    Inhoanvi_n_so(1);

    //getch();
    return 1;
}
