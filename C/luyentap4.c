#include<stdio.h>
#include<stdlib.h>

#define Ineterfind -10000000

typedef struct nodeStack{
    int etems;
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

void push(Stack *s,int X){
    nodeStack *newStack = (nodeStack* )malloc(sizeof(nodeStack));
    if(newStack == NULL){
        printf("Memorry is full!");
        exit(1);
    }
    newStack->etems = X;
    newStack->next = s->top;
    
    s->top = newStack;
}

int pop(Stack *s){
    if(s == NULL) return Ineterfind;
    if(s->top == NULL) return Ineterfind;
    else{
        int X;
        X = s->top->etems;
        nodeStack *tmp = s->top;
        s->top = s->top->next;
        free(tmp);
        return X;
    }
}

void DestroyStack(Stack *s){
    while(!isEmpty(s)){
        pop(s);
    }
    free(s);
}

void chuyendoicoso(int n,int b){
    Stack *s = createStack();
    while(n != 0){
        push(s,n%b);
        n = n/b;
    }

    printf("\n");
    while(!isEmpty(s)){
        printf("%d",pop(s));
    }
    
    DestroyStack(s);

}




int main(){
    Stack *s = createStack();
    push(s,5);
    push(s,4);
    push(s,234);
    
    while(!isEmpty(s)){
        printf("%d\n",pop(s));
    }

    chuyendoicoso(10,2);

    DestroyStack(s);

}