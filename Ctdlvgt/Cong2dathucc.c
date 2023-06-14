#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

 

typedef struct Polynom {
    int coeff;
    int pow;
    struct Polynom *link;
} Poly;

 

Poly *createNewNode(int coeff, int pow){
    Poly *newnode=(Poly*)malloc(sizeof(Poly));
    if(newnode==NULL){
        printf("Error in memory allocation\n");
        exit(0);
    }
    
    newnode->coeff=coeff;
    newnode->pow=pow;
    newnode->link=NULL;
    
    return newnode;
}

 


void duyetds(Poly *head){
    Poly *tg=head;
    printf("\n");
    while(tg!=NULL){
        printf("%d|%d ",tg->coeff,tg->pow);
        tg=tg->link;
    }    
}

 

 
void freelist(Poly *head){
    Poly *tg=head,*temp;

 

    while(tg!=NULL){
        temp=tg->link;
        free(tg);
        tg=temp;
    }    
}

 


Poly *Insert_ToHead(Poly *head, int coeff, int pow)
{
    Poly *newnode = createNewNode(coeff, pow);
    newnode->link = head;
    return newnode;
}

 


Poly *SumTwoPol(Poly  *px, Poly *qx){
    Poly *node=(Poly *)malloc (sizeof(Poly));
    Poly *ptr,*PolySum=node;
    Poly *ptr1=px, *ptr2=qx;
    
    while(ptr1!=NULL && ptr2!=NULL){
        ptr=node;
        if (ptr1->pow > ptr2->pow ) {
            node->coeff=ptr2->coeff;
            node->pow=ptr2->pow;
            ptr2=ptr2->link;//update ptr list 2
        }
        else if ( ptr1->pow < ptr2->pow )
        {
            node->coeff=ptr1->coeff;
            node->pow=ptr1->pow;
            ptr1=ptr1->link;//update ptr list 1
        }
        else
        {
            node->coeff=ptr2->coeff+ptr1->coeff;
            node->pow=ptr2->pow;
            ptr1=ptr1->link;//update ptr list 1
            ptr2=ptr2->link;//update ptr list 2
        }
        node=(Poly *)malloc (sizeof(Poly));
        ptr->link=node;//update ptr list 3
    }
    
    if (ptr1==NULL)//end of list 1
    { 
        while(ptr2!=NULL){
            node->coeff=ptr2->coeff; 
            node->pow=ptr2->pow;
            ptr2=ptr2->link;//update ptr list 2
            ptr=node; 
            node=(Poly *)malloc (sizeof(Poly));
            ptr->link=node; //update ptr list 3
        } 
    }
    else if (ptr2==NULL)//end of list 2
    {
        while(ptr1!=NULL) {
            node->coeff=ptr1->coeff;
            node->pow=ptr1->pow;
            ptr1=ptr1->link;//update ptr list 2
            ptr=node;
            node=(Poly *)malloc (sizeof(Poly));
            ptr->link=node;//update ptr list 3
        }
    }
    
    node=NULL;
    ptr->link=node;
    
    return PolySum;
}

 

Poly *nhanX(Poly *head){
    Poly *node=(Poly *)malloc (sizeof(Poly));
    Poly *ptr1=head,*ptr;
    Poly *polyout=node;
    
    while(ptr1!=NULL)
    {
        ptr=node;
        node->coeff=ptr1->coeff;
        node->pow=ptr1->pow + 1;
        ptr1=ptr1->link;
        node=(Poly *)malloc (sizeof(Poly));
        ptr->link=node;
    } 
    
    node=NULL;
    ptr->link=node;
    
    return polyout;
}

 

int main(){
    Poly *px=NULL;
    px=Insert_ToHead(px,4,3);
    px=Insert_ToHead(px,-2,1);
    px=Insert_ToHead(px,1,0);
    duyetds(px);
    Poly *qx=NULL;
    qx=Insert_ToHead(qx,1,4);
    qx=Insert_ToHead(qx,-5,3);
    qx=Insert_ToHead(qx,4,2);
    qx=Insert_ToHead(qx,1,1);
    qx=Insert_ToHead(qx,4,0);
    printf("\n");
    duyetds(qx);
    
    Poly *sumpoly=SumTwoPol(px,qx);
    printf("\n");
    duyetds(sumpoly);
    
    Poly *nx=nhanX(sumpoly);
    printf("\n");
    duyetds(nx);
    
    freelist(qx);
    freelist(px);
    freelist(sumpoly);
    freelist(nx);
    return 1;
}