#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
* 정수인 천만 이하의 한 수를 입력 받아 
* 우리가 사용하는 단위인 만, 천, 백, 십, 일 단위로 출력하는 프로그램
*/

int main(void) {
	printf("정수인 천만 이하의 한 수를 입력 받아 우리가 사용하는 단위인 만, 천, 백, 십, 일 단위로 출력\n\n");

	int target; // 입력 받은 변수
	printf("천만 이하의 정수를 입력하세요: ");
	scanf("%d", &target);

	int ten = 10;
	char* unit[5] = { " ", "십 ", "백 ", "천 ", "만 " };

	int divisor; // 나누는 수

	printf("입력: %d\n", target);
	for (int i = 4; i >= 0; i--) {
		divisor = pow(10, i);
		if (target / divisor != 0) {	// 단위에 해당하는 숫자가 있으면
			printf("%d %s", target / divisor, unit[i]);	// 출력
			target -= (target / divisor) * divisor;		// 출력 이후 출력 부분 빼기
		}
	}

	printf("입니다.\n");
	return 0;	
}