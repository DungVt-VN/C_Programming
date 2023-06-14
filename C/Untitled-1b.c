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

 

int ktloai(char c,char Xi){
    if(c=='(' && Xi==')') return 1;
    if(c=='[' && Xi==']') return 1;
    if(c=='{' && Xi=='}') return 1;
    return 0;
}

 

int ktbt(char X[], int n)
{
    int i, kq=-1;
    Stack *s=NULL;
    s = createStack();
    
    for(i=0;i<n;i++){
        if((X[i]=='{')||(X[i]=='[')||(X[i]=='('))
            push(s,X[i]);
        else { //X[i] la ngoac dong
            if(isEmpty(s)){//neu st rong
                kq=0;
                break;
            }
            char c=pop(s);
            if(ktloai(c,X[i])==0){//neu khac loai
                kq=0;
                break;
            }
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

 

int main(){
    char X1[] = {'(','{','}',')',']'};
    printf("\n Ketqua: %d \n",ktbt(X1,5));
    
    char X2[] = {'(','{','}',')'};
    printf("\n Ketqua: %d \n",ktbt(X2,4));
    
    char X3[] = {'(','{','}',')',')'};
    printf("\n Ketqua: %d \n",ktbt(X3,5));
    
    char X4[] = {'(','{','[',']','}',']'};
    printf("\n Ketqua: %d \n",ktbt(X4,6));
    
    return 1;
}