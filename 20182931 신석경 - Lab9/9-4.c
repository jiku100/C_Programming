#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printHigher(int count, int input, int down_boundary, int up_boundary); // target이 더 높을 경우 출력
void printLower(int count, int input, int down_boundary, int up_boundary);  // target이 더 낮을 경우 출력

int main(void) {
	srand((unsigned int)time(NULL));
	int target =  rand() % 100 + 1;	// 1 ~ 100 초기화
	
	int input;
	int count = 0;

	int up_boundary = 100;	// 처음 up_boundary = 100 
	int down_boundary = 1;	// 처음 down_boundary = 1

	printf("1부터 100까지의 하나의 정수가 결정되었습니다.\n");
	printf("이 정수를 맞춰 보시오? >> "); 
	scanf("%d", &input);	// 첫 입력
	putchar('\n');
	count++;	// 카운트 1

	for (count; count < 6; count++) { // 카운트가 1 부터 5까지 검사
		if (target < input) {	// target 보다 input이 크면
			up_boundary = input - 1;	// boundary 재설정
			printLower(count, input, down_boundary, up_boundary);	// 높다는 메세지 출력
		}
		else if (target > input) {	// 작으면
			down_boundary = input + 1;	// boundary 재설정
			printHigher(count, input, down_boundary, up_boundary);	// 작다는 메세지 출력
		}
		else {	// 같으면
			printf("축하합니다. 시도한지 %d번만에 정수 %d 를 맞혔습니다.\n\n", count, target);
			break;	// 출력 후 종료
		}
		if (count < 5) {	// 만약 카운트가 5보다 작으면
			scanf("%d", &input);	// 다시 입력을 받는다.
			putchar('\n');
		}
	}
	if (count == 6) {	// for문이 count == 6일 떄 끝난 것은 맞추지 못한 것
		printf("\n최대 시도 횟수인 5회 동안 맞추지 못하였습니다. 프로그램을 종료합니다.\n\n");
	}

	return 0;
}

void printHigher(int count, int input, int down_boundary, int up_boundary) {
	printf("맞추어야 할 정수가 입력한 정수 %d 보다 큽니다. <시도횟수: %d>\n", input, count);
	if(count<5)	// 카운트가 5 아래 일 때만 다시 입력 받기 위한 메세지 출력
		printf("%d에서 %d사이의 정수를 다시 입력하세요. > ", down_boundary, up_boundary);
}
void printLower(int count, int input, int down_boundary, int up_boundary) {
	printf("맞추어야 할 정수가 입력한 정수 %d 보다 작습니다. <시도횟수: %d>\n", input, count);
	if (count < 5)
		printf("%d에서 %d사이의 정수를 다시 입력하세요. > ", down_boundary, up_boundary);
}

