#ifndef CONSOLE
#define CONSOLE

#include "source.h"
#include "cursor.h"

void gameStart();	// ó�� ���� ���� ���
void drawCardBack(int x, int y);	// ī�� �޸� �׸��� �Լ�
void showShuffling();		// ī�� ���̴� ����� �׸��� �Լ�
void showCard(Card* card, int x, int y, int op); 	// ī�� ���� �Լ�
void showDeck(Deck* deck, int op);	// �� ��ü�� �����ִ� �Լ�
void showSum(Gamer* gamer);		// ī�� ���� �����ִ� �Լ�
void gameSet(Dealer* dealer, Gamer* player1, Gamer* player2);	// ���� ù ȭ�� ���� �Լ�
void playerSet(Gamer* player1, Gamer* player2);	// �÷��̾��� ���� �ݾ��� �����ϴ� �Լ�
void showWhoTurn(Person p);	// ������ ����ϴ� �Լ�
void showMoney(Gamer* player1, Gamer* player2);	// ���� �ݾ��� ����ϴ� �Լ�

#endif // !CONSOLE
