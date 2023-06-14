#include<stdio.h>

int main(){
	float g,p,h;
	printf("\nNhap giay phut gio: ");
	scanf("%f%f%f",&g,&p,&h);
	if(g< 0 ||g >60){
		printf("\nGiay khong hop le.");
		return 0;
    }  
	if(p<0 ||p>60){
		printf("\nPhut khong hop le");
		return 0;
    }
	if(h< 0 ||h>24){
		printf("\nGio khong hop le.");
		return 0;
    }
	printf("\nGio phut giay hop le");
}
