#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

 

 

 

typedef int ElementType;

 

 

 

typedef struct NodeType{
    ElementType Inf;
    struct NodeType *Next; 
} List;

 

 

 

List *createNewNode(ElementType X){
    List *newnode=(List*)malloc(sizeof(List));
    if(newnode==NULL){
        printf("Error in memory allocation\n");
        exit(0);
    }
    
    newnode->Inf=X;
    newnode->Next=NULL;
    
    return newnode;
}

 

 

 

void duyetds(List *head){
    List *tg=head;
    printf("\n");
    while(tg!=NULL){
        printf("%d ",tg->Inf);
        tg=tg->Next;
    }    
}

 

 

 

void freelist(List *head){
    List *tg=head,*temp;

 

 

 

    while(tg!=NULL){
        temp=tg->Next;
        free(tg);
        tg=temp;
    }    
}

 

 

 

List *Insert_ToHead(List *head, ElementType X)
{
    List *newnode = createNewNode(X);
    newnode->Next = head;
    return newnode;
}

 

 

 

List *Insert_ToLast(List *head, ElementType X)
{
    List *newnode,*temp;
    newnode=createNewNode(X);
    
    if(head==NULL) {
        head=newnode;
    }
    else{
        temp=head;
        while(temp->Next!=NULL){
            temp=temp->Next;
        }
        temp->Next=newnode;
    }
    
    return head;
}

 

 

 

void Insert_Middle(List *Prev, ElementType X){
    if(Prev==NULL) return;
    List *newnode=createNewNode(X);
    newnode->Next=Prev->Next;
    Prev->Next=newnode;
}

 

List *Delete_Head(List *head){
    if(head==NULL) return NULL;
    List *tg=head->Next;
    free(head);
    return tg;
}

 

List *Delete_Last(List *head){
    if(head==NULL) return NULL;
    if(head->Next==NULL){ free(head); return NULL;}
    List *tg=head;
    while(tg->Next->Next!=NULL){
        tg=tg->Next;
    }
    free(tg->Next);
    tg->Next=NULL;
    return head;
}

 

List *daothutuds1(List *head){
    List *tg=head;
    List *out=NULL;
    
    while(tg!=NULL){
        out=Insert_ToHead(out,tg->Inf);
        tg=tg->Next;
    }    
    
    return out;    
}

 

 

 

List *daothutuds2(List *head){
    List *t1,*t2,*t3;
    if((head==NULL)||(head->Next==NULL)) return head;
    t1=NULL;
    t2=head;
    t3=head->Next;
    while(t3!=NULL){
        t2->Next=t1;
        t1=t2;
        t2=t3;
        t3=t3->Next;
    }
    t2->Next=t1;
    return t2;
}

 

List *daothutuds3(List *head){
    if(head==NULL) return NULL;
    if(head->Next==NULL) return head;
    
    List *l=daothutuds3(head->Next);
    //thuc hien dao chieu mui ten

 

    head->Next->Next=head;
    head->Next=NULL;
    
    return l;
}

 

List *Xoanutam1(List *head) {
    while(head->Inf < 0){
        head = Delete_Head(head);
    }
    
    List *tmp = head;
    
    while(tmp != NULL) {
        if (tmp->Next==NULL) break;
        if (tmp->Next->Inf < 0 ) {
            List *tmp1 = tmp->Next;
            tmp->Next = tmp->Next->Next ;
            free(tmp1);
        }
        else tmp = tmp->Next;
    }
    
    return head;
}
    
    
List *Xoanutam2(List *head) {
    List *tg1=NULL,*tg2=head;
    
    while(tg2!=NULL){
        if(tg2->Inf < 0){
            if(tg1==NULL){
                head=head->Next;
                free(tg2);
                tg2=head;
            }
            else{
                tg1->Next=tg2->Next;
                free(tg2);
                tg2=tg1->Next;
            }
        }
        else{
            tg1=tg2;
            tg2=tg2->Next;
        }
    }
    return head;
}

 

int main(){
    List *list1k=NULL;
    int i;
    //for(i=1000;i>0;i--){
    //    list1k=Insert_ToHead(list1k,i);
    //}
    
    for(i=1;i<1001;i++){
        list1k=Insert_ToLast(list1k,i);
    }
    
    Insert_Middle(list1k->Next,-1);
    list1k=Insert_ToHead(list1k,-10);
    list1k=Insert_ToHead(list1k,-20);
    
    list1k=Xoanutam2(list1k);
    
    list1k=Delete_Head(list1k);
    list1k=Delete_Last(list1k);
    
    duyetds(list1k);
    
    printf("\n------------dao1-------------\n");
    
    List *dsdao=daothutuds1(list1k);
    
    duyetds(dsdao);
    
    printf("\n-------------dao3------------\n");
    
    dsdao=daothutuds3(dsdao);
    
    duyetds(dsdao);
    
    freelist(dsdao);
    
    printf("\n------------dao2-------------\n");
    
    list1k=daothutuds2(list1k);
    
    duyetds(list1k);

 


    freelist(list1k);
    
    //getch();
    return 1;
}