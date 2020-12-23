/*******************************************************
* 파일명: calculation.c
* 프로그램 개요: 표준 입력으로 받은 두 실수의 사칙 연산
*	사칙 연산: calculation 함수를 정의
*
*	입력 1: 임의의 두 실수
*   입력 2: 연산 종류 문자
*
*   출력: 연산 수식 및 연산 결과
*
* 날짜: 2020년 9월 14일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float calculation(float x, float y, char op);	// 사칙 연산을 하는 함수 정의

int main(void) {
	float x, y;	// 입력을 받을 두 실수;
	char op;	// 사칙 연산 종류를 선택하는 변수

	int n;	// 입력 성공 개수 저장 변수
	float result; // 계산 결과를 저장하는 변수

	while (1) {
		printf("두 실수를 입력(종료는 0 0 입력) >> ");
		n = scanf("%f %f", &x, &y);		// 두 실수를 입력 받음

		if (n == 2 && !(x == 0 && y == 0)) {	// 두 실수가 정상적으로 들어오고 x, y 모두 0이 아닌 경우
			printf("연산종류 번호선택 [+, -, *, /] >> ");
			scanf(" %c", &op);
			if (op == '+' || op == '-' || op == '*' || op == '/') {	// 입력이 사칙 연산인 경우에만
				result = calculation(x, y, op);		// 사칙연산 수행
				printf("%.2f %c %.2f = %.2f\n\n", x, op, y, result);
			}
			else {
				printf("연산자를 잘못 선택했습니다.\n\n");	 // 오류 출력
				while (getchar() != '\n');		// 입력 버퍼 비우기
			}
		}
		else if (n == 2 && (x == 0 && y == 0)) {	// x, y가 0 0 인 경우
			printf("**** 프로그램을 종료합니다. **** \n\n");
			break;		// while문 탈출
		}
		else {	// 두 실수가 잘못 입력된 경우
			while (getchar() != '\n');		// 입력 버퍼 비우기
			printf("두 실수를 다시 입력하시오(종료는 0 0 입력) : ");	// 다시 입력
			n = scanf("%f %f", &x, &y);		// 두 실수를 다시 입력 받음

			if (n == 2 && !(x == 0 && y == 0)) {	// 두 실수가 정상적으로 들어오고 x, y 모두 0이 아닌 경우
				printf("연산종류 번호선택 [+, -, *, /] >> ");
				scanf(" %c", &op);
				if (op == '+' || op == '-' || op == '*' || op == '/') {	// 입력이 사칙 연산인 경우에만
					result = calculation(x, y, op);
					printf("%.2f %c %.2f = %.2f\n\n", x, op, y, result);
				}
				else {
					printf("연산자를 잘못 선택했습니다.\n\n");	 // 오류 출력
					while (getchar() != '\n');		// 입력 버퍼 비우기
				}
			}
			else if (n == 2 && (x == 0 && y == 0)) {	// x, y가 0 0 인 경우
				printf("**** 프로그램을 종료합니다. **** \n\n");
				break;		// while문 탈출
			}
			else {	// 또 다시 잘못 입력된 경우
				printf("실수를 잘못 입력했습니다.\n\n");	// 오류 출력
				while (getchar() != '\n');		// 입력 버퍼 비우기
			}
		}
	}
	return 0;
}

float calculation(float x, float y, char op) {
	float result;
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
	return result;
}
