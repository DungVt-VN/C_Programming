#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>







// Chuc nang 1:
int TuyenDuong(){
    int X, Y; //So luong thanh pho;
    char s[100];
    char sX[] = "X.txt";
    char sY[] = "Y.txt";
    int aX[100];
    int aY[100];
    printf("\nNhap ten hang: ");
    gets(s);
    if(strcmp(s,sX) == 0){
        int i = 0;
        FILE *f = fopen("X.txt", "r+");
        fscanf(f, "%d", &X);
        while(!feof(f)){
            fscanf(f,"%d",&aX[i]);
            i++;
        }
        printf("\nTuyen duong cua X la: %d",i-1-X);
        fclose(f);
    }else if(strcmp(s,sY) == 0){
        int j = 0;
        FILE *f = fopen("Y.txt", "r+");
        fscanf(f, "%d", &X);
        while(!feof(f)){
            fscanf(f, "%d",&aY[j]);
        }
        printf("\nTuyen duong cua Y la: %d",j-1-Y);
        fclose(f);
    }else printf("\nBan da nhap sai ten!\n");
}






int main(){
	int n;
	char n2;
	while(1){
	    printf("\n*---------------------------------------------------------*\n");
	    printf("*  [ 1 ] Xac dinh so luong cac tuyen duong bay cua hang   *\n");
	    printf("*  [ 2 ] Xoa di cac tuyen duong bay cua mot hang          *\n");
	    printf("*  [ 3 ] Them cac tuyen duong bay cua mot hang            *\n");
	    printf("*  [ 4 ] Tinh toan chi phi di lai                         *\n");
	    printf("*  [ 5 ] Thoat                                            *\n");
	    printf("*---------------------------------------------------------*\n");
	    printf("\n\n Nhap lua chon cua ban:   ");
	    scanf("%d",&n);
	    system("cls");
	    if(n == 5){
	    	printf("Good bye! ");
	    	break;
	    }else if(n < 1 || n > 5){
	    	printf("\nLua chon khong hop le nhap lai: \n\n");
	    }else{
	        switch(n){
	        	case 1:
                    printf("\nBan da chon chuc nang 1!");
                    fflush(stdin);
                    TuyenDuong();
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 2:
                    printf("\nBan da chon chuc nang 2!");

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 3:
                    printf("\nBan da chon chuc nang 3!");

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 4:
                    printf("\nBan da chon chuc nang 4!");

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        }
        }
    }
    getch();
}
	
