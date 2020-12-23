/*
* 정수 형태의 문자열을 정수로 반환하는 함수를 구현하고 결과를 알아보는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int myatoi(const char* str);	// myatoi

int main(void) {
	char str[16];
	printf("정수 하나를 입력하시오 >> ");
	scanf("%s", str);
	printf("함수 atoi<>를 이용한 정수 -> %d\n", atoi(str));	// atoi 결과
	printf("함수 myatoi<>를 이용한 정수 -> %d\n", myatoi(str));	// myatoi 결과
	return 0;
}

int myatoi(const char* str) {
	int n = strlen(str);	// 문자열 길이 구함
	int sum = 0;
	for (int i = 0; str[i]; i++) {
		if (isdigit(str[i])) {	// 문자가 숫자이면
			// str[i] - 48 -> 숫자
			// pow(10, (n-i-1)) -> 자릿수 계산
			// n = 4, i = 0 -> 4자릿수 식의 첫번째, 1000의 자릿수
			sum += (str[i] - 48) * pow(10, (n-i-1));	// 숫자로 바꾸고 10의 제곱수를 곱해 알맞은 자릿수로 바꿈
		}
	}
	return sum;
}