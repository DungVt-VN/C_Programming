#include <stdio.h>
#include <stdlib.h>














 

#define Infinity 'x' 

 

typedef struct _StackNode {
    char item;
    struct _StackNode *next;
} StackNode;

 

typedef struct _Stack {
    StackNode *top;
}Stack;

 


Stack *createStack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) {printf("Error in memory allocation\n");exit(0);}
    s->top=NULL;
    return s;
}

 

int isEmpty(Stack *s){
    if(s==NULL) return 1;
    if(s->top==NULL) return 1;
    else return 0;
}

 

 

void push(Stack *s,char X){
    if(s==NULL) return;
    StackNode *newnode = (StackNode*)malloc(sizeof(StackNode));
    if(newnode==NULL) {printf("Error in memory allocation\n");exit(0);}
    newnode->item=X;
    newnode->next=NULL;
    
    newnode->next=s->top;
    s->top=newnode;
}

 


char pop(Stack *s){
    if(s==NULL) return Infinity;
    if(isEmpty(s)) return Infinity;
    char X = s->top->item;
    StackNode *tg = s->top;
    s->top=s->top->next;
    
    free(tg);
    return X;
}

 

void StackDestroy(Stack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    free(s);
}

 


void ghinhan(char X[], int size){
    int i;
    printf("\n");
    for(i=0;i<size;i++)
    {
        printf(" %c ",X[i]);
    }    
}

 

/* kiem tra bieu thuc co phai ngoac dung ko? */
int kthople(char X[], int size){
    int i, kq=-1;
    Stack *s=NULL;

 

    /* yeu cau phai ko chua dau hoi */
    for(i=0;i<size;i++)
    {
        if(X[i]=='?') break;
    }
    
    if(i<size) return 0;
    
    /* bat dau kiem tra xau co phai ngoac dung ko?*/
    s = createStack();
    
    for(i=0;i<size;i++){
        if(X[i]=='(')
            push(s,X[i]);
        else { //X[i] la ngoac dong
            if(isEmpty(s)){//neu st rong
                kq=0;
                break;
            }
            pop(s);
        }
    }
    
    if(kq==-1){
        if(isEmpty(s))//neu st rong
             kq=1;
        else kq=0;
    }
    
    StackDestroy(s);
    return kq;
}

 

/* thuat toan quay lui de in ra cac xau hop le khi thay dau hoi */
void inbthople(char X[], int size){
    int i;
    for(i=0;i<size;i++)
    {
        if(X[i]=='?') break;
    }
    
    if(i==size) {
        /*ngay ca khi xau dau vao ko chua dau hoi ma van hop le ---> in ra */
        if(kthople(X,size)==1) ghinhan(X,size);
        return;
    }
    
    X[i]='(';
    if(kthople(X,size)==1) ghinhan(X,size);
    else inbthople(X, size);
    
    X[i]=')';
    if(kthople(X,size)==1) ghinhan(X,size);
    else inbthople(X, size);
    
    X[i]='?';
}

 


int main(){
    char X0[4]={'(','?','?',')'};
    inbthople(X0,4);
    printf("\n------------\n");
    char X1[6]={'(','?','?','?','?',')'};
    inbthople(X1,6);
    printf("\n------------\n");
    char X2[4]={'(','(',')',')'};
    inbthople(X2,4);
    
    //printf("%d\n",kthople(X0,4));
    
    return 1;
}