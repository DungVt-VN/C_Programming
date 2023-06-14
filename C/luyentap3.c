#include<stdio.h>
#include<stdlib.h>

typedef struct dllist{
    int X;
    struct dllist* next;
    struct dllist* prev;
}dllist;

dllist *create(int X){
    dllist *newnode = (dllist *)malloc(sizeof(dllist));
    if(newnode == NULL){
        printf("Error!");
        exit(1);
    }
    newnode->X = X;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

dllist *Insert_toHead(dllist *head,int X){
    dllist *newnode = create(X);
    newnode->next = head;
    if(head != NULL)
    head->prev = newnode;

    return newnode;
}

void duyetds(dllist *head){
    dllist *tg =head;
    printf("\n");
    while(tg != NULL){
        printf("%d  ",tg->X);
        tg = tg->next;
    }
}

void freelist(dllist *head){
    dllist *tg = head;
    dllist *tg1;
    while(tg != NULL){
        tg1 = tg->next;
        free(tg);
        tg = tg1;
    }
}

//tinh tong cac nut trong dslk voi con tro bat ki:

int sum(dllist *p){
    int Sum = 0;
    dllist *prt = p;
    while( prt != NULL){
        Sum+=prt->X;
        prt = prt->next;
    }
    prt = p;
    while(prt!= NULL){
        Sum+=prt->X;
        prt = prt->prev;
    }
    return Sum-p->X;
}


//xoa nut bat ki voi con tro bat ki

dllist *Delete(dllist *p){
    if(p == NULL) return NULL;
    if(p->prev == NULL){
        if(p->next == NULL){
            free(p);
            return NULL;
        }else{
            p->next->prev = NULL;
            dllist *tmp = p->next;
            free(p);
            return tmp;
        }
    }else{
        p->prev->next = p->next;
        p->next->prev = p->prev;
        dllist *tg = p;
        while(tg->prev != NULL){
            tg = tg->prev;
        }
        free(p);
        return tg;
    }
}

//xoa nut le bat ki voi con tro bat ki

dllist *Deletele(dllist *p){
    dllist *tg = p;
    while(tg->prev != NULL){
        tg = tg->prev;
    }
    while(tg != NULL){
        if(tg->next == NULL) {
            if(tg->X %2 == 0) break;
            else {
                dllist *tmp2 = tg->prev->prev;
                tg->prev->next = NULL;
                free(tg);
                tg = tmp2;
            }
        }
        if(tg->X%2 != 0){
            tg->prev->next = tg->next;
            tg->next->prev = tg->prev;
            dllist *tmp = tg->next;
            free(tg);
            tg = tmp;
        }else 
            tg = tg->next;
    }

    while(tg->prev != NULL){
        tg = tg->prev;
    }
    return tg;
    
}


int main(){
    dllist *head = NULL;
    head = Insert_toHead(head,43);
    head = Insert_toHead(head,43);
    head = Insert_toHead(head,43);
    head = Insert_toHead(head,43);
    head = Insert_toHead(head, 120);
    head = Insert_toHead(head, 10);
    head = Insert_toHead(head,20);
    head = Insert_toHead(head,13);
    head = Insert_toHead(head,43);
    head = Insert_toHead(head,30);
    head = Insert_toHead(head,40);

    duyetds(head);

    printf("\nSum = %d ", sum(head->next->next));

    /* printf("\nXoa nut :");
    head = Delete(head->next->next->next);
    duyetds(head); */

    printf("\nXoa nut le :");
    head = Deletele(head);
    duyetds(head);

    freelist(head);

}