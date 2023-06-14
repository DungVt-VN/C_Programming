#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct node{
    char hoten[40];
    char sodt[11];
    struct node* next;
} Node ;
typedef struct Queue{
    node* head;
    node* tail;

    Queue(){
        this->head = NULL;
        this->tail =NULL;
    }
}queue;

Node* createnode(char str[], char s[]){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Error");
    }
    strcpy(newnode->hoten,str);
    strcpy(newnode->sodt,s);
    newnode->next=NULL;
    return newnode;
}
Queue* createqueue(){
    Queue* hangdoi=(Queue*)malloc(sizeof(queue));
    //Queue* hangdoi = Queue();
    if(hangdoi==NULL){
        printf("Error");
    }
    hangdoi->head=NULL;
    hangdoi->tail=NULL;
    return hangdoi;
}

Queue* insert_tail(queue* list,char str[],char s[]){
    if(list==NULL){
        printf("Error");
    }
    node* newnode=createnode(str,s);
    if(list->head==NULL){
        list->head=newnode;
        list->tail=newnode;
        return list;
    }
    else{
        list->tail->next=newnode;
        list->tail=newnode;
        return list;
    }
}

Queue* doc_file(char filename[],queue* list){
    FILE* f= fopen(filename,"r");
    if(f==NULL){
        printf("khongtim thay file");
    }
    char str[40], s[11];
    fflush(stdin);
    while(!feof(f)){
        fscanf(f,"%s",str);
        printf("%s ",str);
        //fflush(stdin);
        fscanf(f,"%s",s);
        printf("%s \n",s);
       
        list= insert_tail(list,str,s);
        
        //printf("%s  %s \n",str,s);
    }
    fclose(f);
    return list;
}

queue* themnguoi(queue* list){
    char str[40];
    char s[11]=" ";
    printf("nhap ho va ten nguoi mua hang can them vao danh sach hang doi \n");
    scanf("%s",&str);
    list= insert_tail(list,str,s);
    return list;
}

void duyetds(queue* list){
    if(list==NULL){
        return;
    }
    if(list->head==NULL){
        return;
    }
    node*tg= list->head;
    while(tg!=NULL){
        printf("%s  %s \n",tg->hoten,tg->sodt);
        tg=tg->next;
    }
    return;
}

node* layra(queue* list){
    node* newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->hoten,list->head->hoten);
    strcpy(newnode->sodt,list->head->sodt);
    newnode->next=NULL;
    return newnode;
}

Queue* dequeue(queue* list){
    node* tg=list->head;
    list->head=list->head->next;
    free(tg);
    return list;
}

Queue* ghithongtin(queue* list, char filename[]){
    node* temp= layra(list);
    list= dequeue(list);
    /*if(list->head==NULL){
        printf("danh sach rong");
        exit(1);
    }
    char str[40];
    strcpy(str,list->head->hoten);*/
    int a,b,c;
    printf("%s muon mua bao nhieu mat hang A:",temp->hoten);
    scanf("%d",&a);
    while(a<0){
        printf("ko the mua duoc, moi nhap lai:");
        scanf("%d",&a);
    }
    printf("\n%s muon mua bao nhieu mat hang B:",temp->hoten);
    scanf("%d",&b);
    while(b<0){
        printf("ko the mua duoc, moi nhap lai:");
        scanf("%d",&b);
    }
    printf("\n%s muon mua bao nhieu mat hang C:",temp->hoten);
    scanf("%d",&c);
    while(c<0){
        printf("ko the mua duoc, moi nhap lai:");
        scanf("%d",&c);
    }
    FILE* f= fopen(filename,"a+");
    if(f==NULL){
        printf("khongtim thay file can ghi");
    }
    fprintf(f,"%d %d %d",a,b,c);
    fclose(f);
    return list;
}

void ghivaofile(char filename[],queue* list,char name[]){
    FILE* f= fopen(filename,"w");
    if(f==NULL){
        printf("khong tim thay file ghi");
    }
    node* tg=list->head;
    while(tg!= NULL){
        fprintf(f,"%s %s \n",tg->hoten,tg->sodt);
        tg=tg->next;
    }
    fclose(f);
    FILE* f1=fopen(name,"a+");
    fprintf(f1,"\n-1");
    fclose(f1);

}

queue* insert_head(queue* list,char str[],char s[]){
    node* newnode= createnode(str,s);
    if(list->head==NULL){
        list->head= newnode;
        list->tail= newnode;
        return list;
    }
    else{
        newnode->next=list->head;
        list->head=newnode;
        return list;
    }
}

void tinhtien(char filename[]){
    FILE* f= fopen(filename,"r");
    int tien=0;
    int a,b,c;
    int A=0,B=0,C=0;
    while(!feof(f)){
        fscanf(f,"%d ",&a);
        if(a== -1){
            tien=A*10000000 +B*50000000+C*80000000;
            printf("so tien ban hang mot ngay la: %d\n",tien);
            A=0;
            B=0;
            C=0;
            tien=0;
            continue;
        }
        fscanf(f,"%d ",&b);
        fscanf(f,"%d ",&c);
        
        A+=a;
        B+=b;
        C+=c;
       
    }

    fclose(f);
}

int main() {
    int n;
    char filename1[]="danhsach.txt";
    char filename2[]="banhang.txt";
    char str[40], s[11];
    queue* ds=createqueue();
while(1){
    printf("\n======Chuong trinh quan li ban hang=======\n");
    printf(" [ 1 ] doc file danh sach.txt \n");
    printf(" [ 2 ] Them nguoi mua vao hang doi \n");
    printf(" [ 3 ] Ban hang \n");
    printf(" [ 4 ] Ghi thong tin sau mot ngay \n");
    printf(" [ 5 ] Thong ke thong tin ban hang \n");
    printf(" [ 6 ] Yeu cau dac biet\n");
    printf("--------------------------------------------------*\n");
    printf("\n\n Nhap lua chon cua ban: ");
    scanf("%d",&n);
  
    if(n == 7){
        exit(0);
    }else if(n < 1 || n > 7){
        printf("\nLua chon khong hop le nhap lai: "); scanf("%d", &n);
    }else{
        switch(n){
            case 1:
                doc_file(filename1,ds);
                break;
            case 2:
                ds=themnguoi(ds);
                
                break;
            case 3:
                ds= ghithongtin(ds,filename2);

                break;
            case 4:
                duyetds(ds);
                ghivaofile(filename1,ds,filename2);
                break;
            case 5:
                tinhtien(filename2);
                break;
            case 6:
                printf("nhap ten va so dien thoai nguoi co yeu cau dac biet:");
                scanf("%s %s",&str,&s);
                ds=insert_head(ds,str,s);

            }
            
        }
    }
    return 0;
}   