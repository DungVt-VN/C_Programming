// Danh sách liên kết đơn;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

Node *createNode(int key)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        printf("Error!");
        exit(1);
    }
    NewNode->key = key;
    NewNode->next = NULL;
    return NewNode;
}

void DuyetDS(Node *head)
{
    Node *tg = head;
    printf("\nDanh sach la:\n");
    while (tg != NULL)
    {
        printf("%d     ", tg->key);
        tg = tg->next;
    }
    printf("\nFree done!");
}

void freeDS(Node *head)
{
    Node *tg = head;
    while (tg != NULL)
    {
        Node *tmp = tg->next;
        free(tg);
        tg = tmp;
    }
}

Node *InsertoHead(int key, Node *head)
{
    Node *NewNode = createNode(key);
    NewNode->next = head;
    return NewNode;
}

Node *InsertoLast(int key, Node *head)
{
    Node *NewNode = createNode(key);
    if (head == NULL)
    {
        head = NewNode;
        return head;
    }
    Node *tg = head;
    while (tg->next != NULL)
    {
        tg = tg->next;
    }
    tg->next = NewNode;
    return head;
}
Node *Insert_Mid(Node *head, Node *prev,int key)
{
    if(prev == NULL){
        head = InsertoLast(key,head);
        return head;
    }
    Node *NewNode = createNode(key);
    NewNode->next = prev->next;
    prev->next = NewNode;
    return head;
}

Node *DeleteHead(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

Node *DeleteNode(Node *head, Node *prev)
{
    if (prev == NULL)
    {
        exit(0);
    }
    Node *tg = head;
    while (tg->next != prev)
    {
        tg = tg->next;
    }
    Node *tmp = tg->next;
    tg->next = tg->next->next;
    free(tmp);
    return head;
}

Node *DeleteLast(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *tg = head;
    while (tg->next->next != NULL)
    {
        tg = tg->next;
    }
    free(tg->next);
    tg->next = NULL;
    return head;
}


Node *Dao_thu_tu_1(Node* head){
    if(head == NULL || head->next== NULL)
        return head;
    Node *tg_1 = NULL;
    Node *tg_2 = head;
    Node *tg_3 = head->next;
    while(tg_3!=NULL){
        tg_2->next = tg_1;
        tg_1 = tg_2;
        tg_2 = tg_3;
        tg_3 = tg_3->next;
    }
    tg_2->next = tg_1;
    return tg_2;
}

Node *Dao_thu_tu_2(Node *head){
    if(head == NULL)
        return head;
    Node *tg = head;
    Node *head2 = NULL;
    while(tg!= NULL){
        head2 = InsertoHead(tg->key, head2);
        tg = tg->next;
    }
    return head2;
}

Node *Dao_thu_tu_3(Node *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;
    Node *l = Dao_thu_tu_3(head->next);
    head->next->next = head;
    head->next = NULL;
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


int main()
{
    Node *head = NULL;
    /*     head = InsertoHead(11,head);
        head = InsertoHead(18,head);
        head = InsertoHead(13,head);
        head = InsertoHead(14,head); */

    /* head = InsertoLast(11, head);
    head = InsertoLast(12, head);
    head = InsertoLast(13, head);
    head = InsertoLast(14, head);
    head = Insert_Mid(head,head->next->next,154); */
    //    head = DeleteHead(head);
    //    head = DeleteLast(head);

    //    DeleteNode(head,head->next->next);

    for(int i = 100; i > 0 ; i--){
        head = InsertoHead(i,head);
    }

    //    head = Dao_thu_tu_1(head);
    //    head = Dao_thu_tu_2(head);
    head = Dao_thu_tu_3(head);

    DuyetDS(head);
    freeDS(head);
}   