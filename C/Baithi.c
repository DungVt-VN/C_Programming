#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char name[256];
	struct node *next;
}node;

typedef struct Queue{
	node *font;
	node *tail;
}Queue;

Queue *createQueue(){
	Queue *newQueue = (Queue *)malloc(sizeof(Queue));
	newQueue->font = NULL;
	newQueue->tail = NULL;
	return newQueue;
}


Queue *enQueue(Queue *q,char name[]){
	node *newNode = (node *)malloc(sizeof(node));
	newNode->next = NULL;
	strcpy(newNode->name,name);
	if(q->font == NULL){
		q->font = q->tail = newNode;
	}else{
		q->tail->next = newNode;
		q->tail = newNode;
	}
}

Queue *deQueue(Queue *q){
	if(q->font == NULL){
		printf("Danh sach trong!");
		return NULL;
	}
	printf("Khach hang tiep theo la: %s",q->font->name);
	node *cmp = q->font;
	q->font = q->font->next;
	free(cmp);
}

void DuyetQueue(Queue *q){
	node *tg = q->font;
	while(tg != NULL){
		printf("%s\n",tg->name);
		tg = tg->next;
	}
}

//cau 1:
void docfile(Queue *q){
	char name[256];
	int sdt;
	fflush(stdin);
	FILE *f = fopen("Danhsach.txt","r+");
	while(!feof(f)){
		fscanf(f, "%s %d",&name ,&sdt);
		printf("%s %d\n",name,sdt);
		q = enQueue(q,name);
	}
	fclose(f);
}
//cau 2:
void ThemNguoiMua(Queue *q){
	fflush(stdin);
	char name[256];
	printf("\nNhap ten nguoi mua: "); gets(name);
	enQueue(q,name);
	printf("Danh sach sau khi them la:\n");
	DuyetQueue(q);
}
//cau 3:
void BanHang(Queue *q){
	if(deQueue(q) == NULL) return;
	int A, B, C;
	printf("\nNhap so luong cua tung loai mat hang: ");
	printf("\nMat hang A: "); scanf("%d",&A);
	printf("Mat hang B: "); scanf("%d",&B);
	printf("Mat hang C: "); scanf("%d",&C);
	while(A <= 0 || B <= 0 || C <= 0){
		printf("\nSo luong bi loi vui long nhap lai!\n");
		printf("Mat hang A: "); scanf("%d",&A);
		printf("Mat hang B: "); scanf("%d",&B);
		printf("Mat hang C: "); scanf("%d",&C);
	}
	fflush(stdin);
	FILE *f = fopen("Banhang.txt","a+");
	static int i = 0;
	if(i != 0) fprintf(f,"\n");
	fprintf(f,"%d %d %d", A, B, C);
	i++;
	fclose(f);
}

//cau 4:

void TongKet(Queue *q){
	DuyetQueue(q);
	FILE *f = fopen("Danhsach.txt","w+");
	node *tg = q->font;
	while(tg != NULL){
		static int i = 0;
		if(i != 0) fprintf(f,"\n");
		fprintf(f, "%s",tg->name);
		i++;
		tg = tg->next;
	}
	fclose(f);
	FILE *f1 = fopen("Banhang.txt","a+");
	int a= -1;
	fprintf(f1,"\n%d",a);
	fclose(f1);
}
//cau 5:




//cau 6:
void Insert_Head(Queue* q){
	fflush(stdin);
	node *newNode = (node *) malloc(sizeof(node));
	char name[256];
	printf("Nhap ten:"); gets(name);
	strcpy(newNode->name,name);
	newNode->next = q->font;
	q->font =newNode;
	return;
}



int main(){
	int n;
	char n2;
	Queue *q = createQueue();
	while(1){
	    printf("\n*--------------------------------------------------*\n");
	    printf("*  [ 1 ] Doc file                                 *\n");
	    printf("*  [ 2 ] In thong tin cac sinh vien                *\n");
	    printf("*  [ 3 ] Tim kiem theo ma so sinh vien             *\n");
	    printf("*  [ 4 ] Tim kiem theo GPA va que quan             *\n");
	    printf("*  [ 5 ] Sap xep theo GPA                          *\n");
	    printf("*  [ 6 ] Thoat                                     *\n");
	    printf("*--------------------------------------------------*\n");
	    printf("\n\n Nhap lua chon cua ban:   ");
	    scanf("%d",&n);
	    system("cls");
	    if(n < 1 || n > 6){
	    	printf("\nLua chon khong hop le nhap lai: ");
	    }else{
	        switch(n){
	        	case 1:
					docfile(q);
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 2:
					ThemNguoiMua(q);
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 3:
					BanHang(q);
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 4:
					TongKet(q);
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
				case 5:

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 6:
					Insert_Head(q);
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        }
        }
    }
    getch();
}
	