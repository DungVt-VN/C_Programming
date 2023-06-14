#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int n;
	char n2;
	while(1){
	    printf("\n*--------------------------------------------------*\n");
	    printf("*  [ 1 ] Nhap thong tin sinh vien                  *\n");
	    printf("*  [ 2 ] In thong tin cac sinh vien                *\n");
	    printf("*  [ 3 ] Tim kiem theo ma so sinh vien             *\n");
	    printf("*  [ 4 ] Tim kiem theo GPA va que quan             *\n");
	    printf("*  [ 5 ] Sap xep theo GPA                          *\n");
	    printf("*  [ 6 ] Thoat                                     *\n");
	    printf("*--------------------------------------------------*\n");
	    printf("\n\n Nhap lua chon cua ban:   ");
	    scanf("%d",&n);
	    system("cls");
	    if(n == 6){
	    	printf("Good bye! ");
	    	break;
	    }else if(n < 1 || n > 6){
	    	printf("\nLua chon khong hop le nhap lai: ");
	    }else{
	        switch(n){
	        	case 1:

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 2:

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 3:

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 4:

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 5:

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        }
        }
    }
    getch();
}
	