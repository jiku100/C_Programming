/*
* source.c
*
* ����: ���� ���� �� ���ҽ��� ���� ó�� �� ���� ��� ��� ���
*
* include: source.h, cursor.h�� �����
*
* �Է�: �� �Լ����� �ʿ�� �ϴ� �Էµ�
*
* ���: ���� �ɼ��� �Է� �ޱ� ���� ���� ���
*
* ���� �ڵ� ���� ��¥: 2020.11.21
* ����: 1.0
* �ۼ���: �ż���
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include "source.h"
#include "cursor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void setInit(Dealer* dealer, Gamer* player1, Gamer* player2) {	// �� ������ �÷��̷��� �ʱ�ȭ�ϴ� �Լ�
	memset(&dealer->gamer.cards, 0, sizeof(dealer->gamer.cards)); // ������ ī�带 �޸� �ʱ�ȭ
	memset(&dealer->remember, 0, sizeof(dealer->remember));	// ������ ī�� ����ϴ� �� �ʱ�ȭ
	dealer->gamer.num = 0;	// ī�� ���� 0����
	dealer->gamer.sum[0] = 0;	// ī�� �� 0
	dealer->gamer.sum[1] = 0;	// ī�� �� 0
	dealer->gamer.hasA = FALSE;	// A ���� ���� FALSE
	dealer->gamer.isLose = FALSE;	// Lose ���� FALSE
	dealer->gamer.isBlackJack = FALSE;	// ���� Ȯ�� ���� FASLE
	dealer->gamer.isStop = FALSE;	// ���ߴ� Ȯ�� ���� FASLE

	// �������� ���� ����
	memset(&player1->cards, 0, sizeof(player1->cards));
	player1->num = 0;
	player1->sum[0] = 0;
	player1->sum[1] = 0;
	player1->hasA = FALSE;
	player1->isLose = FALSE;
	player1->isBlackJack = FALSE;
	player1->isStop = FALSE;

	memset(&player2->cards, 0, sizeof(player2->cards));
	player2->num = 0;
	player2->sum[0] = 0;
	player2->sum[1] = 0;
	player2->hasA = FALSE;
	player2->isLose = FALSE;
	player2->isBlackJack = FALSE;
	player2->isStop = FALSE;
}
void clearData(Dealer* dealer, Gamer* player1, Gamer* player2) {	// ��� ������ �÷��̾��� �����͸� �ʱ�ȭ�ϴ� �Լ�
	memset(dealer, 0, sizeof(Dealer));	// ���� �޸� �ʱ�ȭ
	strcpy(dealer->gamer.person.name, "Dealer");	// ���� �̸� ����
	memset(player1, 0, sizeof(Gamer));	// �÷��̾� 1 �޸� Ŭ����
	memset(player2, 0, sizeof(Gamer));	// �÷��̾� 2 �޸� Ŭ����
}
char int_to_cardNumber(int number) {	// �Էµ� ���ڸ� ������ ī�� �ѹ��� �ٲٴ� �Լ�
	switch (number)
	{
	case 1: return 'A'; break;
	case 2: return '2'; break;
	case 3: return '3'; break;
	case 4: return '4'; break;
	case 5: return '5'; break;
	case 6: return '6'; break;
	case 7: return '7'; break;
	case 8: return '8'; break;
	case 9: return '9'; break;
	case 10: return '0'; break;
	case 11: return 'J'; break;
	case 12: return 'Q'; break;
	case 13: return 'K'; break;
	default:
		return '0';
		break;
	}
}

char cardNumber_to_int(char number) {	// �Էµ� ī�� �ѹ��� ���� ���ڷ� �ٲٴ� �Լ�
	switch (number)
	{
	case 'A': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break;
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	case '0': return 10; break;
	case 'J': return 10; break;
	case 'Q': return 10; break;
	case 'K': return 10; break;
	default:
		return '0';
		break;
	}
}

void filldeck(Deck* deck) {	// �� ����
	for (int i = 0; i < 52; i++) {	// 52���� ī�带 ����
		switch (i / 13)	// 13���� ���� ��
		{
		case SPADES:	// 0�̸�
			(*deck).cards[i].number = int_to_cardNumber(i % 13 + 1);	// ī���� ���ڸ� A ~ K�� ���� 
			(*deck).cards[i].shape = "��";			// ī�� ����� Spades�� ����
			(*deck).cards[i].name = "<Spades>";		// ī�� �̸��� <Spades>�� ����
			break;
		case HEARTS:	// 1�̸�
			(*deck).cards[i].number = int_to_cardNumber(i % 13 + 1);	// ī���� ���ڸ� A ~ K�� ����
			(*deck).cards[i].shape = "��";			// ī�� ����� Hearts�� ����
			(*deck).cards[i].name = "<Hearts>";		// ī�� �̸��� <Hearts>�� ����
			break;
		case DIAMONDS:	// 2�̸�
			(*deck).cards[i].number = int_to_cardNumber(i % 13 + 1);	// ī���� ���ڸ� A ~ K�� ����
			(*deck).cards[i].shape = "��";			// ī�� ����� Diamonds�� ����
			(*deck).cards[i].name = "<Diamonds>";	// ī�� �̸��� <Diamonds>�� ����
			break;
		case CLUBS:		// 3�̸�
			(*deck).cards[i].number = int_to_cardNumber(i % 13 + 1);	// ī���� ���ڸ� A ~ K�� ����
			(*deck).cards[i].shape = "��";			// ī�� ����� Clubs�� ����
			(*deck).cards[i].name = "<Clubs>";		// ī�� �̸��� <Clubs>�� ����
			break;
		default:
			break;
		}
	}
}

void betting(Gamer* player) {	// ���ñݾ� �Է� �ޱ�
	float bet_money;
	int isright;
	do
	{
		gotoxy(0, 0);
		line_clear();
		gotoxy(0, 0);	// 0,0 ���� Ŭ����
		printf("%s�� ���� �ݾ��� �Է��ϼ���: ", player->person.name);
		isright = scanf("%f", &bet_money);	// ���� �ݾ� �Է� �ް�
		while (getchar() != '\n');
		if (isright != 1 || player->person.money < bet_money) {	// ���� �ݾ׺��� ū ���
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 1);
			printf("�˸��� �ݾ��� �Է��ϼ���.");
		}
		if (isright == 1 && player->person.money >= bet_money) {	// �ùٸ� �Է��� ���
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 1);
			player->person.money -= bet_money;	// ���� �ݾ׿��� ���� �ݾ� ����
			player->bet_money = bet_money;	// ���� �ݾ� ����
			return;
		}
	} while (TRUE);	// �ùٸ� �Է��� �� ������ �ݺ�
}

void calCardSum(Gamer* gamer) {	// ī�� �� ���
	gamer->sum[0] = 0;
	gamer->sum[1] = 0;
	for (int i = 0; i < gamer->num; i++) {	// ī�� ���� ������
		if (gamer->hasA == TRUE) {	// A�� ��������
			if (gamer->cards[i].number == 'A')	// ī�尡 A�� ���
				gamer->sum[1] += cardNumber_to_int(gamer->cards[i].number) + 10;	// 1�� index�� 11�� ����
			else
				gamer->sum[1] += cardNumber_to_int(gamer->cards[i].number);	// �ƴ� ��� �״�� 1�� index�� ����
		}
		gamer->sum[0] += cardNumber_to_int(gamer->cards[i].number);	// 0�� index���� ���� �״�θ� �߰�
	}
	if (gamer->sum[0] == 21 || gamer->sum[1] == 21) {	// ���� 0�� Ȥ�� 1���� 21�̸�
		gamer->isBlackJack = TRUE;	// ���� �����
		gamer->isStop = TRUE;	// ����
	}
	if (gamer->sum[0] > 21)	// 0���� 21�� ������
		gamer->isLose = TRUE;	// ��
}

void input_player(Gamer* gamer) {	// �÷��̾ �Է� �޴� �Լ�
	static int order = 0;	// ���� ���� ����
	float money;
	char* name = malloc(sizeof(char) * 16);	// �̸� �Է� ���� ���� �ʱ�ȭ
	int isright;
	do
	{
		gotoxy(0, 0);
		line_clear();
		gotoxy(0, 0);
		printf("player%d�� �̸��� �Է��ϼ���: ", order + 1);
		isright = scanf("%s", name);	// �̸� �Է� �ް�
		if (isright != 1) {	// �ùٸ� �Է��� �ƴ� ��� ���� ���
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			printf("�ùٸ� �̸��� �Է��ϼ���!");
			while (getchar() != '\n');
		}
		if (isright == 1) {
			strcpy(gamer->person.name, name);	// �ùٸ� �Է��̸� gamer ������ ��� �̸��� name�� ����
			break;
		}
	} while (TRUE);

	do
	{
		gotoxy(0, 1);
		line_clear();
		gotoxy(0, 1);
		printf("player%d�� ���� �Է��ϼ���: ", order + 1);
		isright = scanf("%f", &money);	// �� �Է�
		if (isright != 1 || money < 0) {	// �߸��� �Է¿� ���� ���� ���
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 2);
			printf("���� �Ǽ��� �Է��ϼ���!");
			while (getchar() != '\n');
		}
		if (isright == 1 &&  money > 0) {	// �ùٸ� �Է��� ��� 
			gamer->person.money = money;	// ���� �ݾ׿� �߰�
			break;
		}
	} while (TRUE);
	order = (order + 1) % 2;	// order�� 1�� 2�� �ݺ�
	console_clear();	// �ܼ� Ŭ����
}

int choiceAction(Gamer* player) {	// �÷��̾ ���� �ൿ�� �� �� �����ϴ� �Լ�
	char choice;
	int isright;

	do
	{
		gotoxy(36, 3);
		line_clear();
		gotoxy(36, 3);
		printf("ī�带 �����Ͻðڽ��ϱ�? <y or n>: ");
		isright = scanf("%c", &choice);	// �Է� �ް�
		while (getchar() != '\n');
		if (isright != 1 || !(choice == 'y' || choice == 'n')) {	// y�� n�� �ƴ� ��� �ٽ� �Է� ����
			gotoxy(34, 3);
			line_clear();
			gotoxy(0, 0);
			printf("y �� n�� �Է��ϼ���.");
		}
		if (isright == 1 && choice == 'y') {	// y�̸� 1 ����
			gotoxy(0, 0);
			line_clear();
			gotoxy(36, 3);
			line_clear();
			return 1;
		}
		else if (isright == 1 && choice == 'n') {	// n�̸� 0 ����
			player->isStop = TRUE;
			gotoxy(0, 0);
			line_clear();
			gotoxy(36, 3);
			line_clear();
			return 0;
		}
	} while (TRUE);
}
	
void remember_dealer(Dealer* dealer, Card card) {	// ������ ī�带 ����ϴ� �Լ�
	// ���� card�� �ѹ��� ���� ������ remember �迭�� �� ����
	switch (card.number)	
	{
	case 'A': dealer->remember[0]++; break;	
	case '2': dealer->remember[1]++; break;
	case '3': dealer->remember[2]++; break;
	case '4': dealer->remember[3]++; break;
	case '5': dealer->remember[4]++; break;
	case '6': dealer->remember[5]++; break;
	case '7': dealer->remember[6]++; break;
	case '8': dealer->remember[7]++; break;
	case '9': dealer->remember[8]++; break;
	case '0': dealer->remember[9]++; break;
	case 'J': dealer->remember[10]++; break;
	case 'Q': dealer->remember[11]++; break;
	case 'K': dealer->remember[12]++; break;
	default: 
		break;
	}
}

int expect_dealer(Dealer* dealer) {	// ������ Ȯ���� ����Ͽ� �ൿ�� �����ϴ� �Լ�
	float sum = 0;		// ������ ���� �� �ִ� ī�� �ѹ��� ��� ��
	int factor = 0;		// ī�� ���� ����� �� ���� ���
	int open_num = 0;	// ������� open�� ī�� ������ �����ϴ� ����
	int diff;
	float expect_value = 0;
	if (dealer->gamer.sum[0] < 17 && dealer->gamer.sum[1] < 17) {	// ������ 17���ϸ� ������ open �ؾ� ��
		return 1;
	}
	else {	// 17 ���� ū ���
		for (int i = 0; i < 13; i++) {	 // A ~ K ������ ī��
			factor = i + 1;	// �� index���� 1 ū ���� ���� ī�� ����
			if (factor > 10)	// J Q K�� �� 10���� ����
				factor = 10;
			open_num += dealer->remember[i];	// ���� remember[i]�� �ִ� ���� i + 1 ¥�� ī�尡 open�� ����, 
			sum += (4 - dealer->remember[i]) * factor;	// 4 - (i + 1) ī�尡 ���� �� ������ factor�� ���Ͽ� sum�� ����
		}
		expect_value = sum / (52 - open_num);	// ������ ���� ī�� ���� sum�� ������ ���� ī�� ������ ������ ���� ���� ����
		
		if (dealer->gamer.hasA == TRUE && dealer->gamer.sum[1] <= 21) {	// ������ A�� ������ ������ sum[1]�� 21���� �۰ų� ���� ���
			diff = 21 - dealer->gamer.sum[1];	// 21�� sum[1] ������ ���̸� diff�� ����
		}
		else {	// �ƴ� ���, �� sum[1] > 21�� ���
			diff = 21 - dealer->gamer.sum[0];	// 21�� dealer sum[0]���� ���̸� diff�� ����
		}
		gotoxy(0, 0);
		if (expect_value <= diff) {	// ���� ���� ���� diff���� ������ 1 ��ȯ
			return 1;
		}
		else {	// �ƴϸ� ���߰� 0 ��ȯ
			dealer->gamer.isStop = TRUE;
			return 0;
		}
	}
}

int result_sum(Gamer* gamer) {	// ���� ī�� �� ����� ��ȯ�ϴ� �Լ�
	if (gamer->isLose == TRUE) {	// ������
		return 0;	// 0 ��ȯ
	}
	if (gamer->isBlackJack == TRUE) {	// �����̸�
		return 21;	// 21 ��ȯ
	}
	if (gamer->hasA == FALSE){	// A�� ������ ������ sum[0] ��ȯ, �̶� �̹� 21�� ���� ���� ������ �ɷ��� ������ ��� ����
		return gamer->sum[0];
	}
	else if (gamer->hasA == TRUE) {	// A�� �����ٸ�
		if (gamer->sum[1] < 21) {	// sum[1]�� 21���� ������
			return gamer->sum[1];	// sum[1]�� ���
		}
		else {	// �ƴϸ� �� 21�� ������
			return gamer->sum[0];	// sum[0]�� ���
		}
	}
}