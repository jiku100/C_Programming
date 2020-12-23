/*
* 실수 r을 입력 받아 이 값을 반지름으로 하는 원의 면적과 둘레의 길이를 구하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PI 3.14

float area(float radius);	// 원의 면적
float circumference(float radius);	// 원의 둘레

int main(void) {
	float radius;	// 반지름 정수 정의
	int n;	// scanf 성공 여부 변수
	while (1) {
		printf("원의 반지름을 입력하면 원의 면적과 둘레의 길이를 구합니다.\n");
		printf("원의 반지름을 입력 하시오 : ");
		n = scanf("%f", &radius);
		if (n == 1 && radius > 0) {
			printf(" >> 원의 면적은 %.3f, 원의 둘레는 %.3f\n\n", area(radius), circumference(radius));
		}
		else {
			while (getchar() != '\n');		// 입력 버퍼 비우기
			printf("원의 반지름을 양수로 입력 하시오 : ");
			n = scanf("%f", &radius);
			if (n == 1 && radius > 0) {
				printf(" >> 원의 면적은 %.3f, 원의 둘레는 %.3f\n\n", area(radius), circumference(radius));
			}
			else {
				printf("입력을 잘못했습니다.\n\n");
				while (getchar() != '\n');		// 입력 버퍼 비우기
			}
		}
	}
}

float area(float radius) {
	return PI * radius * radius;
}

float circumference(float radius) {
	return 2 * PI * radius;
}