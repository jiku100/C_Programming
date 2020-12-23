/*
* control.c
*
* ����: ���� ������ �帧�� ����ϴ� ���
*
* include: source.h, cursor.h, control.h, console.h�� �����
*
* �Է�: �� �Լ����� �ʿ�� �ϴ� �Էµ�
*
* ���: ���� �ɼ��� �Է� �ޱ� ���� ���� ��� �� ������ ����ǰ� �ִ� ��Ȳ��
*
* ���� �ڵ� ���� ��¥: 2020.11.21
* ����: 1.0
* �ۼ���: �ż���
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include "source.h"
#include "control.h"
#include "console.h"
#include "cursor.h"
#include <stdio.h>
#include <time.h>

int gameStartOption() {	// ó�� ������ �����ϴ� ���θ� �����ϴ� �Լ�
	
	char choice;	// ������ �����ϴ� ����
	int isright;	// �Է��� �ùٸ��� Ȯ���ϴ� ����

	do
	{
		gotoxy(0, 1);	// 0 , 1�� �̵��Ͽ� �� ���� ������
		line_clear();
		gotoxy(0, 1);

		printf("������ �����ϰڽ��ϱ�? <y or n>: ");
		isright = scanf("%c", &choice);		// ���� �ɼ��� �Է� �޴´�.
		while (getchar() != '\n');	// ���۸� ����

		if (isright != 1 || !(choice == 'y' || choice == 'n')) {	// �Է��� �߸� �Ǿ��ų�, �ɼ��� y, n�� �ƴ� ���
			gotoxy(0, 2);
			line_clear();
			gotoxy(0, 2);	// 0,2 �� ���� �����
			printf("y �� n�� �Է��ϼ���.");	// ���� ���
		}
		if (isright == 1 && choice == 'y') {	// �Է��� �ùٸ��� y�� ���
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 3);
			line_clear();
			// 0,1 0,2 0,3 �� ���� �� ����
			return 1;	// 1 ��ȯ
		}
		else if (isright == 1 && choice == 'n') {	// �Է��� �ùٸ��� n�� ���
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 3);
			line_clear();
			// �� ���� �����
			return 0;	// 0 ��ȯ
		}
	} while (TRUE);	// �Է��� �ùٸ��� �� ������ �ݺ�
}

int gameContinueOption() {	// ������ ��� ������ �� Ȯ���ϴ� �Լ�
	char choice;
	int isright;

	do
	{
		gotoxy(0, 0);
		line_clear();
		gotoxy(0, 0);	// 0,0 �� ���� ����

		printf("������ ����ϰڽ��ϱ�? <y or n>: ");
		isright = scanf("%c", &choice);
		while (getchar() != '\n');

		if (isright != 1 || !(choice == 'y' || choice == 'n')) {	// �Է��� y Ȥ�� n�� �ƴ� ���
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 1);	// 0,1 �� �� ����
			printf("y �� n�� �Է��ϼ���."); //0,1�� ���
		}
		if (isright == 1 && choice == 'y') {	// y�̸�
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			line_clear();	// 0,0 0,1 �� ���� ����� 1 ��ȯ
			return 1;
		}
		else if (isright == 1 && choice == 'n') {	// n�̸�
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			line_clear();	// 0,0 0,1 �� ���� ����� 0 ��ȯ
			return 0;
		}
	} while (TRUE);	// �ùٸ� �Է��� �Էµ� ������ �ݺ� 
}

void shuffle(Deck* deck) {	// �� ����
	srand((unsigned long)time(NULL));
	
	Card temp;
	int rn;
	
	console_clear();	// �ܼ� Ŭ����
	drawCardBack(13, 5);	// 13, 5�� ī�� �� ���� �޸����� ���

	for (int i = 0; i < 51; i++) {	// 51�� ����
		rn = rand() % (52 - i) + i;	// i ���� 51 ���̿� ������ ���� ����
		temp = deck->cards[i];	// �� �� ī�带 �ٲ۴�.
		deck->cards[i] = deck->cards[rn];
		deck->cards[rn] = temp;
	}
	deck->count = 0;	// �� open ��ġ �ʱ�ȭ
	Sleep(500);	// 0.5 �ʸ� ��ٸ�
	console_clear();	// �ܼ� Ŭ����
	showShuffling();	// ī�� ���� ����� ������
}

void compare(Dealer* dealer, Gamer* player1, Gamer* player2) { // ���� ���� �Լ�
	int dealer_sum = result_sum(&dealer->gamer);	// dealer�� ī�� �� ����� dealer_sum�� ����
	int player1_sum = result_sum(player1);		// player1�� ī�� �� ����� player1_sum�� ����
	int player2_sum = result_sum(player2);		// player2�� ī�� �� ����� player2_sum�� ����

	if (dealer_sum == 0) {	// ������ ī�� ���� 0�� ��� (Bust)
		if (player1_sum == 21) {	// �÷��̾� 1�� ī�� ���� 21�� ���
			gotoxy(25, 27);
			printf("BLACKJACK!!");		// ���� ���
			player1->person.money += 2.5 * player1->bet_money;	 // ���� �ݾ� 2.5 �踦 ��
			player1->bet_money = 0;	// ���� �ݾ� 0���� �ʱ�ȭ
		}
		else if (player1_sum == 0) {	// �÷��̾� 1�� ī�� ���� 0�� ���
			gotoxy(25, 27);
			printf("LOSE!!     ");	// ���� �� ���
			player1->bet_money = 0;	// ���� �ݾ��� 0���� ����
		}
		else {	// �ٸ� ���, �� ī�� ���� �����ϴ� ���
			gotoxy(25, 27);
			printf("WIN!!      ");	// �¸� ���
			player1->person.money += 2 * player1->bet_money;	// ���� �ݾ��� 2�踦 ��
			player1->bet_money = 0;
		}

		if (player2_sum == 21) {	// �÷��̾� 2�� ��� ���� �÷��̾� 1�� ������
			gotoxy(75, 27);
			printf("BLACKJACK!!");
			player2->person.money += 2.5 * player2->bet_money;
			player2->bet_money = 0;
		}
		else if (player2_sum == 0) {
			gotoxy(75, 27);
			printf("LOSE!!     ");
			player2->bet_money = 0;
		}
		else {
			gotoxy(75, 27);
			printf("WIN!!      ");
			player2->person.money += 2 * player2->bet_money;
			player2->bet_money = 0;
		}
	}
	else if (dealer_sum == 21) {	// ������ ���� 21�� ��� (����)
		if (player1_sum == 21) {	// �÷��̾� 1 ī�� ���� 21�� ���
			gotoxy(25, 27);
			printf("PUSH!!     ");	// ��� �� ���
			player1->person.money += player1->bet_money;	// ���� �ݾ� �״�� �ٽ� ���� ����
			player1->bet_money = 0;
		}
		else {	// �ٸ� ��� ����
			gotoxy(25, 27);
			printf("LOSE!!     ");	// ���� �� ���
			player1->bet_money = 0;
		}

		if (player2_sum == 21) {	// �÷��̾� 2�� ��� ���� �÷��̾� 1�� ����
			gotoxy(75, 27);
			printf("PUSH!!     ");
			player2->person.money += player2->bet_money;
			player2->bet_money = 0;
		}
		else {
			gotoxy(75, 27);
			printf("LOSE!!     ");
			player2->bet_money = 0;
		}
	}
	else {	// ������ ī�� ���� 21�� �ƴ� �ٸ� ���ڷ� �����ϴ� ���
		if (player1_sum == 21) {	// �÷��̾� 1�� ī�� ���� 21�� ���
			gotoxy(25, 27);
			printf("BLACKJACK!!");
			player1->person.money += 2.5 * player1->bet_money;	// ���� �ݾ� 2.5�踦 ��
			player1->bet_money = 0;
		}
		else if (player1_sum == dealer_sum) {	// �÷��̾� 1�� ������ ī�� ���� ���� ��� 
			gotoxy(25, 27);
			printf("PUSH!!     ");
			player1->person.money += player1->bet_money;	// ���� �ݾ� �ٽ� ��
			player1->bet_money = 0;
		}
		else if (player1_sum > dealer_sum) {	// �÷��̾� 1�� ī�� ���� �������� ū ���
			gotoxy(25, 27);
			printf("WIN!!     ");
			player1->person.money += 2* player1->bet_money;	// �¸�
			player1->bet_money = 0;
		}
		else {	// �ٸ� ��� ���
			gotoxy(25, 27);
			printf("LOSE!!     ");
			player1->bet_money = 0;
		}

		if (player2_sum == 21) {	// �÷��̾� 2�� ��� ���� �÷��̾� 1�� ����
			gotoxy(75, 27);
			printf("BLACKJACK!!");
			player2->person.money += 2.5 * player2->bet_money;
			player2->bet_money = 0;
		}
		else if (player2_sum == dealer_sum) {
			gotoxy(75, 27);
			printf("PUSH!!     ");
			player2->person.money += player2->bet_money;
			player2->bet_money = 0;
		}
		else if (player2_sum > dealer_sum) {
			gotoxy(75, 27);
			printf("WIN!!     ");
			player2->person.money += 2 * player2->bet_money;
			player2->bet_money = 0;
		}
		else {
			gotoxy(75, 27);
			printf("LOSE!!     ");
			player2->bet_money = 0;
		}
	}
	showMoney(player1, player2);	// �� ���� �ݾ��� ����� ���� �� �÷��̾� ���� ���� �ݾ��� �ٽ� ���
}
void mainControl(Deck* deck, Dealer* dealer, Gamer* player1, Gamer* player2) {	// ���� ���� ��Ʈ�� �Լ�
	int order = 0;
	Card open;
	
	for (int i = 0; i < 2; i++) {	// ó������ ī�带 �ΰ� ������
		open = deck->cards[deck->count++];	// ī�� ���� �ϰ� 
		remember_dealer(dealer, open);	// ������ �� ī�带 ����Ѵ�.
		if (open.number == 'A')	// ������ ī�尡 A�� ���
			dealer->gamer.hasA = TRUE;	// ������ hasA�� TRUE�� �ٲ�
		dealer->gamer.cards[dealer->gamer.num] = open;	// �������� ī�� �Ҵ�
		showCard(&open, 47 + (2 * dealer->gamer.num++), 7, OPEN);	// ���� �Ʒ��� ī�� ���
		calCardSum(&dealer->gamer);	// ������ ī�� ���� ���
		gotoxy(50, 6);
		showSum(&dealer->gamer);	// ������ ī�� ���� ������
		Sleep(500);

		open = deck->cards[deck->count++];
		remember_dealer(dealer, open);
		if (open.number == 'A')
			player1->hasA = TRUE;
		player1->cards[player1->num] = open;	// �÷��̾� 1���� ī�� �Ҵ�
		showCard(&open, 22 + (2 * player1->num++), 21, OPEN);	// �÷��̾� 1 ī�� ����
		gotoxy(25, 20);
		calCardSum(player1);	// �÷��̾� 1�� ī�� �� ���
		showSum(player1);		// �÷��̾� 1�� ī�� �� ���
		Sleep(500);

		open = deck->cards[deck->count++];
		remember_dealer(dealer, open);
		if (open.number == 'A')
			player2->hasA = TRUE;
		player2->cards[player2->num] = open;	// �÷��̾� 2���� ī�� �Ҵ�
		showCard(&open, 72 + (2 * player2->num++), 21, OPEN);
		gotoxy(75, 20);
		calCardSum(player2);	// �÷��̾� 2�� ī�� �� ���
		showSum(player2);		// �÷��̾� 2�� ī�� �� ���
		Sleep(500);
	}

	int choice;

	showWhoTurn(player1->person);	// �÷��̾� 1�� ���ʸ� ���
	while (!(player1->isLose == TRUE || player1->isStop == TRUE || player1->isBlackJack == TRUE)) {	// �÷��̾� 1�� ���ų�, ���߰ų�, ������ �ƴ� ���
		choice = choiceAction(player1);	// � �ൿ�� �� �� �Է� �ް�
		if (choice == 1) {	// ������ 1�� ���
			open = deck->cards[deck->count++];	// ī�� ����
			remember_dealer(dealer, open);
			if (open.number == 'A')
				player1->hasA = TRUE;
			player1->cards[player1->num] = open;
			showCard(&open, 22 + (2 * player1->num++), 21, OPEN);
			gotoxy(25, 20);
			calCardSum(player1);	// �÷��̾� 1�� ī�� �� ���
			showSum(player1);		// �÷��̾� 1�� ī�� �� ���
		}
		else {	 // �ٸ� ������ ���
			break;	// ����
		}
	}

	showWhoTurn(player2->person);	// �÷��̾� 2�� ���ʸ� ���
	while (!(player2->isLose == TRUE || player2->isStop == TRUE || player2->isBlackJack == TRUE)) {	// �÷��̾� 2�� ���ų�, ���߰ų�, ������ �ƴ� ���
		choice = choiceAction(player2);	// � �ص��� �� �� �Է� �ް�
		if (choice == 1) {	// 1�� ��� �÷��̾� 1�� ������ �ൿ�� ����
			open = deck->cards[deck->count++];
			remember_dealer(dealer, open);
			if (open.number == 'A')
				player2->hasA = TRUE;
			player2->cards[player2->num] = open;
			showCard(&open, 72 + (2 * player2->num++), 21, OPEN);
			gotoxy(75, 20);
			calCardSum(player2);
			showSum(player2);
		}
		else {
			break;
		}
	}
	showWhoTurn(dealer->gamer.person);	// ������ ������ ���
	Sleep(700);
	while (!(dealer->gamer.isLose == TRUE || dealer->gamer.isStop == TRUE || dealer->gamer.isBlackJack == TRUE)) {	// ������ ���ų�, ���߰ų�, ������ �ƴ� ���
		choice = expect_dealer(dealer);	// ������ ������ Ȯ���� ����Ͽ� �ൿ�� ����
		if (choice == 1) {	// 1�� ���	ī�带 open�ϰ� ī�� �� ���, ī�� �� ���
			open = deck->cards[deck->count++];
			remember_dealer(dealer, open);
			if (open.number == 'A')
				dealer->gamer.hasA = TRUE;
			dealer->gamer.cards[dealer->gamer.num] = open;
			showCard(&open, 47 + (2 * dealer->gamer.num++), 7, OPEN);
			gotoxy(50, 6);
			calCardSum(&dealer->gamer);
			showSum(&dealer->gamer);
			Sleep(700);
		}
		else {
			break;
		}
	}
	Sleep(700);
	compare(dealer, player1, player2);	// �������� ���� ī�� ���� ���Ͽ� ���� ����
	gotoxy(43, 2);
	line_clear();
}