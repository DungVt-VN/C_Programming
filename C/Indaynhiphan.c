#include<stdio.h>

int arr[] = {-1, -1, -1, -1, -1};

int n = 4;

void ghinhan(){
    static int j = 1;
    printf("\nDay %02d  ",j );
    for(int i = 0; i < n ;i++){
        printf("%d  ", arr[i]);
    }
    j++;
}

void indaynhiphan(int k){
    for(int i = 0; i <= 1; i++){
        arr[k-1] = i;
        if(k == n) ghinhan();
        else    indaynhiphan(k+1);
    }
}

int main(){
    indaynhiphan(1);
}