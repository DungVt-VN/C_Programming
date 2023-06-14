#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxlen 256

int main(){
	int i = 0;
	char s[maxlen],arr[maxlen];
	char line[maxlen][maxlen];
	FILE* fp;
	printf("\nNhap vao ten file: ");
	gets(s);
	if((fp = fopen(s,"r")) == NULL){
		printf("\nKhong co file");
		exit(1);
	}
	int val[maxlen];
	while(!feof(fp)){
		fscanf(fp,"%[^\n]",line[i]);
		val[i] = atoi(line[i]);
		i++;
	}
	for(int j = 0;j < i;j++ ){
		printf("\n%d",val[j]);
	}
	fclose(fp);
}

