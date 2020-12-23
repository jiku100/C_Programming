/*
* 0에서 9까지의 정수 중에서 10개의 수를 입력 받아 
* 가장 많이 입력 받은 빈도 수는 무엇이고, 몇 번인지 출력하는 프로그램을 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	printf("0 ~ 9까지의 수를 10번 입력 받아 최빈값과 횟수를 출력\n\n");

	int count[10] = { 0, };	// 모든 횟수를 0으로 초기화
	
	int input, n;	// scanf를 통해 들어올 정수를 저장, 올바른 입력인지 확인하는 변수

	int i = 0;	// 입력의 횟수를 저장하는 변수

	int isRight = TRUE;	// 올바른 입력인지 상태를 저장하는 변수

	printf("0에서 9까지의 정수를 입력하시오.\n");

	while (i < 10) {	// 총 10번 입력 받음
		if (isRight == FALSE) {	// 전의 입력이 올바르지 않은 경우
			while (getchar() != '\n');
			printf("다시입력<0 ~ 9> : ");
		}
		n = scanf("%d", &input);
		if (n == 1 && input >= 0 && input <= 9) {	// 입력이 0 ~ 9일 경우
			isRight = TRUE;	// 올바른 입력 상태 저장
			count[input]++;	// 해당 index 1 증가
			i++; // 횟수 1 증가
		}
		else {		// 올바른 입력이 아닌 경우
			isRight = FALSE;	// 잘못된 입력 상태 저장
		}
	}

	int max_index = 0;	// 최빈값 index 저장하는 변수

	for (int j = 0; j < sizeof(count) / sizeof(count[0]); j++) {
		if (count[j] > count[max_index])
			// j index의 count 수가 max_index의 count 수보다 클 경우
			max_index = j;	// max_index 를 j로 바꿈
	}

	// 최빈값과 횟수 출력
	printf("\n0 ~ 9 중 가장 많이 나온 수는 %d이고, %d번 나왔습니다.\n\n", max_index, count[max_index]);
	
	return 0;
}