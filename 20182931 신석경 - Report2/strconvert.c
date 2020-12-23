/*******************************************************
* 파일명: strconvet.c
* 프로그램 개요: 문자열로 받은 16진수를 10진수로 변경하여 출력하는 프로그램
*	16진수 검사 : isHex 함수 정의
*   16진수 10진수로 변경 : convertDex 함수 정의
*
*	입력 : 0x, 0X를 포함하거나 하지 않은 16진수 문자열
*
*   출력: 입력된 16진수 문자열을 10진수로 변경하여 출력
*
* 날짜: 2020년 10월 3일
* 버전: 1.0
* 작성자: 20182931 신석경
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isHex(char* str); // 16 진수 인지 검사하는 함수
int convertDex(char* str);	// 16 진수 문자열을 10 진수 숫자로 바꿔서 반환하는 함수

int main(void) {
	printf("16진수를 정수로 변환하는 프로그램입니다.\n");
	
	char str[32];

	while (1) {
		printf("16진수 문자열을 입력하시오 : ");
		scanf("%s", str);
		if (isHex(str) != 0) {		// 16진수가 아니면
			printf(" ?? 16진수가 아닙니다.\n"); while (getchar() != '\n');	// 오류 출력 및 버퍼 비우기
			continue;
		}
		else {	// 정상적인 16진수 이면
			printf(">> 10진수로 변환 결과 : %d\n\n", convertDex(str));	// 10진수로 바꿔서 출력
		}
	}
	return 0;	
}

int isHex(char* str) {
	int i = 0;
	if (str[0] == '0') {	// 첫문자가 0일 때
		if (str[1] == 'x' || str[1] == 'X') {	// 두번째 문자가 x, X이면
			i = 2;	// index 2부터 검사
		}
	}

	char temp;
	for (i; i < strlen(str); i++) {
		temp = str[i];	// 각 문자마다 검사
		if (!isxdigit(temp))
			return -1;	// 입력된 문자가 16진수가 아니면 return -1
		// isxdigit()은 입력된 문자가 16진수에 해당하는 문자인지 확인, 비정상인 경우 isxdigit(temp) == 0	
	}

	return 0; // 정상일 경우 return 0;
}

int convertDex(char* str) {
	// strtol은 입력된 문자열을 세번째 argument의 입력된 숫자에 해당하는 진법을 통해 long type으로 바꿔준다.
	// 두번째 argument는 여러 문자열이 존재할 경우, 변환이 완료된 끝 문자열의 주소를 기억하기 위한 pointer가 들어간다.
	return strtol(str, NULL, 16);	
}