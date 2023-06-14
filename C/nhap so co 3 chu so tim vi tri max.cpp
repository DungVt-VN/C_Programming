#include<stdio.h>
int main(){
	unsigned int a,b,c,max, n;
	printf("Nhap so co ba chu so: ");
    scanf("%d",&n);
    while(n<100 || n>999){
    	printf("\nNhap so co ba chu so: ");
        scanf("%d",&n);
	}
	a = n/100;
    b = (n -a*100)/10;
    c = n -a*100 - b*10;
	printf("\n%d %d %d",a,b,c);
	max =a;
	if( b>max) max =b;
	if(c>max) max =c;
	
	if(max == a){
		printf("\nMax o vt hang tram (%d)", a);
	}
	if(max == b)
	    printf("\nMax o vt hang chuc (%d)",b);
	if(max == c){
		printf("\nMax o vt hang don vi (%d)",c);
	}
	return 1;
}
