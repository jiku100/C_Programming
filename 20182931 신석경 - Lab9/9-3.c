#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum GAME {		// enum 선언
	ROCK = 0,
	SCISSORS,
	PAPER
};

void doGame(enum GAME computer, int op);	// 결과를 확인하기 위한 함수

int main(void) {
	enum GAME computer;
	int op;
	printf("컴퓨터와 가위 바위 보 게임을 시작합니다.\n");
	srand((unsigned int)time(NULL));

	while (1) {
		computer = rand() % 3;	// 랜덤으로 생성
		printf("가위<0> 바위<1> 보<2> 종료<3> 중에서 하나 입력 >> ");
		scanf("%d", &op);
		if (op >= 0 && op < 3)	// 0, 1, 2이면 결과 출력
			doGame(computer, op);
		else if (op == 3) break;	// 3이면 종료
		else   // 다른 것이면 다시 입력
			printf("잘못 입력했습니다. 다시 입력하세요.\n\n");
	};
	printf("프로그램을 종료합니다.\n\n");
	return 0;
}

void doGame(enum GAME computer, int op) {
	switch (computer)
	{
	case ROCK:	// 컴퓨터가 주먹이면
		switch (op)		// 입력값에 따라 결과 출력
		{
		case ROCK:
			printf("비겼습니다. 다시하세요.\n\n");
			break;
		case SCISSORS:
			printf("컴퓨터의 승리입니다.\n\n");
			break;
		case PAPER:
			printf("당신의 승리입니다.\n\n");
			break;
		}
		break;
	case SCISSORS:
		switch (op)
		{
		case ROCK:
			printf("당신의 승리입니다.\n\n");
			break;
		case SCISSORS:
			printf("비겼습니다. 다시하세요.\n\n");
			break;
		case PAPER:
			printf("컴퓨터의 승리입니다.\n\n");
			break;
		}
		break;
	case PAPER:
		switch (op)
		{
		case ROCK:
			printf("컴퓨터의 승리입니다.\n\n");
			break;
		case SCISSORS:
			printf("당신의 승리입니다.\n\n");
			break;
		case PAPER:
			printf("비겼습니다. 다시하세요.\n\n");
			break;
		}
		break;
	}
}