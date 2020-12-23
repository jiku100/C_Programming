/*******************************************************
* 파일명: calculator.c
* 프로그램 개요: 연속된 연산식에서 각 연산이 몇 번 나오는지 출력하는 프로그램
*	토큰분리: getToken 함수 정의
*
*	입력 : 연산식
*
*   출력: (+, -, *, %, /) 연산 개수 합계
*
* 날짜: 2020년 10월 1일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int getToken(char* str, int* plus, int* minus, int* times, int* division, int* percentage);	// 토큰 분리 함수


int main(void) {
	printf("연산(+,-,*,/,%)의 개수를 카운트하는 프로그램입니다.\n");

	int plus = 0, minus = 0, times = 0, division = 0, percentage = 0;
	char str[64];

	while (1) {
		printf("연산식을 입력하시오 : ");
		if (fgets(str, 64, stdin) == NULL) {
			return 0;
		}

		if (getToken(str, &plus, &minus, &times, &division, &percentage) != 0) {	// 토큰 분리 결과가 비정상이면
			printf(" ?? 연산식 오류\n"); //while (getchar() != '\n');	// 오류 출력 및 버퍼 비우기
			continue;
		}
		else {		// 각 연산자 개수가 0 이상이면 출력
			if (plus > 0)
				printf(" + 연산 합계 : %d\n", plus);
			if (minus > 0)
				printf(" - 연산 합계 : %d\n", minus);
			if (times > 0)
 				printf(" * 연산 합계 : %d\n", times);
			if (division > 0)
				printf(" / 연산 합계 : %d\n", division);
			if (percentage > 0)
				printf(" %% 연산 합계 : %d\n", percentage);
			printf("\n");

		}
	}

	return 0;
}

int getToken(char* str, int* plus, int* minus, int* times, int* division, int* percentage) {

	int plus_temp = 0, minus_temp = 0, times_temp = 0, division_temp = 0, percentage_temp = 0;
	int i = 0;
	while (str[i] != '\n' && str[i] != NULL) {
		if (str[i] >= '0' && str[i] <= '9');	// 0 ~ 9 사이 문자면 pass 
		else if (str[i] == ' ' || str[i] == '/t');	// 공백, 탭문자이면 pass
		else if (str[i] == '+')	// + 이면 plus_temp 값 1 증가
			plus_temp += 1;
		else if (str[i] == '-')	// - 이면 minus_temp 값 1 증가
			minus_temp += 1;
		else if (str[i] == '*')	// * 이면 times_temp 값 1 증가
			times_temp += 1;
		else if (str[i] == '/') // / 이면 division_temp 값 1 증가
			division_temp += 1;
		else if (str[i] == '%') // % 이면 percentage_temp 값 1증가
			percentage_temp += 1;
		else
			return -1;	// 아무것도 아니면 -1 반환

		i++;  // 정상적이면 다음 문자 검사
	}
	*plus += plus_temp;		// 정상적인 연산식인 경우, plus 값 증가
	*minus += minus_temp;	// 정상적인 연산식인 경우, minus 값 증가
	*times += times_temp;	// 정상적인 연산식인 경우, times 값 증가
	*division += division_temp;	// 정상적인 연산식인 경우, division 값 증가
	*percentage += percentage_temp;	// 정상적인 연산식인 경우, percentage 값 증가

	return 0;	// 정상 종료의 경우 0 반환
}