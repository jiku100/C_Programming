/*
* source.c
*
* 개요: 블랙잭 게임 내 리소스에 대한 처리 및 내부 계산 담당 모듈
*
* include: source.h, cursor.h를 사용함
*
* 입력: 각 함수에서 필요로 하는 입력들
*
* 출력: 보통 옵션을 입력 받기 위한 질문 출력
*
* 최종 코드 수정 날짜: 2020.11.21
* 버전: 1.0
* 작성자: 신석경
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include "source.h"
#include "cursor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void setInit(Dealer* dealer, Gamer* player1, Gamer* player2) {	// 각 딜러와 플레이러를 초기화하는 함수
	memset(&dealer->gamer.cards, 0, sizeof(dealer->gamer.cards)); // 딜러의 카드를 메모리 초기화
	memset(&dealer->remember, 0, sizeof(dealer->remember));	// 딜러가 카드 기억하는 거 초기화
	dealer->gamer.num = 0;	// 카드 개수 0으로
	dealer->gamer.sum[0] = 0;	// 카드 합 0
	dealer->gamer.sum[1] = 0;	// 카드 합 0
	dealer->gamer.hasA = FALSE;	// A 보유 변수 FALSE
	dealer->gamer.isLose = FALSE;	// Lose 변수 FALSE
	dealer->gamer.isBlackJack = FALSE;	// 블랙잭 확인 변수 FASLE
	dealer->gamer.isStop = FALSE;	// 멈추는 확인 변수 FASLE

	// 나머지는 위와 동일
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
void clearData(Dealer* dealer, Gamer* player1, Gamer* player2) {	// 모든 딜러와 플레이어의 데이터를 초기화하는 함수
	memset(dealer, 0, sizeof(Dealer));	// 딜러 메모리 초기화
	strcpy(dealer->gamer.person.name, "Dealer");	// 딜러 이름 설정
	memset(player1, 0, sizeof(Gamer));	// 플레이어 1 메모리 클리어
	memset(player2, 0, sizeof(Gamer));	// 플레이어 2 메모리 클리어
}
char int_to_cardNumber(int number) {	// 입력된 숫자를 가지고 카드 넘버로 바꾸는 함수
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

char cardNumber_to_int(char number) {	// 입력된 카드 넘버를 블랙잭 숫자로 바꾸는 함수
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

void filldeck(Deck* deck) {	// 덱 구성
	for (int i = 0; i < 52; i++) {	// 52장의 카드를 생성
		switch (i / 13)	// 13으로 나눈 몫
		{
		case SPADES:	// 0이면
			(*deck).cards[i].number = int_to_cardNumber(i % 13 + 1);	// 카드의 숫자를 A ~ K로 설정 
			(*deck).cards[i].shape = "♠";			// 카드 모양을 Spades로 설정
			(*deck).cards[i].name = "<Spades>";		// 카드 이름을 <Spades>로 설정
			break;
		case HEARTS:	// 1이면
			(*deck).cards[i].number = int_to_cardNumber(i % 13 + 1);	// 카드의 숫자를 A ~ K로 설정
			(*deck).cards[i].shape = "♥";			// 카드 모양을 Hearts로 설정
			(*deck).cards[i].name = "<Hearts>";		// 카드 이름을 <Hearts>로 설정
			break;
		case DIAMONDS:	// 2이면
			(*deck).cards[i].number = int_to_cardNumber(i % 13 + 1);	// 카드의 숫자를 A ~ K로 설정
			(*deck).cards[i].shape = "◆";			// 카드 모양을 Diamonds로 설정
			(*deck).cards[i].name = "<Diamonds>";	// 카드 이름을 <Diamonds>로 설정
			break;
		case CLUBS:		// 3이면
			(*deck).cards[i].number = int_to_cardNumber(i % 13 + 1);	// 카드의 숫자를 A ~ K로 설정
			(*deck).cards[i].shape = "♣";			// 카드 모양을 Clubs로 설정
			(*deck).cards[i].name = "<Clubs>";		// 카드 이름을 <Clubs>로 설정
			break;
		default:
			break;
		}
	}
}

void betting(Gamer* player) {	// 배팅금액 입력 받기
	float bet_money;
	int isright;
	do
	{
		gotoxy(0, 0);
		line_clear();
		gotoxy(0, 0);	// 0,0 라인 클리어
		printf("%s의 배팅 금액을 입력하세요: ", player->person.name);
		isright = scanf("%f", &bet_money);	// 베팅 금액 입력 받고
		while (getchar() != '\n');
		if (isright != 1 || player->person.money < bet_money) {	// 보유 금액보다 큰 경우
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 1);
			printf("알맞은 금액을 입력하세요.");
		}
		if (isright == 1 && player->person.money >= bet_money) {	// 올바른 입력인 경우
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 1);
			player->person.money -= bet_money;	// 보유 금액에서 베팅 금액 빼고
			player->bet_money = bet_money;	// 배팅 금액 설정
			return;
		}
	} while (TRUE);	// 올바른 입력이 될 때까지 반복
}

void calCardSum(Gamer* gamer) {	// 카드 합 계산
	gamer->sum[0] = 0;
	gamer->sum[1] = 0;
	for (int i = 0; i < gamer->num; i++) {	// 카드 개수 전까지
		if (gamer->hasA == TRUE) {	// A를 가졌으면
			if (gamer->cards[i].number == 'A')	// 카드가 A인 경우
				gamer->sum[1] += cardNumber_to_int(gamer->cards[i].number) + 10;	// 1번 index에 11을 더함
			else
				gamer->sum[1] += cardNumber_to_int(gamer->cards[i].number);	// 아닌 경우 그대로 1번 index에 더함
		}
		gamer->sum[0] += cardNumber_to_int(gamer->cards[i].number);	// 0번 index에는 숫자 그대로를 추가
	}
	if (gamer->sum[0] == 21 || gamer->sum[1] == 21) {	// 만약 0번 혹은 1번이 21이면
		gamer->isBlackJack = TRUE;	// 블랙잭 만들고
		gamer->isStop = TRUE;	// 멈춤
	}
	if (gamer->sum[0] > 21)	// 0번이 21을 넘으면
		gamer->isLose = TRUE;	// 짐
}

void input_player(Gamer* gamer) {	// 플레이어를 입력 받는 함수
	static int order = 0;	// 정적 변수 선언
	float money;
	char* name = malloc(sizeof(char) * 16);	// 이름 입력 받을 변수 초기화
	int isright;
	do
	{
		gotoxy(0, 0);
		line_clear();
		gotoxy(0, 0);
		printf("player%d의 이름을 입력하세요: ", order + 1);
		isright = scanf("%s", name);	// 이름 입력 받고
		if (isright != 1) {	// 올바른 입력이 아닌 경우 오류 출력
			gotoxy(0, 0);
			line_clear();
			gotoxy(0, 1);
			printf("올바른 이름을 입력하세요!");
			while (getchar() != '\n');
		}
		if (isright == 1) {
			strcpy(gamer->person.name, name);	// 올바른 입력이면 gamer 변수의 사람 이름에 name을 복사
			break;
		}
	} while (TRUE);

	do
	{
		gotoxy(0, 1);
		line_clear();
		gotoxy(0, 1);
		printf("player%d의 돈을 입력하세요: ", order + 1);
		isright = scanf("%f", &money);	// 돈 입력
		if (isright != 1 || money < 0) {	// 잘못된 입력에 대한 오류 출력
			gotoxy(0, 1);
			line_clear();
			gotoxy(0, 2);
			printf("양의 실수를 입력하세요!");
			while (getchar() != '\n');
		}
		if (isright == 1 &&  money > 0) {	// 올바른 입력인 경우 
			gamer->person.money = money;	// 보유 금액에 추가
			break;
		}
	} while (TRUE);
	order = (order + 1) % 2;	// order는 1과 2를 반복
	console_clear();	// 콘솔 클리어
}

int choiceAction(Gamer* player) {	// 플레이어가 무슨 행동을 할 지 결정하는 함수
	char choice;
	int isright;

	do
	{
		gotoxy(36, 3);
		line_clear();
		gotoxy(36, 3);
		printf("카드를 오픈하시겠습니까? <y or n>: ");
		isright = scanf("%c", &choice);	// 입력 받고
		while (getchar() != '\n');
		if (isright != 1 || !(choice == 'y' || choice == 'n')) {	// y와 n이 아닌 경우 다시 입력 받음
			gotoxy(34, 3);
			line_clear();
			gotoxy(0, 0);
			printf("y 나 n을 입력하세요.");
		}
		if (isright == 1 && choice == 'y') {	// y이면 1 리턴
			gotoxy(0, 0);
			line_clear();
			gotoxy(36, 3);
			line_clear();
			return 1;
		}
		else if (isright == 1 && choice == 'n') {	// n이면 0 리턴
			player->isStop = TRUE;
			gotoxy(0, 0);
			line_clear();
			gotoxy(36, 3);
			line_clear();
			return 0;
		}
	} while (TRUE);
}
	
void remember_dealer(Dealer* dealer, Card card) {	// 딜러가 카드를 기억하는 함수
	// 들어온 card의 넘버에 따라 딜러의 remember 배열의 값 증가
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

int expect_dealer(Dealer* dealer) {	// 딜러가 확률을 계산하여 행동을 선택하는 함수
	float sum = 0;		// 앞으로 나올 수 있는 카드 넘버의 모든 합
	int factor = 0;		// 카드 합을 계산할 때 곱할 계수
	int open_num = 0;	// 현재까지 open된 카드 개수를 저장하는 변수
	int diff;
	float expect_value = 0;
	if (dealer->gamer.sum[0] < 17 && dealer->gamer.sum[1] < 17) {	// 딜러가 17이하면 무조건 open 해야 함
		return 1;
	}
	else {	// 17 보다 큰 경우
		for (int i = 0; i < 13; i++) {	 // A ~ K 까지의 카드
			factor = i + 1;	// 각 index보다 1 큰 값이 실제 카드 값임
			if (factor > 10)	// J Q K는 다 10으로 설정
				factor = 10;
			open_num += dealer->remember[i];	// 현재 remember[i]에 있는 값은 i + 1 짜리 카드가 open된 개수, 
			sum += (4 - dealer->remember[i]) * factor;	// 4 - (i + 1) 카드가 오픈 된 개수에 factor를 곱하여 sum에 더함
		}
		expect_value = sum / (52 - open_num);	// 앞으로 나올 카드 합인 sum을 앞으로 남은 카드 개수로 나누어 예상 값을 구함
		
		if (dealer->gamer.hasA == TRUE && dealer->gamer.sum[1] <= 21) {	// 딜러가 A를 가지고 딜러의 sum[1]이 21보다 작거나 같은 경우
			diff = 21 - dealer->gamer.sum[1];	// 21과 sum[1] 사이의 차이를 diff로 저장
		}
		else {	// 아닌 경우, 즉 sum[1] > 21인 경우
			diff = 21 - dealer->gamer.sum[0];	// 21과 dealer sum[0]과의 차이를 diff로 저장
		}
		gotoxy(0, 0);
		if (expect_value <= diff) {	// 만약 예상 값이 diff보다 작으면 1 반환
			return 1;
		}
		else {	// 아니면 멈추고 0 반환
			dealer->gamer.isStop = TRUE;
			return 0;
		}
	}
}

int result_sum(Gamer* gamer) {	// 최종 카드 합 결과를 반환하는 함수
	if (gamer->isLose == TRUE) {	// 졌으면
		return 0;	// 0 반환
	}
	if (gamer->isBlackJack == TRUE) {	// 블랙잭이면
		return 21;	// 21 반환
	}
	if (gamer->hasA == FALSE){	// A를 가지지 않으면 sum[0] 반환, 이때 이미 21을 넘은 경우는 위에서 걸렀기 때문에 상관 없다
		return gamer->sum[0];
	}
	else if (gamer->hasA == TRUE) {	// A를 가졌다면
		if (gamer->sum[1] < 21) {	// sum[1]이 21보다 작으면
			return gamer->sum[1];	// sum[1]이 결과
		}
		else {	// 아니면 즉 21을 넘으면
			return gamer->sum[0];	// sum[0]이 결과
		}
	}
}