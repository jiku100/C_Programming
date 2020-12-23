#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* 표준입력으로 두 정수를 입력 받아 큰 수를 작은 수로 나눈 몫과 나머지를 
* 각각 출력하는 프로그램
*/

int main(void) {
	printf("두 정수를 입력 받아 큰 수를 작은 수로 나눈 몫과 나머지 출력\n\n");
	int x, y;  // 입력 받을 두 변수

	printf("첫 번째 숫자를 입력하세요: ");
	scanf("%d", &x);
	printf("두 번째 숫자를 입력하세요: ");
	scanf("%d", &y);		// 두 정수 입력

	if (x > y) {	// x > y 이면 x/y의 결과
		printf("\n%d 를 %d 로 나눈 결과\n", x, y);
		printf("몫: %d, 나머지: %d\n", x / y, x % y);
	}
	else {		// 나머지 경우 ( x <= y)
		printf("\n%d 를 %d 로 나눈 결과\n", y, x);
		printf("몫: %d, 나머지: %d\n", y / x, y % x);
	}

	return 0;
}