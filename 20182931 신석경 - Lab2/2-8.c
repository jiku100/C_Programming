#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* 표준입력으로 받은 두 실수로 입력된 연산을 수행하는 프로그램
*/

int main(void) {
	printf("표준입력으로 받은 두 실수로 입력된 연산을 수행하고 출력\n\n");

	float x, y; // 두 실수를 저장하기 위한 변수

	printf("두 실수 입력: ");
	scanf("%f %f", &x, &y);

	char op;	// 선택된 연산을 저장하기 위한 변수

	printf("연산종류 선택( +, -, *, / ) : ");
	scanf(" %c", &op);

	float result;   // 계산 결과를 저장하는 변수

	switch (op)		// 선택된 결과에 따라 실행
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		result = x / y;
		break;
	default:
		break;
	}

	printf("%.2f %c %.2f = %.2f\n", x, op, y, result);
	return 0;
}