/*
* control.c
*
* 개요: 블랙잭 게임의 흐름을 담당하는 모듈
*
* include: source.h, cursor.h, control.h, console.h를 사용함
*
* 입력: 각 함수에서 필요로 하는 입력들
*
* 출력: 보통 옵션을 입력 받기 위한 질문 출력 및 게임이 진행되고 있는 상황들
*
* 최종 코드 수정 날짜: 2020.11.21
* 버전: 1.0
* 작성자: 신석경
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include "source.h"
#include "control.h"
#include "console.h"
#include "cursor.h"
#include <stdio.h>
#include <time.h>

int gameStartOption() {	// 처음 게임을 시작하는 여부를 결정하는 함수
	
	char choice;	// 선택을 저장하는 변수
	int isright;	// 입력이 올바른지 확인하는 변수

	do
	{
		gotoxy(0, 1);	// 0 , 1로 이동하여 한 줄을 삭제함
		line_clear();
		gotoxy(0, 1);

		printf("게임을 시작하겠습니까? <y or n>: ");
		isright = scanf("%c", &choice);		// 시작 옵션을 입력 받는다.
		while (getchar() != '\n');	// 버퍼를 지움

		if (isright != 1 || !(choice == 'y' || choice == 'n')) {	// 입력이 잘못 되었거나, 옵션이 y, n이 아닐 경우
			gotoxy(0, 2);
			line_clear();
			gotoxy(0, 2);	// 0,2 한 줄을 지우고
			printf("y 나 n을 입력하세요.");	// 오류 출력
		}
		if (isright == 1 && choice == 'y') {	// 입력이 올바르게 y인 경우
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 3);
			line_clear();
			// 0,1 0,2 0,3 세 줄을 다 지움
			return 1;	// 1 반환
		}
		else if (isright == 1 && choice == 'n') {	// 입력이 올바르게 n인 경우
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 3);
			line_clear();
			// 세 줄을 지우고
			return 0;	// 0 반환
		}
	} while (TRUE);	// 입력이 올바르게 될 때까지 반복
}

int gameContinueOption() {	// 게임을 계속 진행할 지 확인하는 함수
	char choice;
	int isright;

	do
	{
		gotoxy(0, 0);
		line_clear();
		gotoxy(0, 0);	// 0,0 한 줄을 지움

		printf("게임을 계속하겠습니까? <y or n>: ");
		isright = scanf("%c", &choice);
		while (getchar() != '\n');

		if (isright != 1 || !(choice == 'y' || choice == 'n')) {	// 입력이 y 혹은 n이 아닌 경우
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 1);	// 0,1 한 줄 지움
			printf("y 나 n을 입력하세요."); //0,1에 출력
		}
		if (isright == 1 && choice == 'y') {	// y이면
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			line_clear();	// 0,0 0,1 두 줄을 지우고 1 반환
			return 1;
		}
		else if (isright == 1 && choice == 'n') {	// n이면
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			line_clear();	// 0,0 0,1 두 줄을 지우고 0 반환
			return 0;
		}
	} while (TRUE);	// 올바른 입력이 입력될 때까지 반복 
}

void shuffle(Deck* deck) {	// 덱 섞기
	srand((unsigned long)time(NULL));
	
	Card temp;
	int rn;
	
	console_clear();	// 콘솔 클리어
	drawCardBack(13, 5);	// 13, 5에 카드 한 장을 뒷면으로 출력

	for (int i = 0; i < 51; i++) {	// 51번 돌며
		rn = rand() % (52 - i) + i;	// i 부터 51 사이에 임의의 정수 생성
		temp = deck->cards[i];	// 그 두 카드를 바꾼다.
		deck->cards[i] = deck->cards[rn];
		deck->cards[rn] = temp;
	}
	deck->count = 0;	// 덱 open 위치 초기화
	Sleep(500);	// 0.5 초를 기다림
	console_clear();	// 콘솔 클리어
	showShuffling();	// 카드 섞는 모습을 보여줌
}

void compare(Dealer* dealer, Gamer* player1, Gamer* player2) { // 승자 결정 함수
	int dealer_sum = result_sum(&dealer->gamer);	// dealer의 카드 합 결과를 dealer_sum에 저장
	int player1_sum = result_sum(player1);		// player1의 카드 합 결과를 player1_sum에 저장
	int player2_sum = result_sum(player2);		// player2의 카드 합 결과를 player2_sum에 저장

	if (dealer_sum == 0) {	// 딜러의 카드 합이 0인 경우 (Bust)
		if (player1_sum == 21) {	// 플레이어 1의 카드 합이 21인 경우
			gotoxy(25, 27);
			printf("BLACKJACK!!");		// 블랙잭 출력
			player1->person.money += 2.5 * player1->bet_money;	 // 베팅 금액 2.5 배를 얻어감
			player1->bet_money = 0;	// 베팅 금액 0으로 초기화
		}
		else if (player1_sum == 0) {	// 플레이어 1의 카드 합이 0인 경우
			gotoxy(25, 27);
			printf("LOSE!!     ");	// 지는 것 출력
			player1->bet_money = 0;	// 베팅 금액을 0으로 설정
		}
		else {	// 다른 경우, 즉 카드 합이 존재하는 경우
			gotoxy(25, 27);
			printf("WIN!!      ");	// 승리 출력
			player1->person.money += 2 * player1->bet_money;	// 베팅 금액의 2배를 얻어감
			player1->bet_money = 0;
		}

		if (player2_sum == 21) {	// 플레이어 2의 경우 위의 플레이어 1과 동일함
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
	else if (dealer_sum == 21) {	// 딜러의 합이 21인 경우 (블랙잭)
		if (player1_sum == 21) {	// 플레이어 1 카드 합이 21인 경우
			gotoxy(25, 27);
			printf("PUSH!!     ");	// 비긴 것 출력
			player1->person.money += player1->bet_money;	// 베팅 금액 그대로 다시 돌려 받음
			player1->bet_money = 0;
		}
		else {	// 다른 모든 경우는
			gotoxy(25, 27);
			printf("LOSE!!     ");	// 지는 거 출력
			player1->bet_money = 0;
		}

		if (player2_sum == 21) {	// 플레이어 2의 경우 위의 플레이어 1과 동일
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
	else {	// 딜러의 카드 합이 21이 아닌 다른 숫자로 존재하는 경우
		if (player1_sum == 21) {	// 플레이어 1의 카드 합이 21인 경우
			gotoxy(25, 27);
			printf("BLACKJACK!!");
			player1->person.money += 2.5 * player1->bet_money;	// 베팅 금액 2.5배를 얻어감
			player1->bet_money = 0;
		}
		else if (player1_sum == dealer_sum) {	// 플레이어 1과 딜러의 카드 합이 같은 경우 
			gotoxy(25, 27);
			printf("PUSH!!     ");
			player1->person.money += player1->bet_money;	// 베팅 금액 다시 얻어감
			player1->bet_money = 0;
		}
		else if (player1_sum > dealer_sum) {	// 플레이어 1의 카드 합이 딜러보다 큰 경우
			gotoxy(25, 27);
			printf("WIN!!     ");
			player1->person.money += 2* player1->bet_money;	// 승리
			player1->bet_money = 0;
		}
		else {	// 다른 모든 경우
			gotoxy(25, 27);
			printf("LOSE!!     ");
			player1->bet_money = 0;
		}

		if (player2_sum == 21) {	// 플레이어 2의 경우 위의 플레이어 1과 동일
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
	showMoney(player1, player2);	// 각 보유 금액을 계산한 다음 각 플레이어 들의 보유 금액을 다시 출력
}
void mainControl(Deck* deck, Dealer* dealer, Gamer* player1, Gamer* player2) {	// 게임 진행 컨트롤 함수
	int order = 0;
	Card open;
	
	for (int i = 0; i < 2; i++) {	// 처음에는 카드를 두개 오픈함
		open = deck->cards[deck->count++];	// 카드 오픈 하고 
		remember_dealer(dealer, open);	// 딜러는 그 카드를 기억한다.
		if (open.number == 'A')	// 오픈한 카드가 A인 경우
			dealer->gamer.hasA = TRUE;	// 딜러의 hasA를 TRUE로 바꿈
		dealer->gamer.cards[dealer->gamer.num] = open;	// 딜러에게 카드 할당
		showCard(&open, 47 + (2 * dealer->gamer.num++), 7, OPEN);	// 딜러 아래에 카드 출력
		calCardSum(&dealer->gamer);	// 딜러의 카드 합을 계산
		gotoxy(50, 6);
		showSum(&dealer->gamer);	// 딜러의 카드 합을 보여줌
		Sleep(500);

		open = deck->cards[deck->count++];
		remember_dealer(dealer, open);
		if (open.number == 'A')
			player1->hasA = TRUE;
		player1->cards[player1->num] = open;	// 플레이어 1에게 카드 할당
		showCard(&open, 22 + (2 * player1->num++), 21, OPEN);	// 플레이어 1 카드 오픈
		gotoxy(25, 20);
		calCardSum(player1);	// 플레이어 1의 카드 합 계산
		showSum(player1);		// 플레이어 1의 카드 합 출력
		Sleep(500);

		open = deck->cards[deck->count++];
		remember_dealer(dealer, open);
		if (open.number == 'A')
			player2->hasA = TRUE;
		player2->cards[player2->num] = open;	// 플레이어 2에게 카드 할당
		showCard(&open, 72 + (2 * player2->num++), 21, OPEN);
		gotoxy(75, 20);
		calCardSum(player2);	// 플레이어 2의 카드 합 계산
		showSum(player2);		// 플레이어 2의 카드 합 출력
		Sleep(500);
	}

	int choice;

	showWhoTurn(player1->person);	// 플레이어 1의 차례를 출력
	while (!(player1->isLose == TRUE || player1->isStop == TRUE || player1->isBlackJack == TRUE)) {	// 플레이어 1이 졌거나, 멈추거나, 블랙잭이 아닌 경우
		choice = choiceAction(player1);	// 어떤 행동을 할 지 입력 받고
		if (choice == 1) {	// 선택이 1인 경우
			open = deck->cards[deck->count++];	// 카드 오픈
			remember_dealer(dealer, open);
			if (open.number == 'A')
				player1->hasA = TRUE;
			player1->cards[player1->num] = open;
			showCard(&open, 22 + (2 * player1->num++), 21, OPEN);
			gotoxy(25, 20);
			calCardSum(player1);	// 플레이어 1의 카드 합 계산
			showSum(player1);		// 플레이어 1의 카드 합 출력
		}
		else {	 // 다른 선택인 경우
			break;	// 멈춤
		}
	}

	showWhoTurn(player2->person);	// 플레이어 2의 차례를 출력
	while (!(player2->isLose == TRUE || player2->isStop == TRUE || player2->isBlackJack == TRUE)) {	// 플레이어 2가 졌거나, 멈추거나, 블랙잭이 아닌 경우
		choice = choiceAction(player2);	// 어떤 해동을 할 지 입력 받고
		if (choice == 1) {	// 1인 경우 플레이어 1과 동일한 행동을 진행
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
	showWhoTurn(dealer->gamer.person);	// 딜러의 순서를 출력
	Sleep(700);
	while (!(dealer->gamer.isLose == TRUE || dealer->gamer.isStop == TRUE || dealer->gamer.isBlackJack == TRUE)) {	// 딜러가 졌거나, 멈추거나, 블랙잭이 아닌 경우
		choice = expect_dealer(dealer);	// 딜러가 스스로 확률을 계산하여 행동을 선택
		if (choice == 1) {	// 1인 경우	카드를 open하고 카드 합 계산, 카드 합 출력
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
	compare(dealer, player1, player2);	// 마지막에 서로 카드 합을 비교하여 승자 결정
	gotoxy(43, 2);
	line_clear();
}