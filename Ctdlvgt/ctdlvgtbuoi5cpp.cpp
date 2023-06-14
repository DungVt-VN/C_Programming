#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
 
# define maxlength 1000
typedef int elementtype; /* elements are integers */
typedef struct list_tag {
    elementtype elements [maxlength];
    int last;
} list_type;
 
list_type *create(){
    list_type *lp=(list_type *)malloc(sizeof(list_type));
    if(lp==NULL) {printf("\nError!\n");exit(0);}
    lp->last=-1;
    return lp;
}
 

void duyetds(list_type *lp){
    for(int i=0;i<=lp->last;i++)
        printf("%d\n",lp->elements[i]);
}
 
int end(list_type *lp)
{
    return (lp->last +1);
}
 

void insert(elementtype x ,int p ,list_type *lp)
{
    if (lp->last >= maxlength - 1)
    {
        printf("\n%s ","list is full");
        return;
    }
    if ((p < 0) || (p > lp->last + 1))
    {
        printf("\n%s ","position does not exist");
        return;
    }
    else {
        for (int q = lp->last; q >= p; q--)
            lp->elements[q+1] = lp->elements[q];

        lp->last = lp->last +1 ;
        lp->elements[p] = x;
    }
}
 

void deleteL(int p, list_type *lp)
{
    if ((p > lp->last) || (p < 0))
    {
        printf("\n%s ","position does not exist");
        return;
    }
    else /* shift elements */ {
        lp->last--;
        for (int q = p; q <= lp->last; q++)
            lp->elements[q] = lp->elements[q+1];
    }
}
 

int main(){
    list_type *lp = create();
    insert(5,0,lp);
    insert(4,1,lp);
    insert(7,2,lp);

    duyetds(lp);
    printf("vi tri end = %d\n",end(lp));

    insert(70,1,lp);
    printf("-------------------\n");
    duyetds(lp);

    deleteL(1,lp);
    printf("-------------------\n");
    duyetds(lp);

    //getch();
    return 1;
}
