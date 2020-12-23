/*******************************************************
* ���ϸ�: pocker.c
* ���α׷� ����: �⺻���� ī������� �� �� �ִ� ���α׷�
*	����ü 1: card�� ��Ÿ���� Card ����ü
*   ����ü 2: card�� 52�� ������ ��Ÿ���� Deck ����ü
*   ����ü 3: ����� ��Ÿ���� Gamer ����ü
*	�� ����: filldeck() ����
*	�� ����: shuffle() ����
*	�� �й�: deal() ����
*	���� ���ϱ�: cardOpen() ����
*
*	�Է� 1: ���� ������ 3���� �̸�
*   
*	���: �� �������� ī�� ���� �� ����
*
* ��¥: 2020�� 11�� 04��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Card {		// ī���� ������ ������ ����ü
	int number;		// ī���� ����
	char* shape;	// ī���� ���
	char* name;		// ī���� ��� �̸�
};
typedef struct Card Card;

struct Deck {		// ���� ������ ������ ����ü
	Card cards[52];	// ī�� 52��
	int count;		// ���� �� ���� ī�带 open �ߴ��� Ȯ���ϴ� ����
};
typedef struct Deck Deck;

struct Gamer {
	char name[16];	// ������ �̸�
	Card cards[7];	// 7���� ī�� ����
	int num;		// ī�� ������ ��Ÿ���� ����
};
typedef struct Gamer Gamer;

enum SHAPE {	// �� ����� ��Ÿ���� enum
	SPADES = 0,
	HEARTS,
	DIAMONDS,
	CLUBS
};

void filldeck(Deck* deck);	// �� ����
void shuffle(Deck* deck);	// �� ����
void deal(Gamer* gamers, Deck* deck);		// ī�� �����ֱ�
void cardOpen(Gamer* gamers);	// ���� ��� Ȯ���ϱ�

int main(void) {
	Deck deck = { 0 };			// �� ����ü ����
	Gamer gamers[3] = { 0 };	// Gamer ���� 3¥�� ����ü �迭 ����
	char op;	// ������ ��� ������ ������ ����� �����ϴ� ����

	printf("��Ŀ ������ ������ 3���� ���ʷ� �Է��Ͻÿ�\n");
	printf("���� 1: "); scanf("%s", gamers[0].name);		// ���� �̸� �Է� �ޱ�
	printf("���� 2: "); scanf("%s", gamers[1].name);
	printf("���� 3: "); scanf("%s", gamers[2].name);

	filldeck(&deck);	// �� ���� �Լ� ����
	do{
		printf("��Ŀ ������ �����մϴ�.\n\n");
		shuffle(&deck);
		deal(gamers, &deck);	// �� �й�
		cardOpen(gamers);
		printf("��� �Ͻðڽ��ϱ�?[y/n]: ");
		while (scanf(" %c", &op) != 1 || !(op == 'n' || op == 'y')) {	// ���� �Է��� ������ �ݺ�
			while (getchar() != '\n');
			printf("y Ȥ�� n�� �Է����ּ���.\n");
			printf("��� �Ͻðڽ��ϱ�?[y/n]: ");
		}
		printf("\n");
	}while (op != 'n');
	return 0;
}

void filldeck(Deck* deck) {		// �� ���� �Լ�
	for (int i = 0; i < 52; i++) {	// 52���� ī�带 ����
		switch (i / 13)	// 13���� ���� ��
		{
		case SPADES:	// 0�̸�
			(*deck).cards[i].number = i % 13 + 1;	// ī���� ���ڸ� 1 ~ 13�� ���� 
			(*deck).cards[i].shape = "��";			// ī�� ����� Spades�� ����
			(*deck).cards[i].name = "<Spades>";		// ī�� �̸��� <Spades>�� ����
			break;
		case HEARTS:	// 1�̸�
			(*deck).cards[i].number = i % 13 + 1;	// ī���� ���ڸ� 1 ~ 13�� ����
			(*deck).cards[i].shape = "��";			// ī�� ����� Hearts�� ����
			(*deck).cards[i].name = "<Hearts>";		// ī�� �̸��� <Hearts>�� ����
			break;
		case DIAMONDS:	// 2�̸�
			(*deck).cards[i].number = i % 13 + 1;	// ī���� ���ڸ� 1 ~ 13�� ����
			(*deck).cards[i].shape = "��";			// ī�� ����� Diamonds�� ����
			(*deck).cards[i].name = "<Diamonds>";	// ī�� �̸��� <Diamonds>�� ����
			break;
		case CLUBS:		// 3�̸�
			(*deck).cards[i].number = i % 13 + 1;	// ī���� ���ڸ� 1 ~ 13�� ����
			(*deck).cards[i].shape = "��";			// ī�� ����� Clubs�� ����
			(*deck).cards[i].name = "<Clubs>";		// ī�� �̸��� <Clubs>�� ����
			break;
		default:
			break;
		}
	}
}

void shuffle(Deck* deck) {		// �� ���� �Լ�
	srand((unsigned long)time(NULL));
	Card temp;
	int rn;
	for (int i = 0; i < 51; i++) {	// 51�� ����
		rn = rand() % (52 - i) + i;	// i ���� 51 ���̿� ������ ���� ����
		temp = (*deck).cards[i];	// �� �� ī�带 �ٲ۴�.
		(*deck).cards[i] = (*deck).cards[rn];
		(*deck).cards[rn] = temp;
	}
	(*deck).count = 0;	// �� open ��ġ �ʱ�ȭ
}

void deal(Gamer* gamers, Deck* deck) {	// �� �й� �Լ�
	for (int i = 0; i < 3; i++) {
		gamers[i].num = 0;	// �� �й� �� ������ �ִ� ī�� ����
	}
	printf("    %-15s%-15s%-15s\n\n", gamers[0].name, gamers[1].name, gamers[2].name);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			switch ((*deck).cards[(*deck).count].number)
			{	// ���� ���� ���� �տ� �ִ� ī���� ���� ���
			case 1:
				printf(" %2s%s%-10s", "A", (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			case 11:
				printf(" %2s%s%-10s", "J", (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			case 12:
				printf(" %2s%s%-10s", "Q", (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			case 13:
				printf(" %2s%s%-10s", "K", (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			default:
				printf(" %2d%s%-10s", (*deck).cards[(*deck).count].number, (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			}
			gamers[j].cards[gamers[j].num++] = (*deck).cards[(*deck).count++];	
			// ����� ��ġ�� gamer�� ī�忡 open�� ī�� �߰�
			// ���� gamer�� ī�� ���� +1, deck�� ���� ī��� �̵� (count++)
		}
		printf("\n");
	}
	printf("\n\n");
}

void cardOpen(Gamer* gamers) {	// ������ ����� ����ϴ� �Լ�
	static char* ranks[10] = { "None", "One pair", "Two pair", "Triple" };	// ���� �̸� ����
	int winner;	// ���� ���� ����
	int result[3] = { 0, };	// �� ��������� ������ �����ϴ� ����
	int count = 0;		// ���� ������ ������ �����ϴ� ����
	for (int i = 0; i < 3; i++) {	// 3���� ��� �˻�
		for (int j = 0; j < 6; j++) {	// 0 ~ 6�� index �� �� ī�带 ��������
			count = 0;
			for (int k = j + 1; k < 7; k++) {	// j�� index ���Ŀ� ī�带 j�� index ī��� ��
				if (gamers[i].cards[j].number == gamers[i].cards[k].number)
					count++;
			}
			switch (count)
			{
			case 0:	// �ϳ��� �� ��ġ�� �״��
				break;
			case 1:	// �ϳ��� ��ġ��
				if (result[i] <= 1)	result[i] += 1;	
				// ���� ������ 1���� �̸� 1�߰�
				// �� 2���� ����� ���� �ִ�.
				// ���� ���� ������ 0 �� ��� 1�� �Ǿ� ����� �ǹ�
				// ���� ���� ������ 1�� ��� 2�� �Ǿ� ����� �ǹ�
				break;
			case 2:	// �ΰ��� ��ġ��
				result[i] = 3;	// Ʈ���� �ǹ�
			default:
				break;
			}
		}
	}

	winner = 0;	// 0�� index ����� winner�� ����
	for (int i = 0; i < 3; i++) {
		printf("\t%s : rank = %s\n", gamers[i].name, ranks[result[i]]);
		if (result[i] > result[winner]) {	// i index ����� ����� winner�� ������� ũ��
			winner = i;	// winner �ٲ�
		}
	}
	printf("\n\tThe winner is %s by rank of %s.\n\n", gamers[winner].name, ranks[result[winner]]);	// winner�� �̸��� winner�� result�� rank ���
}