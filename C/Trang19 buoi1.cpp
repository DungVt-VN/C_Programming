#include<stdio.h>
#include<string.h>

void trang19(char c[], char d, char e){
	fflush(stdin);
	int a = strlen(c);
	printf("\n%c",c[1]);
	for(int i = 0; i < a;i++){
		if(c[i] == d)
			c[i] = e;
	}
	printf("\nString sau khi thay doi la:  ");
	puts(c);
}

int main(){
//bai trang 19
	char c[1000], d ,e;
	printf("\nNhap string: ");
	gets(c);
	printf("\nNhap ki tu can thay the: ");
	scanf("%c",&d);
	fflush(stdin);
	printf("\nNhap ki tu thay the: ");
	scanf("%c",&e);
	fflush(stdin);	
	trang19(c,d,e);
}
