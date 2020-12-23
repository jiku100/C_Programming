#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* 두 정수를 입력 받아 합은 정수로 평균은 실수로 출력하는 프로그램
*/

int main(void) {
	printf("두 정수를 입력 받아 합과 평균을 출력\n\n");

	int input_1, input_2; // 두 정수를 입력 받을 변수 선언
	printf("첫 번째 정수를 입력하세요.: ");
	scanf("%d", &input_1);
	printf("두 번째 정수를 입력하세요.: ");
	scanf("%d", &input_2);

	printf("두 정수의 합: %d\n", input_1 + input_2);	// 두 정수의 합을 정수로 출력
	printf("두 정수의 평균: %f\n", (input_1 + input_2) / 2.); // 두 정수의 평균을 실수로 출력
	return 0;
}