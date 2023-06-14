#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define Interfind 'x'


typedef struct nodeStack{
    char etems;
    struct nodeStack *next;
}nodeStack;

typedef struct Stack{
    nodeStack *top;
}Stack;

Stack *createStack(){
    Stack *s = (Stack* )malloc(sizeof(Stack));
    if(s == NULL){
        printf("Error!");
        exit(1);
    }
    s->top = NULL;
    return s;
}

int isEmpty(Stack *s){
    if(s == NULL) return 1;
    if(s->top == NULL) return 1;
    else return 0;
}

void push(Stack *s, int X){
    nodeStack *newStack = (nodeStack* )malloc(sizeof(nodeStack));
    if(newStack == NULL) {
        printf("Memory is full!");
        exit(1);
    }
    newStack->etems = X;
    newStack->next = s->top;
    s->top = newStack;
}

char pop(Stack *s){
    if(s == NULL) return Interfind;
    if(s->top == NULL) return Interfind;
    else {
        int X = s->top->etems;
        nodeStack *tmp = s->top;
        s->top = s->top->next;
        free(tmp);
        return X;
    }
}

void destroyStack(Stack *s){
    while(!isEmpty(s)){
        pop(s);
    }
    free(s);
}


int kiemtra(char X,char X1){
    if(X == '(' && X1 == ')' ) return 1;
    if(X == '[' && X1 == ']' ) return 1;
    if(X == '{' && X1 == '}' ) return 1;
    return 0;
}


int kiemtrangoac(char A[],int n){
    Stack *s = createStack();
    int check = -1;
    for(int i = 0; i < n; i++){
        if( A[i] == '(' || A[i] == '[' || A[i] == '{')
            push(s,A[i]);
        else{
            if(kiemtra(pop(s),A[i]) == 0) return 0;
            else check = 1;
        }
    }

    if(isEmpty(s)){
        check = 1;
    }else check = 0;

    destroyStack(s);
    return check;
}


int main(){
    char X1[] = {'(','{','}',')',']','['};
    printf("\n Ketqua: %d \n",kiemtrangoac(X1,5));
    
    char X2[] = {'(','{','}',')','[',']'};
    printf("\n Ketqua: %d \n",kiemtrangoac(X2,4));
    
    char X3[] = {'(','{','}',')',')'};
    printf("\n Ketqua: %d \n",kiemtrangoac(X3,5));
    
    char X4[] = {'(','{','[',']','}',']'};
    printf("\n Ketqua: %d \n",kiemtrangoac(X4,6));
    
    return 1;
}
