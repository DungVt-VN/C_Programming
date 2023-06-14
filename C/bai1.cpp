#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct SinhVien
{
    char UserName[100];
    char Password[100];
    float Score;
} SinhVien;

typedef struct BST
{
    SinhVien student;
    struct BST *left;
    struct BST *right;
} BST;

BST *head = NULL;

BST *createNode(SinhVien student)
{
    BST *node = (BST *)malloc(sizeof(BST));
    if (node == NULL)
    {
        printf("error!");
        exit(1);
    }
    node->student = student;
    node->right = NULL;
    node->left = NULL;
    return node;
}

BST *NewNode_BST(SinhVien student, BST *h)
{
    if (h == NULL)
    {
        h = createNode(student);
        return h;
    }
    if (strcmp(h->student.UserName, student.UserName) < 0)
    {
        h->right = NewNode_BST(student, h->right);
    }
    else
        h->left = NewNode_BST(student, h->left);
    return h;
}

int check_place(char check[])
{
    int len = strlen(check);
    for (int i = 0; i < len; i++)
    {
        if (check[i] == ' ')
            return 1;
    }
    return 0;
}

void DocFile()
{
    SinhVien student;
    FILE *f = fopen("SinhVien.txt", "r+");
    while (!feof(f))
    {
        fscanf(f, "%s %s %f", &student.UserName, &student.Password, &student.Score);
        head = NewNode_BST(student, head);
    }
    fclose(f);
}

BST *ChangePass(BST *check){
    char newPass[100];
    char newPass2[100];
    while(1){
        printf("\nNhap mat khau moi: "); gets(newPass);
        while(strlen(newPass) <= 6 || check_place(newPass) == 1){
            printf("\nPassWord khong hop le! hay nhap lai: "); 
        gets(newPass);
        }
        printf("Xac nhan lai new Password: "); gets(newPass2);
        if(strcmp(newPass,newPass2) != 0){
            printf("\nDoi khong thanh cong! Vui long lam lai cac buoc:\n");
            continue;
        }
        strcpy(check->student.Password,newPass);
        printf("Doi mat khau thanh cong!\n");
        break;
    }
    return check;
}

BST *Inorder(BST *h,FILE *f){
    if(h==NULL) return NULL;
    Inorder(h->left,f);
    printf("\n%f",h->student.Score);
    fprintf(f,"%s %s %0.2f\n",h->student.UserName,h->student.Password,h->student.Score);
    Inorder(h->right,f);
}


void GhiFile(){
    FILE *f = fopen("SinhVien.txt", "w+");
    fflush(stdin);
    Inorder(head,f);
    fclose(f);
}

void MenuSV(BST *check)
{
    int ch;
    char n;
    while (1)
    {
        printf("========================================");
        printf("\n1. Diem\n2. Doi PassWord\n3. Quit");
        printf("\n========================================");
        printf("\n\nNhap lua chon cua ban la: ");
        scanf("%d", &ch);
        if (ch == 3)
        {
            GhiFile();
            break;
        }
        switch (ch)
        {
        case 1:
            printf("\nDiem cua ban la: %0.2f\n",check->student.Score);
            fflush(stdin);
            printf("Nhap bat ky de ve menu: ");
            scanf("%c", &n);
            system("cls");
            continue;
        case 2:
            fflush(stdin);
            check = ChangePass(check);
            printf("Nhap bat ky de ve menu: ");
            scanf("%c", &n);
            system("cls");
            continue;
        default:
            system("cls");
            printf("\nBan da nhap sai! Vui long chon lai:\n ");
            continue;
        }
    }
}


void *ThemSV(){
    SinhVien student;
    fflush(stdin);
    printf("Nhap UserName: "); gets(student.UserName);
    while(check_place(student.UserName) == 1){
        printf("UserName khong hop le!");
        printf("Nhap UserName: "); gets(student.UserName);
    }
    printf("Nhap PassWord: "); gets(student.Password);
    while(check_place(student.Password) == 1|| strlen(student.Password) < 6){
        printf("PassWord khong hop le!");
        printf("Nhap PassWord: "); gets(student.Password);
    }
    printf("Nhap diem: "); scanf("%f",&student.Score);
    head = NewNode_BST(student,head);
}

BST *Inorder1(BST *h){
    fflush(stdin);
    printf("Hello");
    if(h==NULL) return NULL;
    Inorder1(h->left);
    printf("\n%s %s %0.2f",h->student.UserName,h->student.Password,h->student.Score);
    Inorder1(h->right);
}

BST *Delete(BST *h){
    char UserName[100];
    printf("Nhap UserName: "); gets(UserName);
}



void MenuAdmin()
{
    int choice;
    char n;
    while (1)
    {
        printf("========================================");
        printf("\n1. Them SinhVien\n2. In Danh Sach\n3. Xoa sinh vien\n4. Thoat");
        printf("\n========================================");
        printf("\n\nNhap lua chon cua ban: ");
        scanf("%d", &choice);
        if (choice == 2)
        {
            GhiFile();
            break;
        }
        switch (choice)
        {
        case 1:
            fflush(stdin);
            ThemSV();
            fflush(stdin);
            printf("Nhap bat ky de ve menu: ");
            scanf("%c", &n);
            system("cls");
            continue;
        case 2:
            fflush(stdin);
            printf("Hello");
            printf("\nNhap bat ky de ve menu: ");
            scanf("%c", &n);
            system("cls");
            continue;
        case 3:

            printf("Nhap bat ky de ve menu: ");
            scanf("%c", &n);
            system("cls");
            continue;
        default:
            system("cls");
            printf("\nBan da nhap sai! Vui long chon lai:\n ");
            continue;
        }
    }
}

BST *check1(char UserName[],BST *h){
    if(h == NULL) return NULL;
    if(strcmp(UserName,h->student.UserName) == 0) return h;
    else if(strcmp(UserName,h->student.UserName) < 0) return check1(UserName,h->left);
    else return check1(UserName,h->right);
}


void DangNhap()
{
    char UserName[100];
    char Password[100];
    fflush(stdin);
    printf("UserName:");
    gets(UserName);
    BST *check = check1(UserName,head);
    while(check == NULL){
        printf("\nUserName ko dung! Hay nhap lai: ");
        printf("UserName:");
        gets(UserName);
    }
    printf("PassWord: ");
    gets(Password);
    int p = 0;
    while(strcmp(check->student.Password,Password) != 0)
    {   
        if(p == 2) return;
        p++;
        printf("Password khong dung! Nhap lai: ");
        printf("PassWord: ");
        gets(Password);
    }
    printf("\n\nDang Nhap thanh cong!\n\n");
    if(strcmp(UserName,"Admin") ==0) MenuAdmin();
    else MenuSV(check);
}

int main()
{
    int choice;
    char n;
    BST *head = NULL;
    DocFile(head);
    while (1)
    {
        printf("========================================");
        printf("\n1. Dang Nhap\n2. Thoat");
        printf("\n========================================");
        printf("\n\nNhap lua chon cua ban: ");
        scanf("%d", &choice);
        if (choice == 2)
        {
            printf("Goodbye!");
            break;
        }
        switch (choice)
        {
        case 1:
            DangNhap(head);
            printf("Nhap bat ky de ve menu: ");
            scanf("%c", &n);
            system("cls");
            continue;
        default:
            system("cls");
            printf("\nBan da nhap sai! Vui long chon lai:\n ");
            continue;
        }
    }
}
