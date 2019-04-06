#define  _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 3
#define MAX_COL 3
#include<stdio.h>
#include<stdlib.h>
int Menu() {
	printf("=============\n");
	printf("  1.��ʼ��Ϸ \n");
	printf("  2.������Ϸ \n");
	printf("=============\n");
	printf(" ���������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
char chess_board[MAX_ROW][MAX_COL];
void Init() {
	//1.��������ʼ������
	//����ʹ�� x ��ʾ������ӣ�o��ʾ�������ӣ�������ʾδ����
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chess_board[row][col] = ' ';
		}
	}
}
void Print() {
	//2.��ӡ����
	for (int row = 0; row < MAX_ROW; row++) {
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		if (row != MAX_ROW - 1) {
			printf("|---|---|---|\n");
		}
	}
}
	
void PlayerMove() {
	//3.�������
	printf("�������\n");
	while (1) {
		printf("������һ������(row,col):\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {
			printf("�������Ƿ�!\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("����������걻ռ��!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
int IsFull() {
//����������˷���1������0
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chess_board[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

//���� x ��ʾ���ʤ
//���� o ��ʾ����ʤ
//���� q ��ʾ����
//���� '' ������Ϸ
char CheckGameOver() {
	//4.�����Ϸ����
	//������е���
	for (int row = 0; row < MAX_ROW; row++) {
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]) {
			return chess_board[row][0];
		}
	}
	//������е���
	for (int col = 0; col < MAX_COL; col++) {
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]) {
			return chess_board[0][col];
		}
	}
	//������еĶԽ���
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]) {
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]) {
		return chess_board[0][2];
	}
	if (IsFull()) {
		return 'q';
	}
	return ' ';

}
void ComputerMove() {
	//5.��������
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] !=  ' ') {
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}
void Game() {
	char winner = ' ';
        //1.��������ʼ������
	    Init();
	while (1) {
		system("cls");
		//2.��ӡ����
		Print();
		//3.�������
		PlayerMove();
		//4.�����Ϸ����
		CheckGameOver();
	    winner = CheckGameOver();
		if (winner != ' ') {
			//�ֳ�ʤ�������
			break;
		}
		//5.��������
		ComputerMove();
		//6.�����Ϸ����
		winner = CheckGameOver();
		if (winner != ' ') {
			break;
		}
	}
	system("cls");
	Print();
	if (winner == 'x') {
		printf("���ʤ����\n");
	}
	else if (winner == 'o') {
		printf("����ʤ����\n");
	}
	else if (winner == 'q') {
		printf("���壡\n");
	}
	else {
		printf("�����ˣ�\n");
	}
}
int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		}
		else if (choice == 2) {
			printf("goodbye\n");
			break;
		}else {
			printf("�����������\n");
		}
	}
	system("pause");
	return 0;
}