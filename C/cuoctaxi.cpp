#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char user[25];
    char name[25];
    int diem;
}SinhVien;
typedef struct Node{
    SinhVien sv;
    struct Node *left;
    struct Node *right;
} TreeNode;

TreeNode* root = NULL;

TreeNode* createNode(SinhVien sv){
        TreeNode *Node = (TreeNode *)malloc(sizeof(TreeNode));
        if(Node == NULL) {
            printf("Error");
            exit(1);
        }
        strcpy(Node->sv.user, sv.user);
        strcpy(Node->sv.name, sv.name);
        Node->sv.diem = sv.diem ;
        Node->left = NULL;
        Node->right = NULL;
        return Node;
}
TreeNode* Insert(TreeNode *r,SinhVien sv) {
    printf("helloddwe");
    if(r == NULL)
       {   printf("\n Hello \n"); 
           r = createNode(sv);
            return r;
       }

    if (strcmp(r->sv.user, sv.user) >0 )
        r->left = Insert(r->left,sv);
    else if (strcmp(r->sv.user, sv.user) < 0 )
        r->right = Insert(r->right,sv);
    return r;
}
void Doc_File(root) {
    FILE *fptr;
    SinhVien sv;
    fptr = fopen("SinhVien.txt", "r");
    while (!feof(fptr)) {
        fscanf(fptr,"%s", sv.user);
        fscanf(fptr,"%s", sv.name);
        fscanf(fptr,"%d",&sv.diem);
        //printf("%s ", sv.user);
        //printf("%s ", sv.name);
        //printf("%d \n",sv.diem);
        root = Insert(root,sv);
    }
    printf("\n%s",root->sv.user);
    fclose(fptr);
}

void PreOrder(TreeNode* root) {
    if(root == NULL) return ;
        printf("%s ", root->sv.user);
        printf("%s ", root->sv.name);
        printf("%d \n",root->sv.diem);
        PreOrder(root->left);
        PreOrder(root->right);
}

int main() {
    SinhVien sv;
    Doc_File(root);  
    printf("Hello");
    PreOrder(root);
    return 0;
}
