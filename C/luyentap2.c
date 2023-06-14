#include<stdio.h>
#include<stdlib.h>

typedef struct Polynom {
    int coeff;
    int pow;
    struct Polynom *link;
}Poly;

Poly* create(int coeff,int pow){
    Poly *newnode = (Poly*)malloc(sizeof(Poly));
    if(newnode == NULL){
        printf("Error!");
        exit (1);
    }
    newnode->coeff = coeff;
    newnode->pow = pow;
    newnode->link = NULL;

    return newnode;
}

Poly *Insert_toHead(Poly *px,int coeff,int pow){
    Poly* newnode = create(coeff,pow);
    newnode->link = px;
    return newnode;
}

void duyetds(Poly *px){
    Poly *tg = px;
    printf("\n");
    while(tg != NULL){
        printf("%02d|%d  ",tg->coeff,tg->pow);
        tg= tg->link;
    }
}
void freePoly(Poly *px){
    Poly *tg = px;
    while(tg != NULL){
        Poly *tg1 = tg->link;
        free(tg);
        tg = tg1;
    }
}

Poly* SumtwoPol(Poly *px,Poly *px1){
    Poly* node = (Poly*)malloc(sizeof(Poly));
    Poly *ptr1 = px, *ptr2 = px1;
    Poly *ptr,*PolySum = node;

    while(ptr1 != NULL && ptr2 != NULL){
        ptr = node;
        if(ptr1->pow > ptr2->pow){
            node->coeff = ptr2->coeff;
            node->pow = ptr2->pow;
            ptr2 = ptr2->link;

        }else if(ptr1->pow < ptr2->pow){
            node->coeff = ptr1->coeff;
            node->pow = ptr1->pow;
            ptr1 = ptr1->link;

        }else{
            node->coeff = ptr1->coeff + ptr2->coeff;
            node->pow = ptr1->pow;

            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }

        node = (Poly *)malloc(sizeof(Poly));
        ptr->link = node;
    }

    if(ptr1 == NULL){
        while(ptr2 != NULL){
            
            node->coeff = ptr2->coeff;
            node->pow = ptr2->pow;
            ptr2 = ptr2->link;
            ptr = node;
            node = (Poly*)malloc(sizeof(Poly));
            ptr->link = node;
        }
    }
    else if(ptr2 == NULL){
        while(ptr1 != NULL){
            
            node->coeff = ptr1->coeff;
            node->pow = ptr1->pow;
            ptr1 = ptr1->link;
            ptr = node;
            node = (Poly*)malloc(sizeof(Poly));
            ptr->link = node;
        }
    }
    node = NULL;
    ptr->link = node;
    return PolySum;
}

Poly *nhanX(Poly *px){
    Poly *node = (Poly*)malloc(sizeof(Poly));
    Poly *ptr1 = px, *NhanX = node;
    Poly *ptr;
    while(ptr1 != NULL){
        ptr = node;
        node->coeff = ptr1->coeff;
        node->pow = ptr1->pow+1;
        ptr1 = ptr1->link;
        node = (Poly*)malloc(sizeof(Poly));
        ptr->link = node;
    }
    node = NULL;
    ptr->link = node;
    return NhanX;
}

int main(){
    Poly *px = NULL;
    px = Insert_toHead(px,4,3);
    px = Insert_toHead(px,-2,1);
    px = Insert_toHead(px,1,0);
    duyetds(px);

    Poly *px1 = NULL;
    px1 = Insert_toHead(px1,1,4);
    px1 = Insert_toHead(px1,-5,3);
    px1 = Insert_toHead(px1,4,2);
    px1 = Insert_toHead(px1,1,1);
    px1 = Insert_toHead(px1,4,0);
    duyetds(px1);


    printf("\nTong hai ham");
    Poly *Sum = SumtwoPol(px,px1);
    duyetds(Sum);

    printf("\nNhan voi X");
    Poly *NhanX = nhanX(px1);
    duyetds(NhanX);

    free(NhanX);
    freePoly(Sum);
    freePoly(px1);
    freePoly(px);
}
