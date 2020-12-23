/*
* 입력 받은 두 개의 양의 정수의 합을 계산하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	printf("두 개의 양의 정수를 입력 받아 합을 출력\n\n");

	int x, y;	// 입력 받을 두 변수 정의
	int n;	//입력의 성공 개수를 저장하는 변수

	while (1) {
		printf("두 개의 양의 정수를 입력하시오 >> ");
		n = scanf("%d %d", &x, &y);	// 두 개의 정수를 입력

		if (n == 2 && x > 0 && y > 0)	// 입력 2개가 성공적으로 양수 일 경우
		{
			printf("두 정수의 합은 %d 입니다.\n", x + y);
			break;
		}
		else {
			printf(">> 양의 정수가 아닙니다. 다시 입력하시오\n");  // 오류 출력
			while (getchar() != '\n');		// 입력 버퍼 비우기
		}
	}

	return 0;
}
