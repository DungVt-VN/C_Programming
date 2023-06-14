#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxlen 256

int main(){
	int i =    0, sum = 0;
	char s[maxlen], c[maxlen];
	int a[maxlen];
 	FILE* fp;
	printf("\nNhap vao ten file: ");
	gets(s);
	if((fp = fopen(s,"r")) == NULL){
		printf("\nKhong co file");
		exit(1);
	}
	while(!feof(fp)){
   		fgets(c, maxlen,fp);   
		a[i] = atoi(c);
 		i++;
	}
	fclose(fp);
	for(int j = 0;j < i;j++ ){
		printf("\n%d",a[j]);
		sum += a[j];
	}
	printf("\n%d",sum);   
}
 