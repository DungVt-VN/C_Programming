#include<stdio.h>
int main(){
	int date, month, year;
	printf("Nhap ngay thang nam: ");
	scanf("%d%d%d",&date,&month,&year);
	if(month <1 || month >12 || date <1){
		printf("\nNgay thang khong hop le.");
	}else if(month ==2 && ( date >29)){
		printf("\nNgay thang khong hop le.");
	}else if((month ==1|| month == 3|| month == 5 || month==7||month==8||month==10||month==12) && (date> 31)){
		printf("\nNgat Thang khong hop le.");
	}else if((month ==4|| month == 6|| month == 9 || month==11) && (date> 30)){
	printf("\nThang khong hop le.");	
	}else printf("\nNgay thang nam hop le.");
}
