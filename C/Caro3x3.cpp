#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int n;
int checkwin(char s[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (s[i][0] == s[i][1] && s[i][0] == s[i][2] && s[i][0] != ' ')
			return 1;
		if (s[0][i] == s[1][i] && s[0][i] == s[2][i] && s[0][i] != ' ')
			return 1;
		if (s[0][0] == s[1][1] && s[0][0] == s[2][2] && s[0][0] != ' ')
			return 1;
		if (s[2][0] == s[1][1] && s[0][2] == s[1][1] && s[2][0] != ' ')
			return 1;
	}
	int dem = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (s[i][j] != ' ')
				dem++;
		}
	}
	if (dem == 9)
		return 2;
	return 0;
}
void banco(char s[][3]) {
	printf("___________________\n");
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n", s[0][0], s[0][1], s[0][2]);
	printf("|_____|_____|_____|\n");
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n", s[1][0], s[1][1], s[1][2]);
	printf("|_____|_____|_____|\n");
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n", s[2][0], s[2][1], s[2][2]);
	printf("|_____|_____|_____|\n");
}

int checkVt(char s[3][3], int vt, char c) {
	if (vt > 9 || vt < 0)
		return 1;
	switch (vt) {
	case 1:
		if (s[0][0] != ' ')
			return 1;
		else
			s[0][0] = c;
		break;
	case 2:
		if (s[0][1] != ' ')
			return 1;
		else
			s[0][1] = c;
		break;
	case 3:
		if (s[0][2] != ' ')
			return 1;
		else
			s[0][2] = c;
		break;
	case 4:
		if (s[1][0] != ' ')
			return 1;
		else
			s[1][0] = c;
		break;
	case 5:
		if (s[1][1] != ' ')
			return 1;
		else
			s[1][1] = c;
		break;
	case 6:
		if (s[1][2] != ' ')
			return 1;
		else
			s[1][2] = c;
		break;
	case 7:
		if (s[2][0] != ' ')
			return 1;
		else
			s[2][0] = c;
		break;
	case 8:
		if (s[2][1] != ' ')
			return 1;
		else
			s[2][1] = c;
		break;
	case 9:
		if (s[2][2] != ' ')
			return 1;
		else
			s[2][2] = c;
		break;
	default:
		return 1;
	}
	return 0;
}

void People(char s[3][3], int j) {
	char c;
	if (j % 2 != 0)
		c = 'X';
	else
		c = 'O';
	int vt = -1;
	printf("Nhap vi tri: ");
	scanf("%d", &vt);
	while (checkVt(s, vt, c) == 1) {
		printf("\nVi Tri Khong Hop Le!");
		printf("\nVui long nhap lai: ");
		scanf("%d", &vt);
	}
}
void May(char s[3][3], int j,int i) {	
	printf("\nMay dang nghi...");
	Sleep(1000);
	char c, c2;
	if (j % 2 != 0) {
		c = 'X';
		c2 = 'O';
	}
	else {
		c = 'O';
		c2 = 'X';
	}

	if (s[2][0] == s[0][2] && s[2][0] == c && s[1][1] == ' ') {
		s[1][1] = c;
		return;
	}
	if (s[2][0] == s[1][1] && s[2][0] == c && s[0][2] == ' ') {
		s[0][2] = c;
		return;
	}
	if (s[1][1] == s[0][2] && s[1][1] == c && s[2][0] == ' ') {
		s[2][0] = c;
		return;
	}

	if (s[0][0] == s[1][1] && s[0][0] == c && s[2][2] == ' ') {
		s[2][2] = c;
		return;
	}
	if (s[0][0] == s[2][2] && s[0][0] == c && s[1][1] == ' ') {
		s[1][1] = c;
		return;
	}
	if (s[1][1] == s[2][2] && s[1][1] == c && s[0][0] == ' ') {
		s[0][0] = c;
		return;
	}
	

	for (int i = 0; i < 3; i++) {
		if (s[i][0] == s[i][2] && s[i][0] == c && s[i][1] == ' ') {
			s[i][1] = c;
			return;
		}	
		if (s[i][0] == s[i][1] && s[i][0] == c && s[i][2] == ' ') {
			s[i][2] = c;
			return;
		}
		if (s[i][1] == s[i][2] && s[i][1] == c && s[i][0] == ' ') {
			s[i][0] = c;
			return;
		}
			

		if (s[2][i] == s[0][i] && s[2][i] == c && s[1][i] == ' ') {
			s[1][i] = c;
			return;
		}
		if (s[2][i] == s[1][i] && s[2][i] == c && s[0][i] == ' ') {
			s[0][i] = c;
			return;
		}			
		if (s[1][i] == s[0][i] && s[1][i] == c && s[2][i] == ' ') {
			s[2][i] = c;
			return;
		}
			
	}

	if (s[2][0] == s[0][2] && s[2][0] == c2 && s[1][1] == ' ') {
		s[1][1] = c;
		return;
	}
	if (s[2][0] == s[1][1] && s[2][0] == c2 && s[0][2] == ' ') {
		s[0][2] = c;
		return;
	}
	if (s[1][1] == s[0][2] && s[1][1] == c2 && s[2][0] == ' ') {
		s[2][0] = c;
		return;
	}

	if (s[0][0] == s[1][1] && s[0][0] == c2 && s[2][2] == ' ') {
		s[2][2] = c;
		return;
	}
	if (s[0][0] == s[2][2] && s[0][0] == c2 && s[1][1] == ' ') {
		s[1][1] = c;
		return;
	}
	if (s[1][1] == s[2][2] && s[1][1] == c2 && s[0][0] == ' ') {
		s[0][0] = c;
		return;
	}
	

	for (int i = 0; i < 3; i++) {
		if (s[i][0] == s[i][2] && s[i][0] == c2 && s[i][1] == ' ') {
			s[i][1] = c;
			return;
		}
		if (s[i][0] == s[i][1] && s[i][0] == c2 && s[i][2] == ' ') {
			s[i][2] = c;
			return;
		}
		if (s[i][1] == s[i][2] && s[i][1] == c2 && s[i][0] == ' ') {
			s[i][0] = c;
			return;
		}	

		if (s[2][i] == s[0][i] && s[2][i] == c2 && s[1][i] == ' ') {
			s[1][i] = c;
			return;
		}	
		if (s[2][i] == s[1][i] && s[2][i] == c2 && s[0][i] == ' ') {
			s[0][i] = c;
			return;
		}
		if (s[1][i] == s[0][i] && s[1][i] == c2 && s[2][i] == ' ') {
			s[2][i] = c;
			return;
		}
			
	}

	if (s[1][1] == ' ') {
		s[1][1] = c;
		return;
	}
	else {
		if (s[0][0] == s[0][2] && s[0][0] == s[2][0] && s[0][0] == s[2][2] && s[0][0] == ' ') {
			if (s[0][1] == c2)
				s[0][2] = c;
			else if (s[1][0] == c2)
				s[0][0] = c;
			else if (s[2][1] == c2)
				s[2][0] = c;
			else if (s[1][2] == c2)
				s[2][2] = c;
			else
				s[0][0] = c;
			return;
		}
		else {
			if (s[0][1] == s[1][2] && s[1][2] == s[2][1] && s[1][0] == s[0][1] && s[0][1] == ' ') {
				if (s[0][1] == ' ')
					s[0][1] = c;
				else if (s[1][2] == ' ')
					s[1][2] = c;
				else if (s[2][1] == ' ')
					s[2][1] = c;
				else if (s[1][0] == ' ')
					s[1][0] = c;
				return;
			}
		}
	}
	if(i %2 != 0){
		if(s[0][1] != ' '){
			if(s[2][0] != ' ') s[0][0] = c;
			else s[0][2] = c;
		}
		if(s[1][0] != ' '){
			if(s[0][2] != ' ') s[0][0] = c;
			else s[2][0] = c;
		}
		if(s[2][1] != ' '){
			if(s[0][0] != ' ') s[2][0] = c;
			else s[2][2] = c;
		}
		if(s[1][2] != ' '){
			if(s[0][0] != ' ') s[0][2] = c;
			else s[2][2] = c;
		}
	}else{
		if(s[0][1] != ' '){
			if(s[2][0] != ' ') s[2][2] = c;
			else s[2][0] = c;
		}
		if(s[1][0] != ' '){
			if(s[0][0] != ' ') s[0][2] = c;
			else s[2][2] = c;
		}
		if(s[2][1] != ' '){
			if(s[2][0] != ' ') s[0][0] = c;
			else s[0][2] = c;
		}
		if(s[1][2] != ' '){
			if(s[2][2] != ' ') s[2][0] = c;
			else s[0][0] = c;
		}
	}
}

void game(char s[3][3]) {
	static int i = 1;
	int j = 0;
	int vt, check;
	banco(s);
	while (1) {
		j++;
		if (n == 1) {
			if (i % 2 != 0) {
				printf("\nNguoi choi!\n");
				People(s, j);
				system("cls");
				banco(s);
				check = checkwin(s);
				if (check == 1) {
					printf("\nNguoi choi thang!");
					break;
				}
				if (check == 2) {
					printf("\nHoa!");
					break;
				}
				j++;
				printf("\nLuot may!\n");
				Sleep(1000);
				May(s, j,i);
				system("cls");
				banco(s);
				check = checkwin(s);
				if (check == 1) {
					printf("\nMay thang!");
					break;
				}
				if (check == 2) {
					printf("\nHoa!");
					break;
				}
			}
			else {
				printf("\nLuot may!\n");
				Sleep(1000);
				May(s, j,i);
				system("cls");
				banco(s);
				check = checkwin(s);
				if (check == 1) {
					printf("\nMay thang!");
					break;
				}
				if (check == 2) {
					printf("\nHoa!");
					break;
				}

				j++;
				printf("\nNguoi choi!\n");
				People(s, j);
				system("cls");
				banco(s);
				check = checkwin(s);
				if (check == 1) {
					printf("\nNguoi choi thang!");
					break;
				}
				if (check == 2) {
					printf("\nHoa!");
					break;
				}
			}
		}
		else {
			printf("\nNguoi choi 1!\n");
			People(s, j);
			system("cls");
			banco(s);
			check = checkwin(s);
			if (check == 1)
			{
				printf("\nNguoi choi 1 thang!");
				break;
			}
			if (check == 2)
			{
				printf("\nHoa!");
				break;
			}
			j++;
			printf("\nNguoi choi 2!\n");
			People(s, j);
			system("cls");
			banco(s);
			check = checkwin(s);
			if (check == 1)
			{
				printf("\nNguoi choi 2 thang!");
				break;
			}
			if (check == 2)
			{
				printf("\nHoa!");
				break;
			}
		}
	}
	i++;
}

int main()
{
	char c;
	printf("\nChon 1: 1 nguoi choi");
	printf("\nChon 2: 2 nguoi choi");
	printf("\nNhap lua chon cua ban: ");
	scanf("%d", &n);
	while (1)
	{
		char s[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
		game(s);
		printf("\nBan co muon choi tiep? Y/N de tiep tuc: ");
		fflush(stdin);
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			system("cls");
			continue;
		}

		else
			break;
	}
}
