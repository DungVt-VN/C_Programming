#include<stdio.h>


int n = 6;
int a[][6]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int ghinhan(int a){
	printf("\n(%d , %d )");
}

int UCV(int k,int i){
	if(i != k)
}

int sephau(int k){
	for(int i =1; i <= n; i++){
		if(UCV(k,i) == 1)
			return ghinhan(k , i );
		else sephau(k+1);
	}
}

int main(){
	sephau(1);
	return 0;
}
