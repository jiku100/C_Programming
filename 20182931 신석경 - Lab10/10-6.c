#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Card {
	int number;
	char* shape;
	char* name;
};

typedef struct Card Card;

struct Deck {
	Card cards[52];
	int count;
};

typedef struct Deck Deck;


enum SHAPE {
	SPADES=0,
	HEARTS,
	DIAMONDS,
	CLUBS
};

void filldeck(Deck* deck);
void shuffle(Deck* deck);
void deal(Deck* deck);

int main(void) {
	Deck deck = { 0 };

	printf("ī����ӿ� 3���� ������ �����մϴ�...\n");
	printf("52���� ī�带 ���� �ݴϴ�.\n");
	printf("ī�带 7�� �� ������ �ݴϴ�.\n\n");
	filldeck(&deck);
	shuffle(&deck);
	deal(&deck);
	return 0;
}

void filldeck(Deck* deck) {
	for (int i = 0; i < 52; i++) {
		switch (i/13)
		{
		case SPADES:
			(*deck).cards[i].number = i % 13 + 1;
			(*deck).cards[i].shape = "��";
			(*deck).cards[i].name = "<Spades>";
			break;
		case HEARTS:
			(*deck).cards[i].number = i % 13 + 1;
			(*deck).cards[i].shape = "��";
			(*deck).cards[i].name = "<Hearts>";
			break;
		case DIAMONDS:
			(*deck).cards[i].number = i % 13 + 1;
			(*deck).cards[i].shape = "��";
			(*deck).cards[i].name = "<Diamonds>";
			break;
		case CLUBS:
			(*deck).cards[i].number = i % 13 + 1;
			(*deck).cards[i].shape = "��";
			(*deck).cards[i].name = "<Clubs>";
			break;
		default:
			break;
		}
	}
}

void shuffle(Deck* deck) {
	srand((unsigned long)time(NULL)); 
	Card temp; 
	int rn;
	for (int i = 0; i < 51; i++) {
		rn = rand() % (52 - i) + i;	// i ���� num-1 ���̿� ������ ���� ����
		temp = (*deck).cards[i]; 
		(*deck).cards[i] = (*deck).cards[rn];
		(*deck).cards[rn] = temp;
	} 
}

void deal(Deck* deck) {
	printf("     player 1           player 2           player 3\n");
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			switch ((*deck).cards[(*deck).count].number)
			{
			case 1:
				printf(" %2s of %s%-10s", "A", (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			case 11:
				printf(" %2s of %s%-10s", "J", (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			case 12:
				printf(" %2s of %s%-10s", "Q", (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			case 13:
				printf(" %2s of %s%-10s", "K", (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			default:
				printf(" %2d of %s%-10s", (*deck).cards[(*deck).count].number, (*deck).cards[(*deck).count].shape, (*deck).cards[(*deck).count].name);
				break;
			}
			(*deck).count++;
		}
		printf("\n");
	}
}