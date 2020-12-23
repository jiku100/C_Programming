/*
* console.c
*
* 개요: 블랙잭 게임에서 콘솔 출력을 담당하는 모듈
*
* include: source.h, cursor.h, console.h를 사용함
*
* 입력: 없음
*
* 출력: 블랙잭 게임에서 필요한 콘솔 출력들
*
* 최종 코드 수정 날짜: 2020.11.21
* 버전: 1.0
* 작성자: 신석경
*
*/

#include "console.h"
#include "source.h"
#include "cursor.h"
#include <stdio.h>


void gameStart() {	// 게임 시작화면 출력 함수
	gotoxy(0, 0);
	printf("Black Jack!!!");
}
void drawCardBack(int x, int y) {	// 카드 뒷면 그리는 함수
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

void showShuffling() {		// 카드 섞이는 모습을 그리는 함수
	for (int i = 0; i < 2; i++) {
		for (int i = 0; i < 7; i++) {	// 카드를 13,5에서 퍼지고
			gotoxy(0, 0);
			printf("카드를 섞는 중.....");
			drawCardBack(13 - i, 5);
			drawCardBack(13, 5);
			drawCardBack(13 + i, 5);
			Sleep(10);
			console_clear();
		}
		for (int i = 0; i < 7; i++) {	// 카드를 13,5로 다시 모으고	
			gotoxy(0, 0);
			printf("카드를 섞는 중.....");
			drawCardBack(7 + i, 5);
			drawCardBack(13, 5);
			drawCardBack(19 - i, 5);
			Sleep(10);
			console_clear();
		}
		for (int i = 0; i < 4; i++) {	// 카드를 위 아래로 4번 섞음
			for (int i = 0; i < 2; i++) {	// 위로 옮기고
				gotoxy(0, 0);
				printf("카드를 섞는 중.....");
				drawCardBack(13, 5 - i);
				drawCardBack(13, 5);
				drawCardBack(13, 5 + i);
				Sleep(10);
				console_clear();
			}
			for (int i = 2; i >= 0; i--) {	// 아래로 옮기고
				gotoxy(0, 0);
				printf("카드를 섞는 중.....");
				drawCardBack(13, 5 - i);
				drawCardBack(13, 5);
				drawCardBack(13, 5 + i);
				Sleep(10);
				console_clear();
			}
		}
	}
	gotoxy(0, 0);
	printf("카드를 섞는 중.....");
	drawCardBack(13, 5);	// 13,5에 카드 뒷면 출력
}

void showCard(Card* card, int x, int y, int op) {	// 카드 오픈 함수
	gotoxy(x, y++);
	printf(" ----");
	gotoxy(x, y++);
	if (op == OPEN) {	// op이 OPEN이면
		if (card->number == '0') {	// card number가 0 이면
			printf("|10  |");	// 10으로 출력
			gotoxy(x, y++);
			printf("| %s |", card->shape);
			gotoxy(x, y++);
			printf("|  10|");
		}
		else {
			printf("|%c   |", card->number);	// 아닌 경우 number 출력
			gotoxy(x, y++);
			printf("| %s |", card->shape);
			gotoxy(x, y++);
			printf("|   %c|", card->number);
		}
	}
	else if (op == CLOSE) {	// op 가 CLOSE 이면
		printf("|XXXX|");	// 모두 뒷면으로 출력
		gotoxy(x, y++);
		printf("|XXXX|");
		gotoxy(x, y++);
		printf("|XXXX|");
	}
	gotoxy(x, y);
	printf(" ----\n");
}

void showDeck(Deck* deck, int op) {
	CONSOLE_SCREEN_BUFFER_INFO presentCur;	// 커서 위치 저장 변수
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);	// 현재 커서 위치 저장
	int X_init = presentCur.dwCursorPosition.X;	// 커서 X위치 저장
	int Y_init = presentCur.dwCursorPosition.Y;  // 커서 Y위치 저장
	int X = X_init;
	int Y = Y_init;
	for (int i = 0; i < 4; i++) {	// 4행
		for (int j = 0; j < 13; j++) {	// 13열로 카드 출력
			showCard(&(*deck).cards[13 * i + j], X, Y, op);
			X += CARD_X_OFFSET;
		}
		X = X_init;
		Y += CARD_Y_OFFSET;
	}
}

void showSum(Gamer* gamer) {		// 카드 합을 보여주는 함수
	if (gamer->isLose == FALSE) {	// 게이머가 안 죽었으면
		if (gamer->isBlackJack == TRUE) {	// 블랙잭이면
			printf("카드 합: BlackJack!!         ");	// 블랙잭 출력
		}
		else if (gamer->hasA && !(gamer->sum[1] > 21)) {	// A를 가지고 있고 21을 넘지 않는다면
			printf("카드 합: %d / %d", gamer->sum[0], gamer->sum[1]);	// 두 개 출력
		}
		else {
			printf("카드 합: %d        ", gamer->sum[0]);	// 한 개만 있으면 한 개만 출력
		}
	}
	else {
		printf("카드 합: BUST!!             ");	// 게이머가 죽었으면 죽은 거 출력
	}
}

void gameSet(Dealer* dealer, Gamer* player1, Gamer* player2) {	// 처음 게임 세팅 화면
	gotoxy(50, 5);
	printf("%s", dealer->gamer.person.name);
	drawCardBack(50, 12);
	gotoxy(25, 17);
	printf("%s", player1->person.name);
	gotoxy(75, 17);
	printf("%s", player2->person.name);
}


void showMoney(Gamer* player1, Gamer* player2) {	// 각 플레이어의 보유 금액을 출력
	gotoxy(25, 18);
	printf("보유 금액 : %.2f    ", player1->person.money);
	gotoxy(75, 18);
	printf("보유 금액 : %.2f    ", player2->person.money);
	gotoxy(25, 19);
	printf("베팅 금액 : %.2f    ", player1->bet_money);
	gotoxy(75, 19);
	printf("베팅 금액 : %.2f    ", player2->bet_money);
}

void playerSet(Gamer* player1, Gamer* player2) {	// 베팅 금액을 입력 받고 그 금액을 출력하는 함수
	betting(player1);	// 플레이어 1의 베팅을 받음
	gotoxy(25, 19);
	showMoney(player1, player2);
	betting(player2);
	gotoxy(75, 19);
	showMoney(player1, player2);
}


void showWhoTurn(Person p) {	// p의 차례를 나타내는 함수
	gotoxy(0, 2);
	line_clear();
	gotoxy(43, 2);
	printf("%11s Turn  ", p.name);
}