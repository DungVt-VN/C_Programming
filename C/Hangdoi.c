#include<stdio.h>
#include<stdlib.h>

typedef struct nodeQueue{
    int etems;
    struct nodeQueue *next;
}nodeQueue;

typedef struct Queue{
    nodeQueue *font;
    nodeQueue *back;
}Queue;

Queue *createQueue(){
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->font = NULL;
    newQueue->back = NULL;
    return newQueue;
}

int IsEmpty(Queue *q){
    if(q->font == NULL) return 1;
    if(q->back == NULL) return 1;
    else return 0;
}

void duyetQueue(Queue *q){
    nodeQueue *tg = q->font;
    printf("\nDanh sach la:\n");
    while(tg != NULL){
        printf("%d\n", tg->etems);
        tg = tg->next;
    }
}

void freeQueue(Queue *q){
    nodeQueue *tg = q->font;
    while(tg != NULL){
        nodeQueue *tmq = tg->next;
        free(tg);
        tg = tmq;
    }
    free(q);
}

nodeQueue *enQueue(Queue *q,int X){
    nodeQueue *newQueue = (nodeQueue* )malloc(sizeof(nodeQueue));
    newQueue->etems = X;
    newQueue->next = q->font;
    if(q->font == NULL){
        q->font = q->back = newQueue;
    }else{
        q->font = newQueue;
    }
}
nodeQueue *deQueue(Queue *q){
    if( q->font == NULL){
        printf("\nError!");
        exit(0);
    }else if(q->font == q->back){
        printf("\nLay ra: %d",q->back->etems);
        q->font = NULL;
        q->back = NULL;
    }else{
        printf("\nLay ra: %d",q->back->etems);
        nodeQueue *tg =q->font;
        while(tg->next->next != NULL){
            tg = tg->next;
        }
        nodeQueue *tmp = tg->next;
        q->back = tg;
        tg->next = NULL;
        free(tmp);
    }
}

int sizeofQueue(Queue *q){
    nodeQueue *tg = q->font;
    int check = 0;
    while(tg != NULL){
        check ++;
        tg = tg->next;  
    }
    return check;
}


int main(){
    Queue *q = createQueue();
    enQueue(q,12);
    enQueue(q,112);
    enQueue(q,123);
    printf("\nSize of Queue is: %d",sizeofQueue(q));

    duyetQueue(q);

    deQueue(q);
    printf("\nSize of Queue is: %d",sizeofQueue(q));
    printf("\nFont is: %d",q->font->etems);
    duyetQueue(q);
    deQueue(q);
    duyetQueue(q);
    
    printf("\nDanh sach rong la ");
    if(IsEmpty(q) == 1){
        printf("Trust");
    }else printf("False");
    deQueue(q);

    printf("\nBye!");
    freeQueue(q);
}