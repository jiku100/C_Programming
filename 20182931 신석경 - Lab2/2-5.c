#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
* 이차 방정식 ax^2 + bx + c = 0 의 근을 계산하는 프로그램
*/
int main(void) {
	printf("이차 방정식 ax^2 + bx + c = 0  의 해를 구하시오.\n\n");

	float a, b, c; // 각각의 계수를 저장하는 변수
	printf("계수 a를 입력하시오: "); scanf("%f", &a);
	printf("계수 b를 입력하시오: "); scanf("%f", &b);
	printf("계수 c를 입력하시오: "); scanf("%f", &c);

	float x1, x2;

	if (a == 0) {	// a 가 0 이면 근은 -c/b
		x1 = -c / b;
		printf("이차 방정식의 해 x = %.2f 입니다.\n", x1);
	}
	else if (b * b - 4 * a * c < 0) {		// b^2 - 4ac < 0 이먄 실근 존재 X
		printf("이차 방정식의 해는 존재하지 않습니다.\n");
	}
	else {		// 이차 방정식의 두 근이 존재하는 경우
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		printf("이차 방정식의 해 x = %.2f, x = %.2f 입니다. \n", x1, x2);
	}

	return 0;
}