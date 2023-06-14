#include<stdio.h>

int main(){
	int a[9] = {2,13,-10,21,-3,-4,6,9,-3};
	int max = a[0];
	for(int i = 0 ; i < 9 ; i ++){
		int sum = 0;
		for(int j = i; j < 9; j++){
			sum += a[j];
			if(sum > max) max = sum;
		}
	}
	printf("%d",max);
	
}
