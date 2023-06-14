#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct nodeTree{
    char W;
    struct nodeTree *leftmost_child;
    struct nodeTree *right_sibling;
}nodeTree;

nodeTree *createNode(char s){
    nodeTree *newnode = (nodeTree* )malloc(sizeof(nodeTree));
    if(newnode == NULL){
        printf("Error!");
        exit(0);
    }
    newnode->W = s;
    newnode->leftmost_child = NULL;
    newnode->right_sibling = NULL;

    return newnode;
}

void duyettruoc(nodeTree *r){
    if(r == NULL) return;
    printf("%c ",r->W);
    nodeTree *tg = r->leftmost_child;
    while(tg != NULL){
        duyettruoc(tg);
        tg = tg->right_sibling;
    }
}

void duyetsau( nodeTree *r ){
    if(r == NULL) return;
    nodeTree *tg = r->leftmost_child;
    while(tg != NULL){
        duyetsau(tg);
        tg = tg->right_sibling;
    }
    printf("%c ",r->W);
}


void duyetgiua (nodeTree *r )
{
    if(r==NULL) return;
    if (r->leftmost_child==NULL) printf("%c ",r->W);
    else
    {
        duyetgiua(r->leftmost_child);
        printf("%c ",r->W);

        nodeTree *tg=r->leftmost_child->right_sibling;
        while(tg!=NULL){
            duyetgiua(tg);
            tg=tg->right_sibling;
        }
    }
}


void freeTree(nodeTree *r){
    if(r == NULL) return;
    nodeTree *tg = r->leftmost_child;
    nodeTree *luutru = NULL;
    while(tg !=NULL){
        luutru = tg->right_sibling;
        freeTree(tg);
        tg = luutru;
    }
    free(r);
}

int tongnut(nodeTree *r){
    if(r == NULL) return 0;
    int dem = 1;
    nodeTree *tg = r->leftmost_child;
    while(tg != NULL){
       dem += tongnut(tg);
       tg = tg->right_sibling;
    }
    return dem;
}

int tongnutla(nodeTree *r )
{
    if(r==NULL) return 0;
    if(r->leftmost_child==NULL) return 1;
    int dem=0;
    nodeTree *tg=r->leftmost_child;
    while(tg!=NULL){
        dem += tongnutla(tg);
        tg=tg->right_sibling;
    }
    
    return dem;
}

int CountNodeWKChild( nodeTree *r , int k)
{
    if(k<0) return -1;
    if(r==NULL) return 0;
    int dem=0,i=0;

 

    nodeTree *tg=r->leftmost_child;
    while(tg!=NULL){
        i++;
        dem += CountNodeWKChild(tg,k);
        tg=tg->right_sibling;
    }
    
    if(i==k) dem++;
    
    return dem;
}


int main(){
    nodeTree *root = NULL;
    nodeTree *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;

    root = createNode('A');
    nutB = createNode('B');
    nutC = createNode('C');
    nutD = createNode('D');
    nutE = createNode('E');
    nutF = createNode('F');
    nutG = createNode('G');
    nutH = createNode('H');
    nutI = createNode('I');
    nutJ = createNode('J');
    nutK = createNode('K');

    root->leftmost_child=nutB;
    
    nutB->leftmost_child=nutE;
    nutB->right_sibling=nutC;
    
    nutC->leftmost_child=nutG;
    nutC->right_sibling=nutD;
    
    nutE->right_sibling=nutF;
    
    nutG->leftmost_child=nutH;
    
    nutH->right_sibling=nutI;
    nutI->right_sibling=nutJ;
    nutJ->right_sibling=nutK;
    

    printf("----------------Duyet truoc--------------------\n");
    duyettruoc(root);
    printf("\n----------------Duyet truoc--------------------\n");
    duyetsau(root);
    printf("\n----------------Duyet truoc--------------------\n");
    duyetgiua(root);
    
    printf("\nTong nut cua cay la: %d",tongnut(root));
    printf("\n\nTong nut la cua cay la: %d",tongnutla(root));
    printf("\n\nTong nut la cua cay la: %d",CountNodeWKChild(root,3));
    
    freeTree(root);

}