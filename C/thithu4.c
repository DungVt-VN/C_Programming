#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodeTree{
    int ID;
    char name[256];
    struct nodeTree *left;
    struct nodeTree *right;
    struct nodeTree *parent;
}node;

node *head = NULL;

node *makenode(int id, char name[]){
	node *newnode = (node* )malloc(sizeof(node));
	if(newnode==NULL) {
		printf("\nError to allocate memory");
		exit(1);
	}
	newnode->ID = id;
	strcpy(newnode->name,name);
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;
	return newnode;
}

node *AddToTree(node* r,int id,char name[]){
	if(r == NULL) return makenode(id,name);
	if(id > r->ID){
		r->right = AddToTree(r->right,id,name);
	}else if(id == r->ID){
	}else{
		r->left = AddToTree(r->left,id,name);
	}
	return r;
}
void Intangdan(node* root){
	if(root == NULL) return;
	Intangdan(root->left);
	printf("\n%d	%s",root->ID,root->name);
	Intangdan(root->right);
}

void Ingiamdan(node* root){
	if(root == NULL) return;
	Ingiamdan(root->right);
	printf("\n%d	%s",root->ID,root->name);
	Ingiamdan(root->left);
}

void DocFileA(node* root){
	int ID;
	char name[256];
	FILE *f = fopen("A.txt", "r+");
	while(!feof(f)){
		fscanf(f, "%d	%s",&ID,&name);
		root = AddToTree(root,ID,name);
	}
	Intangdan(root);
	head = root;
	fclose(f);
}


	int	dem = 0;
void DocFileB(node B[]){
	FILE *f = fopen("B.txt", "r+");
	while(!feof(f)){
		fscanf(f, "%d	%s",&B[dem].ID,&B[dem].name);
		dem ++;
	}
	fclose(f);
	for(int i = 0; i < dem; i++){
		printf("\n%d	%s",B[i].ID,B[i].name);
	}
	fclose(f);
}

// void TimkiemTree(node* root,node B[]){
// 	for(int i = 0; i < dem; i++){
// 		Delete(root,B[i].ID);
// 	}
// 	Intangdan(root);
// }

void TonghopTree(node* root,node B[]){
	for(int i = 0; i < dem; i++){
		root = AddToTree(root,B[i].ID,B[i].name);
	}
	Ingiamdan(root);
}
void Insoluong(node *root){
	
}

node *findmin(node* root){
	if(root->left == NULL) return root;
	else{
		return findmin(root->left);
	}
}

void DeleteNode(node* root,int id){
	if(id > root->ID){
		DeleteNode(root->right,id);
	}else if(id < root->ID){
		DeleteNode(root->left,id);
	}else{
		if(root->left == NULL){
			node *tmp = root;
			root = root->right;
			free(tmp);
			printf("\ndon 1\n");
		}else if(root->right == NULL){
			node *tmp = root;
			root = root->left;
			free(tmp);
			printf("\nDon 2\n");
		}else {
			node *tmp = findmin(root->right);
			root->ID = tmp->ID;
			strcpy(root->name,tmp->name);
			DeleteNode(root->right,tmp->ID);
			printf("\nDone 3\n");
		}
	}
}



void FreeTree(node* root){
	if(root == NULL) return;
	FreeTree(root->left);
	FreeTree(root->right);
	free(root);
}



int main(){
	int n;
	node *root = NULL;
	char n2;
	node B[100];
	while(1){
	    printf("\n*--------------------------------------------------*\n");
	    printf("*  [ 1 ] Doc file A.txt                            *\n");
	    printf("*  [ 2 ] Doc file B.txt                            *\n");
	    printf("*  [ 3 ] Tim kiem                                  *\n");
	    printf("*  [ 4 ] Tong hop                                  *\n");
	    printf("*  [ 5 ]                                           *\n");
	    printf("*  [ 6 ] Thoat                                     *\n");
	    printf("*--------------------------------------------------*\n");
	    printf("\n\n Nhap lua chon cua ban:   ");
	    scanf("%d",&n);
	    system("cls");
	    if(n == 6){
	    	printf("Good bye! ");
	    	break;
	    }else if(n < 1 || n > 6){
	    	printf("\nLua chon khong hop le nhap lai: ");
	    }else{
	        switch(n){
	        	case 1:
					DocFileA(root);
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 2:
					DocFileB(B);
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 3:
					root = head;
					fflush(stdin);
					printf("\n%d\n",root->ID);
					DeleteNode(root,1120);
					Intangdan(root);;
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 4:
					root = head;
					TonghopTree(root, B);
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 5:

	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		break;
	        }
        }
    }
	FreeTree(root);
    getch();
}
