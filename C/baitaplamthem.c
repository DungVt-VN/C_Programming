#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char name[20];
    char mssv[10];
    float avg;
}SinhVien;

typedef struct node{
    SinhVien SV;
    struct node *next;
}node;

typedef struct Queue{
    node *font;
    node *back;
}Queue;

Queue *createQueue(){
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    if(newQueue == NULL) {
        printf("Failed to allocate");
        exit(1);
    }
    newQueue->font = NULL;
    newQueue->back = NULL;
    return newQueue;
}

node *NewNode(SinhVien SV[]){
    node *newNode = (node* )malloc(sizeof(node));
    if(newNode == NULL) {
        printf("Failed to allocate");
        exit(1);
    }
    newNode->SV = SV[0];
    newNode->next = NULL;
    return newNode;
}
void DuyetDS(Queue *head){
    node *tg = head->font;
    int dem = 1;
    while(tg != NULL){
        printf("\nSinh Vien Thu %d:",dem);
        printf("\n%s\t %s\t %0.2f",tg->SV.name,tg->SV.mssv,tg->SV.avg);
        tg = tg->next;
        dem++;
    }
    printf("\n\nHet danh sach!\n\n");
}

void DuyetvaoDS(Queue *head,node *newNode){
    if(head->font == NULL){
        head->font = newNode;
        head->back = newNode;
    }
    else{
        head->back->next = newNode;
        head->back = newNode;
    }
}


void Load(Queue *head){
    SinhVien SV[1];
    FILE* f = fopen("B.txt","r+");
    if(f == NULL){
        printf("Khong mo duoc file! ");
        exit (1);
    }
    while(!feof(f)){
        fscanf(f, "%s %s %f\n",&SV[0].name,&SV[0].mssv,&SV[0].avg);
        node *newNode = NewNode(SV);
        DuyetvaoDS(head,newNode);
    }
    printf("\nDone loading!");
    fclose(f);
}

void XoaSV(Queue *head){
    node *tg = head->font;
    if(tg == NULL) return;
    char s[100];
    fflush(stdin);
    printf("\nNhap ma so sinh vien can xoa: ");
    gets(s);
    if(strcmp(tg->SV.mssv,s) == 0 ){
        printf("\nTen hoc sinh xoa la: %s", tg->SV.name);
        node *tmp = tg;
        head->font = tg->next;
        free(tmp);
    }
    while(tg->next!=NULL){
        if(strcmp(tg->next->SV.mssv,s) == 0){
            printf("\nTen hoc sinh xoa la: %s", tg->next->SV.name);
            node *tmp = tg->next;
            tg->next = tg->next->next;
            free(tmp);
        }
        if(tg->next == NULL){
            head->back = tg;
            break;
        }
        tg = tg->next;
    }
}

void Sapxep(Queue *head){
    node *tg = head->font, *tg2;
    FILE *f = fopen("filename03.txt","w+");
    while(tg->next!= NULL){
        tg2 = tg->next;
        while(tg2 != NULL){
            if(tg->SV.avg > tg2->SV.avg){
                SinhVien tmp = tg->SV;
                tg->SV = tg2->SV;
                tg2->SV = tmp;
            }
            tg2 = tg2->next;
        }
        tg = tg->next;
    }
    DuyetDS(head);
    tg = head->font;
    while(tg != NULL){
        fprintf(f,"%s\t%s\t%0.2f\n",tg->SV.name,tg->SV.mssv,tg->SV.avg);
        tg = tg->next;
    }
    fclose(f);
}

void SinhViendiemcaonhat(Queue *head){
    node *tg = head->font;
    float max = tg->SV.avg;
    SinhVien SVx = tg->SV;
    while(tg != NULL){
        if(tg->SV.avg > max){
            max = tg->SV.avg;
            SVx = tg->SV;
        }
        tg = tg->next;
    }
    printf("\nSinh vien co diem cao nhat la: \n");
    printf("%s\t%s\t%0.2f\n",SVx.name,SVx.mssv,SVx.avg);
}

void Timkiemtheomssv(Queue *head){
    fflush(stdin);
    node *tg = head->font;
    printf("\nNhap mssv: ");
    char mssv[100];
    gets(mssv);
    SinhVien SVx;
    int check = 0;
    while(tg != NULL){
        if(strcmp(tg->SV.mssv,mssv) == 0){
            SVx = tg->SV;
            check =1;
        }
        tg = tg->next;
    }
    if(check ==0){
        printf("\nKhong co thong tin sinh vien! ");
    }else{
        printf("\nSinh vien la: \n");
        printf("%s\t%s\t%0.2f\n",SVx.name,SVx.mssv,SVx.avg);
    }
}

void themsinhvien(Queue *head){
    fflush(stdin);
    SinhVien SV[1];
    printf("\nNhap ten sinh vien: "); gets(SV[0].name);
    printf("\nNhap mssv: "); gets(SV[0].mssv);
    printf("\nNhap diem trung binh: "); scanf("%f", &SV[0].avg);
    node *newnode = NewNode(SV);
    head->back->next = newnode;
    head->back = newnode;
    printf("\nDanh sach sinh vien la: \n");
    DuyetDS(head);

    FILE *f = fopen("thongtinsinhvien.txt", "w+");
    node *tg = head->font;
    while(tg != NULL){
        fprintf(f,"%s\t%s\t%0.2f\n",tg->SV.name,tg->SV.mssv,tg->SV.avg);
        tg = tg->next;
    }
    fclose(f);
}

void freeQueue(Queue *head){
    node *tg = head->font;
    while(tg != NULL){
        node *tmp = tg->next;
        free(tg);
        tg = tmp;
    }
    free(head);
}

int main(){
    Queue *head = createQueue();
    int n;
    while(1){
	    printf("\n=======================Nhap vao so bat ky de thuc hien chuc nang========================\n");
	    printf("*  1) Doc file name01.txt va xuat danh sach ra man hinh                                 *\n");
	    printf("*  2) Nhap ma so va xoa sinh vien do                                                    *\n");
	    printf("*  3) Sap xep theo thu tu tang dan mssv va luu sang file name03                         *\n");
	    printf("*  4) Tim sinh vien co diem cao nhat sau luu vao file name04                            *\n");
	    printf("*  5) Tim kiem sinh vien theo ma so		                                        *\n");
	    printf("*  6) Them 1 sinh vien vao cuoi danh sach sau do luu vao file thongtinsinhvien.txt      *\n");
        printf("*  7) Ket thuc chuong trinh                                                             *\n");
	    printf("*---------------------------------------------------------------------------------------*\n");
	    printf("\n\n Nhap lua chon cua ban:   ");
	    scanf("%d",&n);
	    	system("cls");
	    if(n == 7){
	    		printf("\nChuong trinh da ket thuc ");
	    		break ; 
	    }else if(n < 1 || n > 7){
	    		printf("\nLua chon khong hop le nhap lai: ");
	    }else{
	        switch(n){
	        	case 1: 
	        		Load(head);
	        		DuyetDS(head);
	        		break ;
	        	case 2:
                    XoaSV(head);
                    printf("\nDanh sach sau khi xoa:");
                    DuyetDS(head);
	        		break ;
	        	case 3 :
                Sapxep(head);
	        		break ;
	        	case 4 :
                    SinhViendiemcaonhat(head);
	        		break ;
	        	case 5: 
                    Timkiemtheomssv(head);
	        		break ;	
	        	case 6: 
                themsinhvien(head);
	        	break ;
            }
        }
    }

    freeQueue(head);
    return 1;
}