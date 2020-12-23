/*
* BlackJack.c
* 
* 개요: 전체 블랙잭 프로그램이 실행되는 코드
* 
* include: source.h, cursor.h, control.h, console.h를 사용함
* 
* 입력: 입력은 각 모듈에서 따로 처리함
* 
* 출력: 블랙잭 게임이 진행되고 있는 흐름
* 
* 최종 코드 수정 날짜: 2020.11.21
* 버전: 1.0
* 작성자: 신석경
* 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "source.h"
#include "cursor.h"
#include "control.h"
#include "console.h"
#include <string.h>
#include <stdlib.h>

int main(void) {
	Deck deck = { 0 };			// 덱 구조체 선언
	Dealer dealer = { {{"Dealer", 100}, 0,0},0 };	// 딜러 선언
	Gamer* player1 = (Gamer*)calloc(1, sizeof(Gamer));	// 플레이어1 동적 할당
	Gamer* player2 = (Gamer*)calloc(1, sizeof(Gamer));	// 플레이어2 동적 할당

	int option;	// 선택 옵션들 저장 변수

	filldeck(&deck);	// 덱 구성 함수 실행

	while (1) {
		console_clear();	// 콘솔 클리어
		gameStart();	// 첫 화면 출력
		option = gameStartOption();	// 시작 옵션 받고
		if (option == 0)	// 0이면 종료
			break;
		else {	// 아니면
			console_clear();	// 콘솔 클리어
			input_player(player1);	// 플레이어 1 정보 받고
			input_player(player2);	// 플레이어 2 정보 받고
			console_clear();	// 콘솔 클리어
			printf("게임을 시작합니다!!");
			Sleep(1000);
			console_clear();
			showDeck(&deck, OPEN);	// 카드 전체를 보여주고
			Sleep(1000);
			console_clear();
			showDeck(&deck, CLOSE);	// 카드 뒷면으로 전체를 보여주고
			Sleep(800);
			while (1) {
				console_clear();
				shuffle(&deck);	// 카드를 섞음
				console_clear();
				gameSet(&dealer, player1, player2);	// 게임 화면 세팅
				showMoney(player1, player2);	// 각 플레이어의 돈 보여줌
				playerSet(player1, player2);	// 각 플레이어이 베팅을 하고 베팅 금액을 보여줌
				gotoxy(0, 0);
				line_clear();
				mainControl(&deck, &dealer, player1, player2);	// 전체 게임 흐름 출력
				
				option = gameContinueOption();	// 게임을 더 할 것인지 입력 받는 함수
				if (option == 0) {
					gotoxy(0, 0);
					printf("게임을 그만합니다.");
					Sleep(1000);
					gotoxy(0, 0);
					line_clear();
					break;
				}
				else {
					gotoxy(0, 0);
					printf("게임을 계속합니다.");
					Sleep(1000);
					gotoxy(0, 0);
					line_clear();
					setInit(&dealer, player1, player2);	// 게임을 계속하면 데이터 초기화 이후 다시 게임 시작
				}
			}
			clearData(&dealer, player1, player2);	// 만약 게임을 맨 처음부터 하고 싶으면 각 변수의 메모리 초기화 이후 다시 시작
		}
	}
	gotoxy(0, 0);
	console_clear();
	printf("게임을 종료합니다!!\n\n");
	return 0;
}