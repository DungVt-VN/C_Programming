#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ifmations {
    int id;
    char toy[30];
    struct ifmations *next;
}ifm;

ifm *ALink = NULL;

ifm *create(int id, char toy[30]){
    ifm *newnode = (ifm *)malloc(sizeof(ifm));
    if(newnode == NULL){
        printf("Error !");
        exit(1);
    }
    newnode->id = id;
    strcpy(newnode-> toy, toy);
    newnode->next = NULL;
    return newnode;
}

ifm *Insert_tohead(int id,char toy[30]){

    ifm *newnode = create(id,toy);
    newnode->next = ALink;

    return newnode;
}

void duyetds(){
    ifm *tg = ALink;
    printf("\n");
    while(tg!=NULL){
        printf("%d   ",tg->id);
        puts(tg-> toy);
        tg = tg-> next;
    }    
}

void free_list(){
    ifm *tg = ALink;
    ifm *tg2 = NULL;
    while(tg!=NULL){
        tg2 = tg-> next;
        free(tg);
        tg = tg2;
    }
}
// cau 1:
void read_fileA(){
    int id;
    FILE *f = fopen("A.txt", "r");
    while(!feof(f)){
        char toy[30] = "\0";
        fscanf(f,"%d",&id);
        fseek(f,4,SEEK_CUR);
        fscanf(f,"%[^\n]", &toy);
        ALink = Insert_tohead(id, toy);
    }
    duyetds();
    fclose(f);
}

//cau 2:

void read_fileB(){
    int id;
    FILE *f = fopen("B.txt", "r");
    while(!feof(f)){
        char toy[30] = "\0";
        fscanf(f,"%d  %s",&id,&toy);
        ALink = Insert_tohead(id, toy);
    }
    duyetds();
    fclose(f);
}

//cau 3:


//cau 5:
//  void thongke(ifm *ALink){
//     ifm *tg;
//     tg = Alink;
//     while( tg!= NULL){
//         a
//     }
// }

int main(){
	int n;
	char n2;
	while(1){
	printf("\n*-------------------------------------------*\n");
	printf("*  [ 1 ] Doc file A                         *\n");
	printf("*  [ 2 ] Doc file B                         *\n");
	printf("*  [ 3 ] Tim kiem                           *\n");
	printf("*  [ 4 ] Tong hop                           *\n");
	printf("*  [ 5 ] Thong ke                           *\n");
	printf("*-------------------------------------------*\n");
	printf("\n\n Nhap lua chon cua ban:   ");
	scanf("%d",&n);
		system("cls");
    if(n < 1 || n > 5){
			printf("\nLua chon khong hop le nhap lai: ");
	}else{
	switch(n){
		case 1:
            read_fileA();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 2:
            read_fileB();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 3:
            duyetds();
			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 4:

			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
		case 5:

			printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
			scanf("%s",&n2);
			system("cls");
			continue;
	}
    }
}
free_list();
getch();
}
