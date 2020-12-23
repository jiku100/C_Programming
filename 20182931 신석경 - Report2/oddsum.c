/*******************************************************
* 파일명: password.c
* 프로그램 개요: 암호를 입력받고, 암호의 안전도를 검사하는 프로그램
*	홀수의 합 : recur_sum 함수 정의
*	올바른 입력 검사: isInteger 함수 정의
* 
*	입력 : 검사할 정수
*
*   출력 : 홀수 합
*
* 날짜: 2020년 10월 4일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur_sum(int n);	// 홀수만 더하는 함수 정의
int isInteger(int check, int* n);	// 입력된 정수가 올바른 정수인지 판단하고 아니면 재입력 받는 함수

int main(void) {
	int n;	// 입력 받을 정수
	int check;	// 올바른 입력 판단 변수
	int odd_sum;	// 홀수 정수 합 변수
	while (1) {
		printf("1부터 n까지 홀수의 합을 구하는 재귀호출 프로그램입니다.\n");
		printf("정수 n을 입력하시오 >> ");
		check = scanf("%d", &n);
		if (isInteger(check, &n) == 0) {
			odd_sum = recur_sum(n);		// 홀수 합 계산
			printf("1부터 %d까지 홀수 합: %d\n\n", n, odd_sum);
		}
	}
}


int recur_sum(int n) {
	if (n == 1)		// n이 1이면 1반환
		return 1;
	else if (n % 2 == 0)	// n이 짝수 이면
		return recur_sum(n - 1);	// 홀수로 바꿔 함수 실행
	else
		return n + recur_sum(n - 2); // n이 홀수이면 2씩 빼면서 홀수만 함수 진행
}

int isInteger(int check, int* n) {
	do
	{
		if (check != 1)		// 입력이 정수가 아니면
			printf(" ?? 정수가 아닙니다. 다시 입력하시오 >> ");
		else if (*n < 0)	// 입력이 0보다 작으면
			printf(" ?? 0 보다 큰 정수를 입력하시오 >> ");
		else	// 입력이 정수에 0 보다 크면
			break;
		while (getchar() != '\n');	// 버퍼 비우기
		check = scanf("%d", n);	// 다시 입력 받기
	} while (1);
	return 0;
}