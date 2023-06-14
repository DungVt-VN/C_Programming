#include<stdio.h>
#include<stdlib.h>
#define MAX 200

typedef struct list{
	int arr[MAX];
	int last;
}list;

list* create(){
	list *pt = (list*)malloc(sizeof(list));
	if(pt == NULL){
		printf("\nError1");
		exit(0);
	}
	pt->last = -1;
		return pt;
}

void insert(int x, int p, list *pt){
	if(p == MAX-1){
		printf("\nKhong con bo nho!");
		exit(0);
	}else if(p < 0 || p > pt->last+1){
		printf("\nError2");
		exit(0);
	}else{
		for(int i = pt->last+1; i >= p; i--){
			pt->arr[i+1] = pt->arr[i];
		}
		pt->arr[p] = x;
		pt->last = pt->last+1; 
	}
}

int duyetds(list *pt){
	for(int i= 0; i < pt->last+1;i++ ){
		printf("\n%d",pt->arr[i]);
	}
}

int main(){
	list *pt = create();
    insert(5,0,pt);
    insert(4,1,pt);
    insert(7,2,pt);
    insert(10,3,pt);
    
    duyetds(pt);
}

