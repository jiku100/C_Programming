#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mymacro.h"
// mymacro.h에 #define PI 3.141592로 정의 되어있음.

/*
* 표준입력으로 원의 반지름 값인 실수를 입력 받아 반지름, 면적, 둘레 출력하는 프로그램
*/


int main(void) {
	printf("원의 반지름을 입력 받아 반지름, 면적, 둘레를 출력\n\n");

	float radius;
	printf("반지름을 입력하세요.: ");
	scanf("%f", &radius);		// 반지름을 입력 받아 radius 변수에 저장

	printf("원의 반지름: %f, 원의 면적: %f, 원의 둘레: %f", radius, PI*radius*radius, 2*PI*radius);
	// 각각의 계산 결과를 출력
	return 0;
}
