/*******************************************************
* 파일명: Round.c
* 프로그램 개요: 임의의 양의 정수와 자릿수 정수(n)을 입력 받아 n 자리수에서 반올림하는 프로그램
*	반올림: ROUND 매크로 정의
*
*	입력 1: 임의의 양의 정수
*   입력 2: 반올림을 할 자리수
*	입력 3: 프로그램 반복 실행 물음에 대한 대답
* 
*   출력: 반올림한 결과
*
* 날짜: 2020년 9월 14일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define ROUND(num, n) ((int)((num + 5 * pow(10, n - 1)) / pow(10, n)) * (int)(pow(10, n))) // 반올림하는 매크로 정의

int main(void) {
	int num;	// 양의 정수 입력 변수
	int digit;		// 자릿수 입력 정수

	int n;	// 입력 성공 개수 저장 변수
	char op;	// 반복 여부에 대한 변수

	int isloop;	// 반복 여부에 대한 입력 성공 개수 저장 변수
	while (1) {
		printf("임의의 양의 정수와 자릿수 정수를 입력하시오>> ");
		n = scanf("%d %d", &num, &digit);	// 임의의 양의 정수와 자릿수 정수를 입력 받음

		if (n == 2 && num > 0 && digit > 0 && (num - pow(10, digit)) > 0) {	// num이 양수이고 자릿수가 올바르게 들어온 경우	
			printf("%d 자리에서 반올림한 결과 >> %d\n", digit, ROUND(num, digit));	// 반올림한 결과 출력
			while (1) {
				printf("계속 하시겠습니까<y/n> ? ");
				isloop = scanf(" %c", &op);
				if (isloop == 1 && op == 'n') {		// 반복 여부에 대한 답이 n인 경우
					printf("\n--------------------------------");
					return 0;		// 프로그램 종료
				}
				else if (isloop == 1 && op == 'y') {	// 반복 여부에 대한 답이 y인 경우
					printf("\n");
					break; // 현재 while 문 탈출 및 다시 정수 입력 받으러 감
				}
				else {	// 다른 입력인 경우
					printf("?? y 또는 n을 입력하세요.\n");
					while (getchar() != '\n');		// 입력 버퍼 비우기
				}
			}
			
		}
		else {
			printf("?? 음수이거나 자릿수 지정 오류 입니다.\n");	// 오류 출력
			while (getchar() != '\n');		// 입력 버퍼 비우기
		}
	}
	return 0;
}