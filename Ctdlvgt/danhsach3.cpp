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

 


int main(){
    /*
    List *head=NULL;
    head=(List*)malloc(sizeof(List));
    if(head==NULL){
        printf("Error in memory allocation\n");
        exit(0);
    }
    
    head->Inf=10;
    head->Next=NULL;
    
    List *newnode =(List*)malloc(sizeof(List));
    if(newnode==NULL){
        printf("Error in memory allocation\n");
        exit(0);
    }
    
    newnode->Inf=20;
    newnode->Next=NULL;
    
    head->Next=newnode;
    
    
    newnode =(List*)malloc(sizeof(List));
    if(newnode==NULL){
        printf("Error in memory allocation\n");
        exit(0);
    }
    
    newnode->Inf=30;
    newnode->Next=NULL;
    
    head->Next->Next=newnode;
    */
    
    List *head=createNewNode(10);
    List *newnode=createNewNode(20);
    head->Next=newnode;
    newnode=createNewNode(30);
    head->Next->Next=newnode;
    
    duyetds(head);
    
    printf("\n---------Tao ds 1k nut --------\n");
    
    List *list1k=NULL, *tg, *mynewnode;

    
    for(int i=1;i<1001;i++){
        mynewnode=createNewNode(i);
        if(list1k==NULL){
            list1k = mynewnode;
    	}
        else
            tg->Next=mynewnode;
        tg=mynewnode;
    	
    }
    
    duyetds(list1k);
    
    freelist(list1k);
    freelist(head);
    
    //getch();
    return 1;
}
