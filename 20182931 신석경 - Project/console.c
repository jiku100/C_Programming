/*
* console.c
*
* ����: ���� ���ӿ��� �ܼ� ����� ����ϴ� ���
*
* include: source.h, cursor.h, console.h�� �����
*
* �Է�: ����
*
* ���: ���� ���ӿ��� �ʿ��� �ܼ� ��µ�
*
* ���� �ڵ� ���� ��¥: 2020.11.21
* ����: 1.0
* �ۼ���: �ż���
*
*/

#include "console.h"
#include "source.h"
#include "cursor.h"
#include <stdio.h>


void gameStart() {	// ���� ����ȭ�� ��� �Լ�
	gotoxy(0, 0);
	printf("Black Jack!!!");
}
void drawCardBack(int x, int y) {	// ī�� �޸� �׸��� �Լ�
	gotoxy(x, y++);
	printf(" ----");
	gotoxy(x, y++);
	printf("|XXXX|");
	gotoxy(x, y++);
	printf("|XXXX|");
	gotoxy(x, y++);
	printf("|XXXX|");
	gotoxy(x, y);
	printf(" ----\n");
}

void showShuffling() {		// ī�� ���̴� ����� �׸��� �Լ�
	for (int i = 0; i < 2; i++) {
		for (int i = 0; i < 7; i++) {	// ī�带 13,5���� ������
			gotoxy(0, 0);
			printf("ī�带 ���� ��.....");
			drawCardBack(13 - i, 5);
			drawCardBack(13, 5);
			drawCardBack(13 + i, 5);
			Sleep(10);
			console_clear();
		}
		for (int i = 0; i < 7; i++) {	// ī�带 13,5�� �ٽ� ������	
			gotoxy(0, 0);
			printf("ī�带 ���� ��.....");
			drawCardBack(7 + i, 5);
			drawCardBack(13, 5);
			drawCardBack(19 - i, 5);
			Sleep(10);
			console_clear();
		}
		for (int i = 0; i < 4; i++) {	// ī�带 �� �Ʒ��� 4�� ����
			for (int i = 0; i < 2; i++) {	// ���� �ű��
				gotoxy(0, 0);
				printf("ī�带 ���� ��.....");
				drawCardBack(13, 5 - i);
				drawCardBack(13, 5);
				drawCardBack(13, 5 + i);
				Sleep(10);
				console_clear();
			}
			for (int i = 2; i >= 0; i--) {	// �Ʒ��� �ű��
				gotoxy(0, 0);
				printf("ī�带 ���� ��.....");
				drawCardBack(13, 5 - i);
				drawCardBack(13, 5);
				drawCardBack(13, 5 + i);
				Sleep(10);
				console_clear();
			}
		}
	}
	gotoxy(0, 0);
	printf("ī�带 ���� ��.....");
	drawCardBack(13, 5);	// 13,5�� ī�� �޸� ���
}

void showCard(Card* card, int x, int y, int op) {	// ī�� ���� �Լ�
	gotoxy(x, y++);
	printf(" ----");
	gotoxy(x, y++);
	if (op == OPEN) {	// op�� OPEN�̸�
		if (card->number == '0') {	// card number�� 0 �̸�
			printf("|10  |");	// 10���� ���
			gotoxy(x, y++);
			printf("| %s |", card->shape);
			gotoxy(x, y++);
			printf("|  10|");
		}
		else {
			printf("|%c   |", card->number);	// �ƴ� ��� number ���
			gotoxy(x, y++);
			printf("| %s |", card->shape);
			gotoxy(x, y++);
			printf("|   %c|", card->number);
		}
	}
	else if (op == CLOSE) {	// op �� CLOSE �̸�
		printf("|XXXX|");	// ��� �޸����� ���
		gotoxy(x, y++);
		printf("|XXXX|");
		gotoxy(x, y++);
		printf("|XXXX|");
	}
	gotoxy(x, y);
	printf(" ----\n");
}

void showDeck(Deck* deck, int op) {
	CONSOLE_SCREEN_BUFFER_INFO presentCur;	// Ŀ�� ��ġ ���� ����
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);	// ���� Ŀ�� ��ġ ����
	int X_init = presentCur.dwCursorPosition.X;	// Ŀ�� X��ġ ����
	int Y_init = presentCur.dwCursorPosition.Y;  // Ŀ�� Y��ġ ����
	int X = X_init;
	int Y = Y_init;
	for (int i = 0; i < 4; i++) {	// 4��
		for (int j = 0; j < 13; j++) {	// 13���� ī�� ���
			showCard(&(*deck).cards[13 * i + j], X, Y, op);
			X += CARD_X_OFFSET;
		}
		X = X_init;
		Y += CARD_Y_OFFSET;
	}
}

void showSum(Gamer* gamer) {		// ī�� ���� �����ִ� �Լ�
	if (gamer->isLose == FALSE) {	// ���̸Ӱ� �� �׾�����
		if (gamer->isBlackJack == TRUE) {	// �����̸�
			printf("ī�� ��: BlackJack!!         ");	// ���� ���
		}
		else if (gamer->hasA && !(gamer->sum[1] > 21)) {	// A�� ������ �ְ� 21�� ���� �ʴ´ٸ�
			printf("ī�� ��: %d / %d", gamer->sum[0], gamer->sum[1]);	// �� �� ���
		}
		else {
			printf("ī�� ��: %d        ", gamer->sum[0]);	// �� ���� ������ �� ���� ���
		}
	}
	else {
		printf("ī�� ��: BUST!!             ");	// ���̸Ӱ� �׾����� ���� �� ���
	}
}

void gameSet(Dealer* dealer, Gamer* player1, Gamer* player2) {	// ó�� ���� ���� ȭ��
	gotoxy(50, 5);
	printf("%s", dealer->gamer.person.name);
	drawCardBack(50, 12);
	gotoxy(25, 17);
	printf("%s", player1->person.name);
	gotoxy(75, 17);
	printf("%s", player2->person.name);
}


void showMoney(Gamer* player1, Gamer* player2) {	// �� �÷��̾��� ���� �ݾ��� ���
	gotoxy(25, 18);
	printf("���� �ݾ� : %.2f    ", player1->person.money);
	gotoxy(75, 18);
	printf("���� �ݾ� : %.2f    ", player2->person.money);
	gotoxy(25, 19);
	printf("���� �ݾ� : %.2f    ", player1->bet_money);
	gotoxy(75, 19);
	printf("���� �ݾ� : %.2f    ", player2->bet_money);
}

void playerSet(Gamer* player1, Gamer* player2) {	// ���� �ݾ��� �Է� �ް� �� �ݾ��� ����ϴ� �Լ�
	betting(player1);	// �÷��̾� 1�� ������ ����
	gotoxy(25, 19);
	showMoney(player1, player2);
	betting(player2);
	gotoxy(75, 19);
	showMoney(player1, player2);
}


void showWhoTurn(Person p) {	// p�� ���ʸ� ��Ÿ���� �Լ�
	gotoxy(0, 2);
	line_clear();
	gotoxy(43, 2);
	printf("%11s Turn  ", p.name);
}