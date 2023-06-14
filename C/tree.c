#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char name[256];
	struct node* leftMostChild;
	struct node* rightSibling;
}NODE;
NODE *root;
NODE *createNode(char name[]){// hàm tạo node
	NODE *temp = (NODE* )malloc(sizeof(NODE));
	strcpy(temp->name, name);
	temp->leftMostChild = NULL;
	temp->rightSibling = NULL;
	return temp;
}
NODE *addSibling(NODE *leftMost, char name[]){// hàm tạo anh em
	NODE *temp = createNode(name);
	leftMost->rightSibling = temp;
	return temp;
}
NODE *addLeft(NODE *r, char name[]){// hàm tạo con trái cùng
	NODE *temp = createNode(name);
	r->leftMostChild = temp;
	return temp;
}
void printTree(NODE *r){   // in cay
	if(r == NULL) return;    
	printf("%s: ",r->name);    
	NODE* p = r->leftMostChild;    
	while(p != NULL){        
		printf("%s ",p->name);        
		p = p->rightSibling;    
	}    
	printf("\n");    
	p = r->leftMostChild;    
	while(p != NULL){        
		printTree(p);        
		p = p->rightSibling;    
	}
}
void printTreeF(NODE *r, FILE* f){    //in cay ra file
	if(r == NULL) return;   
	fprintf(f,"%s ",r->name);   
	NODE *p = r->leftMostChild;   
	while(p != NULL){       
		fprintf(f,"%s ",p->name);  
		p = p->rightSibling;   
	}   
	fprintf(f," $\n");  
	p = r->leftMostChild;   
	while(p != NULL){      
		printTreeF(p,f);     
		p = p->rightSibling;  
	}
}
NODE *findNode(NODE *r, char name[]){    // tim 1 node
	if(r == NULL) return NULL;    
	if(strcmp(r->name,name) == 0) return r;    
	NODE* p = r->leftMostChild;    
	while(p != NULL){        
		NODE* q = findNode(p,name);        
		if(q != NULL) return q;       
		p = p->rightSibling;    
	}
}
NODE *Load(NODE *r){// doc file
	char name[256];
	FILE *fin = fopen("filein.txt", "r");
    if(fin == NULL){ 
        printf("Error");
        exit(1);
    }
	fscanf(fin, "%s ", &name);
	NODE *root = createNode(name);
	NODE *tree = root;
	fscanf(fin, "%s ", &name);
	tree = addLeft(tree, name);
	while(fin){
		fscanf(fin, "%s ", &name);
		if(strcmp(name, "$") != 0){
			tree = addSibling(tree, name);
		}else{
			fscanf(fin, "\n");
			break;
		}
	}
	int i = 0;
	while(fin){
		NODE *p;
		fscanf(fin, "%s ", &name);
		if(strcmp(name, "$") != 0){
			if(i <= 0){
				p = findNode(root, name);
				i++;
			}else if(i <= 1){
				p = addLeft(p, name);
				i++;
			}else{
				p = addSibling(p, name);
				i++;
			}
		}else{
			fscanf(fin, "\n");
			i = 0;
		}
		if(strcmp(name, "$$") == 0){
			break;
		}
	}
	fclose(fin); 
	return root;
}
void findChildren(NODE *root, char name[]){    // tim con
	NODE* p = findNode(root,name);    
	if(p == NULL) printf("Not Found %s\n",name);    
	else{        
		printf("Found %s with children: ",name);        
		NODE* q = p->leftMostChild;        
		while(q != NULL){            
			printf("%s ",q->name);     
			q = q->rightSibling;        
		}   
	}    
	printf("\n");
}
NODE *addLast(NODE *p, char name[]){    
	if(p == NULL) return createNode(name);   
	p->rightSibling = addLast(p->rightSibling, name);   
	return p;
}
void addChild(NODE *root, char name[]){// tao con
	char nameChild[256];    
	printf("Enter child name: ");scanf("%s", &nameChild);
	NODE* r = findNode(root,name);    
	if(r == NULL) return;    
	r->leftMostChild = addLast(r->leftMostChild, nameChild);
}
int height(NODE *p){    // tim chieu cao cua cay
	if(p == NULL) return 0;    
	int maxH = 0;    
	NODE* q = p->leftMostChild;   
	while(q != NULL){       
		int h = height(q);    
	    maxH = maxH < h ? h : maxH;     
		q = q->rightSibling;  
	}    
	return maxH + 1;
}
int count(NODE *r){    // dem so node cua cay
	if(r == NULL) return 0;    
	int sonode = 1;    
	NODE *q = r->leftMostChild;    
	while(q != NULL){        
		sonode += count(q);        
		q = q->rightSibling;    
	}    
	return sonode;
}
int main(){
	int luachon;
	do{
		printf("\n----------MENU----------");
		printf("\n1.Load");
		printf("\n2.Find Children");
		printf("\n3.Add Children");
		printf("\n4.Print Tree");
		printf("\n5.Height Tree");
		printf("\n6.Count Node of Tree");
		printf("\n7.Store Tree");
		printf("\n8.Exit menu!");
		printf("\nBan chon chuc nang so ");scanf("%d", &luachon);
		while(luachon < 1 || luachon > 8){
			printf("\nBan da chon sai chuc nang! Hay chon lai!");
			printf("\nBan chon chuc nang so ");scanf("%d", &luachon);
		}
		char name[256];
		switch(luachon){
			case 1:
				root = Load(root);
				printf("\nLoad file is okay!"); 
				break;
			case 2:
				printf("\nEnter parent name: ");scanf("%s", &name);
				findChildren(root, name);
				break;
			case 3:
				printf("\nEnter parent name: ");scanf("%s", &name);
				addChild(root, name);
				break;
			case 4:
				printf("\nTree is: \n");
				printTree(root);
				break;
			case 5:
				printf("\nHeight of tree is %d", height(root));
				break;
			case 6:
				printf("\nNode of tree is %d", count(root));
				break;
			case 7:
				printf("\nEnter the name of file out: ");scanf("%s", &name);
				FILE *fout = fopen(name, "w");
				printTreeF(root, fout);
				fclose(fout);
				break;
			case 8:
				printf("\nGOODBYE!");
				return;
		}
	}while(luachon);

}
