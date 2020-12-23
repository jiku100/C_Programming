/*******************************************************
* 파일명: pocker.c
* 프로그램 개요: 기본적인 카드게임을 할 수 있는 프로그램
*	구조체 1: card를 나타내는 Card 구조체
*   구조체 2: card의 52장 묶음을 나타내는 Deck 구조체
*   구조체 3: 사람을 나타내는 Gamer 구조체
*	덱 구성: filldeck() 정의
*	덱 섞기: shuffle() 정의
*	덱 분배: deal() 정의
*	승자 정하기: cardOpen() 정의
*
*	입력 1: 게임 참여자 3명의 이름
*   
*	출력: 각 참여자의 카드 구성 및 승자
*
* 날짜: 2020년 11월 04일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Card {		// 카드의 정보를 가지는 구조체
	int number;		// 카드의 숫자
	char* shape;	// 카드의 모양
	char* name;		// 카드의 모양 이름
};
typedef struct Card Card;

struct Deck {		// 덱의 정보를 가지는 구조체
	Card cards[52];	// 카드 52장
	int count;		// 현재 몇 장의 카드를 open 했는지 확인하는 변수
};
typedef struct Deck Deck;

struct Gamer {
	char name[16];	// 참가자 이름
	Card cards[7];	// 7개의 카드 저장
	int num;		// 카드 개수를 나타내는 변수
};
typedef struct Gamer Gamer;

enum SHAPE {	// 각 모양을 나타내는 enum
	SPADES = 0,
	HEARTS,
	DIAMONDS,
	CLUBS
};

void filldeck(Deck* deck);	// 덱 구성
void shuffle(Deck* deck);	// 덱 섞기
void deal(Gamer* gamers, Deck* deck);		// 카드 나눠주기
void cardOpen(Gamer* gamers);	// 게임 결과 확인하기

int main(void) {
	Deck deck = { 0 };			// 덱 구조체 선언
	Gamer gamers[3] = { 0 };	// Gamer 길이 3짜리 구조체 배열 선언
	char op;	// 게임을 계속 진행할 것인지 대답을 저장하는 변수

	printf("포커 게임의 참여자 3명을 차례로 입력하시오\n");
	printf("선수 1: "); scanf("%s", gamers[0].name);		// 선수 이름 입력 받기
	printf("선수 2: "); scanf("%s", gamers[1].name);
	printf("선수 3: "); scanf("%s", gamers[2].name);

	filldeck(&deck);	// 덱 구성 함수 실행
	do{
		printf("포커 게임을 시작합니다.\n\n");
		shuffle(&deck);
		deal(gamers, &deck);	// 덱 분배
		cardOpen(gamers);
		printf("계속 하시겠습니까?[y/n]: ");
		while (scanf(" %c", &op) != 1 || !(op == 'n' || op == 'y')) {	// 옳은 입력일 때까지 반복
			while (getchar() != '\n');
			printf("y 혹은 n을 입력해주세요.\n");
			printf("계속 하시겠습니까?[y/n]: ");
		}
		printf("\n");
	}while (op != 'n');
	return 0;
}

void filldeck(Deck* deck) {		// 덱 구성 함수
	for (int i = 0; i < 52; i++) {	// 52장의 카드를 생성
		switch (i / 13)	// 13으로 나눈 몫
		{
		case SPADES:	// 0이면
			(*deck).cards[i].number = i % 13 + 1;	// 카드의 숫자를 1 ~ 13로 설정 
			(*deck).cards[i].shape = "♠";			// 카드 모양을 Spades로 설정
			(*deck).cards[i].name = "<Spades>";		// 카드 이름을 <Spades>로 설정
			break;
		case HEARTS:	// 1이면
			(*deck).cards[i].number = i % 13 + 1;	// 카드의 숫자를 1 ~ 13로 설정
			(*deck).cards[i].shape = "♥";			// 카드 모양을 Hearts로 설정
			(*deck).cards[i].name = "<Hearts>";		// 카드 이름을 <Hearts>로 설정
			break;
		case DIAMONDS:	// 2이면
			(*deck).cards[i].number = i % 13 + 1;	// 카드의 숫자를 1 ~ 13로 설정
			(*deck).cards[i].shape = "◆";			// 카드 모양을 Diamonds로 설정
			(*deck).cards[i].name = "<Diamonds>";	// 카드 이름을 <Diamonds>로 설정
			break;
		case CLUBS:		// 3이면
			(*deck).cards[i].number = i % 13 + 1;	// 카드의 숫자를 1 ~ 13로 설정
			(*deck).cards[i].shape = "♣";			// 카드 모양을 Clubs로 설정
			(*deck).cards[i].name = "<Clubs>";		// 카드 이름을 <Clubs>로 설정
			break;
		default:
			break;
		}
	}
}

void shuffle(Deck* deck) {		// 덱 섞기 함수
	srand((unsigned long)time(NULL));
	Card temp;
	int rn;
	for (int i = 0; i < 51; i++) {	// 51번 돌며
		rn = rand() % (52 - i) + i;	// i 부터 51 사이에 임의의 정수 생성
		temp = (*deck).cards[i];	// 그 두 카드를 바꾼다.
		(*deck).cards[i] = (*deck).cards[rn];
		(*deck).cards[rn] = temp;
	}
	(*deck).count = 0;	// 덱 open 위치 초기화
}

void deal(Gamer* gamers, Deck* deck) {	// 덱 분배 함수
	for (int i = 0; i < 3; i++) {
		gamers[i].num = 0;	// 덱 분배 전 가지고 있는 카드 제거
	}
	printf("    %-15s%-15s%-15s\n\n", gamers[0].name, gamers[1].name, gamers[2].name);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			switch ((*deck).cards[(*deck).count].number)
			{	// 현재 덱의 제일 앞에 있는 카드의 종류 출력
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
			// 출력한 위치의 gamer의 카드에 open한 카드 추가
			// 이후 gamer의 카드 개수 +1, deck의 다음 카드로 이동 (count++)
		}
		printf("\n");
	}
	printf("\n\n");
}

void cardOpen(Gamer* gamers) {	// 게임의 결과를 출력하는 함수
	static char* ranks[10] = { "None", "One pair", "Two pair", "Triple" };	// 족보 이름 저장
	int winner;	// 승자 저장 변수
	int result[3] = { 0, };	// 각 사람마다의 족보를 저장하는 변수
	int count = 0;		// 같은 숫자의 개수를 저장하는 변수
	for (int i = 0; i < 3; i++) {	// 3명의 사람 검사
		for (int j = 0; j < 6; j++) {	// 0 ~ 6번 index 중 한 카드를 기준으로
			count = 0;
			for (int k = j + 1; k < 7; k++) {	// j번 index 이후에 카드를 j번 index 카드와 비교
				if (gamers[i].cards[j].number == gamers[i].cards[k].number)
					count++;
			}
			switch (count)
			{
			case 0:	// 하나도 안 겹치면 그대로
				break;
			case 1:	// 하나만 겹치면
				if (result[i] <= 1)	result[i] += 1;	
				// 현재 족보가 1이하 이면 1추가
				// 총 2가지 경우의 수가 있다.
				// 만약 현재 족보가 0 인 경우 1이 되어 원페어 의미
				// 만약 현재 족보가 1인 경우 2가 되어 투페어 의미
				break;
			case 2:	// 두개가 겹치면
				result[i] = 3;	// 트리플 의미
			default:
				break;
			}
		}
	}

	winner = 0;	// 0번 index 사람을 winner라 가정
	for (int i = 0; i < 3; i++) {
		printf("\t%s : rank = %s\n", gamers[i].name, ranks[result[i]]);
		if (result[i] > result[winner]) {	// i index 사람의 결과가 winner의 결과보다 크면
			winner = i;	// winner 바꿈
		}
	}
	printf("\n\tThe winner is %s by rank of %s.\n\n", gamers[winner].name, ranks[result[winner]]);	// winner의 이름과 winner의 result의 rank 출력
}