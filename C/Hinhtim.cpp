#include<stdio.h>
#include<math.h>
int main(){
	for(int i=-4 ; i<=4;i++){
		for(int j=-4;j<=4;j++){
			if(i - j ==0){
				printf("*");
			}else printf(" ");
		}
					printf("\n");
	}
}
