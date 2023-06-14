#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    int X;
    struct List *next;
}List;

List* createList(int X){
    List *newnode = (List *)malloc(sizeof(List));
    if(newnode==NULL)   printf("Create error! ");
    else{
        newnode->X = X;
        newnode->next = NULL;
    }
    return newnode;
}

void duyetlist(List *head){
    List *tg = head;
    printf("\n");
    while(tg != NULL){
        printf("%d  ",tg->X);
        tg = tg->next;
    }
}

void freeList(List* head){
    List *tg = head, *tmp;
    while(tg != NULL){
        tmp = tg->next;
        free(tg);
        tg = tmp;
    }
}

List* Insertohead(List* head,int X){
    List* newnode = createList(X);
    newnode->next = head;
    return newnode;
}


List* Insertolast(List* head,int X){
    List* newnode = createList(X);
    List* tg = head;
    while(tg->next != NULL){
        tg = tg->next;
    }
    tg->next = newnode;
    return head;
}

//Dao list 

List* Daolist1(List* head){
    List* tg = head;
    List* head2 = NULL;
    while(tg != NULL){
        head2 = Insertohead(head2,tg->X);
        tg = tg->next;
    }
    return head2;
}

List* Daolist2(List* link1){
    List* t1 = NULL;
    List* t2 = link1;
    List* t3 = link1->next;
    while(t3 != NULL){
        t2->next = t1;
        t1 = t2;
        t2 = t3;
        t3 = t3->next;
    }
    t2->next = t1;
    return t2;
}

List* Daolist3(List* link1){
    if(link1 == NULL) return NULL;
    if(link1->next == NULL) return link1;
    List* l = Daolist3(link1->next);
    link1->next->next = link1;
    link1->next = NULL;
    return l;
}

List* Delete_head(List* link1){
    if(link1 == NULL) return NULL;
    List* tg = link1;
    free(link1);
    return tg->next;
}

List* Delete_Last(List* link1){
    if(link1 == NULL) return NULL;
    if(link1->next == NULL){
        free(link1);
        return NULL;
    }
    List* tg = link1;
    while(tg->next->next != NULL){
        tg = tg->next;
    }
    free(tg->next);
    tg->next = NULL;
    
    return link1;
}

List* xoanutam1(List* link1){
    if(link1 == NULL) return NULL;
    while(link1->X < 0) link1 = Delete_head(link1);
    List* tg = link1;
    while(tg != NULL){
        if(tg->next == NULL) break;
        if(tg->next->X < 0){
            List* tg1 = tg->next;
            tg->next = tg->next->next;
            free(tg1);
        }else tg = tg->next;
    }
    return link1;
}

List* xoanutam2(List* link1){
    List *tg1 = NULL, *tg2 = link1;
    while(tg2!=NULL){
        if(tg2->X < 0){
            if(tg1 == NULL){
                link1 = link1->next;
                free(tg2);
                tg2 = link1;
            }else{
                tg1->next = tg2->next;
                free(tg2);
                tg2 = tg1->next;
            }
        }else {
            tg1 = tg2;
            tg2 = tg2->next;
        }
    }
    return link1;
}


int main(){
/*     List* head = createList(10);
    List* newnode = createList(20);
    head->next = newnode;
    newnode = createList(59);
    head->next->next = newnode;
    duyetlist(head);
    printf("\n\n\n");

 */ 
    List* newnode;
    List* link1 = NULL, *tmp;
    for(int i = 1; i <= 20; i++){
        newnode = createList(i);
        if(link1 == NULL) link1 = newnode;
        else tmp->next = newnode;
        tmp = newnode;
    }
    link1 = Insertohead(link1,111);
    link1 = Insertohead(link1,-1);
    link1 = Insertohead(link1,-12);
    link1 = Insertohead(link1,11);
    link1 = Insertohead(link1,12);
    link1 = Insertohead(link1,145);
    link1 = Insertohead(link1,-123);
    link1 = Insertolast(link1,-12);
    link1 = Insertohead(link1,-123);

    
    duyetlist(link1);

    /* link1 = Delete_head(link1);
    duyetlist(link1);

    printf("\nDelete last:");
    link1 = Delete_Last(link1);
    duyetlist(link1); */
    
    /* printf("\nXoa nut am 1:");
    link1 = xoanutam1(link1);
    duyetlist(link1); */

    printf("\nXoa nut am 2:");
    link1 = xoanutam2(link1);
    duyetlist(link1);
    /* head = Insertohead(head,12);
    head = Insertohead(head,1000);
    duyetlist(head);
    head = Insertolast(head,120);
    head = Insertolast(head,210);
    duyetlist(head);
    printf("\nDao thu tu 1 \n\n");
    List* head2 = NULL;
    head2 = Daolist1(link1);
    duyetlist(head2);

    printf("\nDao thu tu 2 \n\n");
    head2 = Daolist2(head2);
    duyetlist(head2);

    printf("\nDao thu tu 3 \n\n");
    head2 = Daolist3(head2);
    duyetlist(head2);

    freeList(link1);
    freeList(head2);
    */

}