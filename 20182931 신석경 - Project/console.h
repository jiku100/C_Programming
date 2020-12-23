#ifndef CONSOLE
#define CONSOLE

#include "source.h"
#include "cursor.h"

void gameStart();	// 처음 게임 시작 출력
void drawCardBack(int x, int y);	// 카드 뒷면 그리는 함수
void showShuffling();		// 카드 섞이는 모습을 그리는 함수
void showCard(Card* card, int x, int y, int op); 	// 카드 오픈 함수
void showDeck(Deck* deck, int op);	// 덱 전체를 보여주는 함수
void showSum(Gamer* gamer);		// 카드 합을 보여주는 함수
void gameSet(Dealer* dealer, Gamer* player1, Gamer* player2);	// 게임 첫 화면 세팅 함수
void playerSet(Gamer* player1, Gamer* player2);	// 플레이어의 베팅 금액을 세팅하는 함수
void showWhoTurn(Person p);	// 순서를 출력하는 함수
void showMoney(Gamer* player1, Gamer* player2);	// 보유 금액을 출력하는 함수

#endif // !CONSOLE
