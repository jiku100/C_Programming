/*
* 표준입력으로 입력 받은 문자열의 길이를 구하는 함수 mystrlen()을 구현하여 
* 라이브러리 strlen()과 결과를 비교하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int mystrlen(const char* str);	// 문자열 길이를 구하는 함수

int main(void) {
	printf("Enter any string >> ");
	char str[64];	// 입력 버퍼
	gets(str, 64);
	printf("strlen<> : %d\n", strlen(str));
	printf("mystrlen<> : %d\n", mystrlen(str));
	return 0;
}

int mystrlen(char* str) {
	int n;
	for (n = 0; str[n]; n++);	// str[n]이 '\n' 혹은 NULL이 나올 때 까지	n값을 증가시킴
	return n;
}