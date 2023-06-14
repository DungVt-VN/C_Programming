#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxlen 100
typedef int ElementType;
typedef struct node{
    ElementType a;
    struct node *next; 
}node;

node *create_newnode(ElementType X){
    node *new = (node*)malloc(sizeof(node));
    if(new == NULL){
        printf("error");
        exit(0);
    }
    new->a = X;
    new->next = NULL; 
    return new;  
}

void duyetds(node *head){
    node *tg = head;
    printf("\n");
    while(tg != NULL){
        printf("%d\n",tg->a);
        tg = tg->next;
    }
}

void free_node(node *head){
    node *tg = head , *tmp;
    while(tg != NULL){
        tmp = tg->next;
        free(tg);
        tg = tmp;
    }
}

node *inser_tohead(ElementType X, node *head){
    node *tg = create_newnode(X);
    tg->next = head;
    return tg;
}


node *inser_tolast(ElementType X, node *head){
    node *tg = head;
    node *tmp = create_newnode(X);
    if(tg == NULL){
        tg = tmp;
    }
    else{
        while(tg->next != NULL){
        tg = tg->next;
    }
        tg->next = create_newnode(X);
    }
    return head;
}

node *delete_last(node *head){
    node *tg = head;
    if(head = NULL) return NULL;
    if(tg->next == NULL){ free(head); exit(0); }
    while(tg->next->next != NULL){
        tg = tg->next;
    }
    free(tg->next);
    tg->next = NULL;
    return head;
}

node *delete_head(node *head){
    if(head == NULL) return NULL;
    node *tg = head->next;
    free(head);
    return tg;
}

int main(){
    node *head = create_newnode(10);NULL;
    node *new = create_newnode(40);
    head->next = new;
    new = create_newnode(20);
    head->next->next = new;
    new = create_newnode(200);
    head->next->next->next = new;
    duyetds(head);
    head = inser_tohead(103,head);
    duyetds(head);
    inser_tolast(120,head);
    duyetds(head);
    printf("\nDelete_last");
    delete_last(head);
    duyetds(head);
    printf("\ndelete_head");
    head = delete_head(head);
    duyetds(head);
}

