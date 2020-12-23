/*
* 임의의 대문자, 소문자, 숫자, 그외 문자를 10개 입력 받아 배열에 저장하고,
* 각각이 몇 개인지 출력 하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mystrlen(char* str);
void checkToken(char* str);

int main(void) {
	char str[11];

	while (1) {
		printf("임의의 문자 10개를 연속으로 입력하시오 >> ");
		scanf("%s", str);
		checkToken(str);	// 토큰 개수 출력
	}
	return 0;
}


int mystrlen(char* str) {	// 문자열 길이 반환 함수
	int n;
	for (n = 0; str[n]; n++);	// str[n]이 '\n' 혹은 NULL이 나올 때 까지
	return n;
}

void checkToken(char* str) {
	int n = mystrlen(str);	// 문자열 길이 저장 변수

	int num[] = { 0,0,0,0 };	// 각각 숫자, 소문자, 대문자, 특수문자 개수를 나타냄.

	for (int i = 0; i < n; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')	num[0]++;	// 대문자 -> 0번 index 1 증가
		else if (str[i] >= 'a' && str[i] <= 'z')	num[1]++;	// 소문자 -> 1번 index 1 증가
		else if (str[i] >= '0' && str[i] <= '9') num[2]++;	// 숫자 -> 2번 index 1 증가
		else	num[3]++;	// 특수문자의 경우 3번 index 1 증가
	}

	printf("대문자 %d개, 소문자 %d개, 숫자 %d개, 그외 문자 %d개 입니다.\n\n", num[0], num[1], num[2], num[3]);
}