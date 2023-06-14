#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct COVID19
{
    char address[50];
    int gio;
    int phut;
    struct COVID19 *next;
} CV;

CV *createCV(char address[], int gio, int phut)
{
    CV *NewCV = (CV *)malloc(sizeof(CV));
    if (NewCV == NULL)
    {
        printf("\nERROR: Failed to allocate");
        exit(1);
    }
    strcpy(NewCV->address, address);
    NewCV->gio = gio;
    NewCV->phut = phut;
    NewCV->next = NULL;
    return NewCV;
}
CV *InsertLast(CV *head, char address[], int gio, int phut)
{
    if (head == NULL)
    {
        head = createCV(address, gio, phut);
        return head;
    }
    CV *tg = head;
    while (tg->next != NULL)
    {
        tg = tg->next;
    }
    tg->next = createCV(address, gio, phut);
    return head;
}

// Cau 1:
CV *Napdulieu(CV *head)
{
    char address[50];
    int gio;
    int phut;
    FILE *f = fopen("log.txt", "r+");
    while (!feof(f))
    {
        fscanf(f, "%s %d %d", &address, &gio, &phut);
        head = InsertLast(head, address, gio, phut);
    }
    fclose(f);
    printf("\nDone!\n");
    return head;
}

// Cau 2:

void Lichsu(CV *head)
{
    CV *tg = head;
    printf("%-50s%-10s%-10s", "DIA DIEM", "GIO", "PHUT");
    while (tg != NULL)
    {
        printf("\n%-50s%-10d%-10d", tg->address, tg->gio, tg->phut);
        tg = tg->next;
    }
}
// Cau 3:
void Search(CV *head)
{
    fflush(stdin);
    char name[50];
    printf("Nhap ten dia diem: \n");
    gets(name);
    CV *tg = head;
    int time[1000], i = 0;
    while (tg != NULL)
    {
        if (strcmp(name, tg->address) == 0)
        {
            i = i + 1;
            time[i] = tg->gio;
            time[i + 1] = tg->phut;
            i = i + 1;
        }
        tg = tg->next;
    }
    printf("%-25s", name);
    if (i == 0)
    {
        printf("    Ban chua toi dia diem do!");
    }
    else
    {
        for (int j = 1; j <= i; j = j + 2)
        {
            printf("%d:%d", time[j], time[j + 1]);
            if (j + 2 < i)
                printf(", ");
        }
    }
}

// cau 4:

void Timkiemtheothoigian(CV *head)
{
    fflush(stdin);
    int gio, phut;
    printf("Nhap gio: ");
    scanf("%d", &gio);
    printf("Nhap phut: ");
    scanf("%d", &phut);
    while (0 > gio || gio >= 24 || 0 > phut || phut >= 60)
    {
        printf("Nhap sai du lieu. Nhap lai!\n");
        printf("Nhap gio: ");
        scanf("%d", &gio);
        printf("Nhap phut: ");
        scanf("%d", &phut);
    }
    CV *tg = head;
    while (tg != NULL)
    {
        if (tg->gio == gio && tg->phut == phut)
        {
            printf("%s", tg->address);
            break;
        }
        tg = tg->next;
    }
}

// cau 5:
void Kiemtratruyvet(CV *head)
{
    fflush(stdin);
    int check = 0;
    char address[50];
    int gio, phut;
    printf("Nhap dia chi va thoi gian!\n");
    printf("Dia chi: ");
    gets(address);
    printf("Nhap gio: ");
    scanf("%d", &gio);
    printf("Nhap phut: ");
    scanf("%d", &phut);
    CV *tg = head;
    while (tg != NULL)
    {
        if (strcmp(address, tg->address) == 0)
        {
            if (tg->gio > gio)
                check++;
            else if (tg->gio = gio && tg->phut > phut)
                check++;
        }
        tg = tg->next;
    }
    if (check == 0)
        printf("\nLich trinh cua ban OK");
    else
        printf("\nBan can khai bao y te!");
}

void freeCV(CV *head)
{
    CV *tg = head;
    while (tg != NULL)
    {
        CV *tmp = tg->next;
        free(tg);
        tg = tmp;
    }
}

int main()
{
    int n;
    char n2;
    CV *head = NULL;
    while (1)
    {
        printf("\n*----------CHUONG TRINH TRUY VET COVID19-----------*\n");
        printf("*  [ 1 ] Nap file log lich su di chuy              *\n");
        printf("*  [ 2 ] In ra lich su di chuyen                   *\n");
        printf("*  [ 3 ] Tim kiem lich su theo dia diem            *\n");
        printf("*  [ 4 ] Tim kiem lich su theo thoi gian           *\n");
        printf("*  [ 5 ] Kiem tra truy vet moi nhat                *\n");
        printf("*  [ 6 ] Thoat                                     *\n");
        printf("*--------------------------------------------------*\n");
        printf("\n\n Nhap lua chon cua ban:   ");
        scanf("%d", &n);
        system("cls");
        if (n == 6)
        {
            freeCV(head);
            printf("Good bye! ");
            break;
        }
        else if (n < 1 || n > 6)
        {
            printf("\nLua chon khong hop le nhap lai: ");
        }
        else
        {
            switch (n)
            {
            case 1:
                head = Napdulieu(head);
                printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
                scanf("%s", &n2);
                system("cls");
                continue;
            case 2:
                Lichsu(head);
                printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
                scanf("%s", &n2);
                system("cls");
                continue;
            case 3:
                Search(head);
                printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
                scanf("%s", &n2);
                system("cls");
                continue;
            case 4:
                Timkiemtheothoigian(head);
                printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
                scanf("%s", &n2);
                system("cls");
                continue;
            case 5:
                Kiemtratruyvet(head);
                printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
                scanf("%s", &n2);
                system("cls");
                continue;
            }
        }
    }
    getch();
}
