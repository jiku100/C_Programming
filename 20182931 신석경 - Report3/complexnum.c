/*******************************************************
* 파일명: complexnum.c
* 프로그램 개요: 복소수의 더하기, 빼기, 곱하기 및 절댓값을 구하는 프로그램
*	복소수 더하기: complex_sum() 정의
*	복소수 빼기: complex_sub() 정의
*	복소수 곱하기: complex_mul() 정의
*	복소수 절댓값: complex_abs() 정의
*	복소수 출력: complex_print() 정의
*
*	입력 1: 복소수를 나타내는 두 개의 실수 입력
*	입력 2: 복소수를 나타내는 두 개의 실수 입력
* 
*	출력: 더하기, 빼기, 곱하기, 절댓값의 결과 출력
*
* 날짜: 2020년 11월 04일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct mycomplex {	// 복소수 구조체
	float real;		// 실수 부분
	float imagine;	// 허수 부분
};
typedef struct mycomplex mycomplex;

void complex_sum(mycomplex c1, mycomplex c2, mycomplex* dst);	// 복소수 더하기
void complex_sub(mycomplex c1, mycomplex c2, mycomplex* dst);	// 복소수 빼기
void complex_mul(mycomplex c1, mycomplex c2, mycomplex* dst);	// 복소수 곱하기
float complex_abs(mycomplex c);	// 복소수 절댓값
void complex_print(mycomplex c);	// 복소수 출력

int main(void) {
	mycomplex c1, c2, result;	// 복소수 구조체 3개 선언
	printf("복소수 연산을 수행합니다.\n");
	printf("첫 번째 복소수를 두 개의 실수로 입력하시오. >> ");
	scanf("%f %f", &c1.real, &c1.imagine);	// c1 복소수 입력
	printf("두 번째 복소수를 두 개의 실수로 입력하시오. >> ");
	scanf("%f %f", &c2.real, &c2.imagine);	// c2 복소수 입력

	printf("\n덧셈\n");
	complex_sum(c1, c2, &result);	// 덧셈 계산 
	complex_print(c1); printf(" + "); complex_print(c2); printf(" = "); complex_print(result); printf("\n");	// 출력

	printf("\n뺄셈\n");
	complex_sub(c1, c2, &result);	// 뺄셈 계산 
	complex_print(c1); printf(" - "); complex_print(c2); printf(" = "); complex_print(result); printf("\n");	// 출력
	
	printf("\n곱셈\n");
	complex_mul(c1, c2, &result);	// 곱셈 계산 
	complex_print(c1); printf(" * "); complex_print(c2); printf(" = "); complex_print(result); printf("\n");	// 출력
	
	printf("\n절댓값\n"); 
	printf("|"); complex_print(c1); printf("|"); printf(" = ");  printf("%.3f\n", complex_abs(c1));	// 출력
	printf("|"); complex_print(c2); printf("|"); printf(" = ");  printf("%.3f\n", complex_abs(c2));	// 출력
	return 0;
}


void complex_sum(mycomplex c1, mycomplex c2, mycomplex* dst) {	// 복소수 더하기
	(*dst).real = c1.real + c2.real;	// 실수항끼리 더하여 결과를 저장
	(*dst).imagine = c1.imagine + c2.imagine;	// 허수항끼리 더함
}

void complex_sub(mycomplex c1, mycomplex c2, mycomplex* dst) {	// 복소수 빼기
	(*dst).real = c1.real - c2.real;	// 실수항끼리 빼 결과를 저장
	(*dst).imagine = c1.imagine - c2.imagine;	// 허수항끼리 뺌
}

void complex_mul(mycomplex c1, mycomplex c2, mycomplex* dst) {	// 복소수 곱하기
	(*dst).real = (c1.real*c2.real) - (c1.imagine * c2.imagine); // 실수항끼리 곱한 값에 허수항끼리 곱한 값을 뺌
	(*dst).imagine = (c1.real*c2.imagine) + (c1.imagine*c2.real);	// 실수항 * 허수항 값을 더함
}

float complex_abs(mycomplex c) {	// 복소수 절댓값
	return sqrt(c.real * c.real + c.imagine * c.imagine);	// 절댓값 계산
}

void complex_print(mycomplex c) {	// 복소수 출력
	printf("< %.2f ", c.real);
	if (c.imagine < 0) {
		printf("- %.2fi >", fabs(c.imagine));	
		// c.imagine이 음수이면 - 절댓값(허수) 로 출력함
		// 이는 단순히 보기 편하게 출력하기 위함, 없어도 상관 없음.
	}
	else {
		printf("+ %.2fi >", c.imagine);
	}
}