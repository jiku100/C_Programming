#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur_strlen(char* str, int index);

int main(void) {
	char str[64];
	while (1) {
		printf("Enter a string: ");
		fgets(str, 64, stdin);	// fgets로 한줄을 읽어옴
		printf("Total number of characters <string length> are %d\n\n", recur_strlen(str,0));	// 결과 출력
	}
	return 0;
}

int recur_strlen(char* str, int index) {
	if (str[index] && str[index] != '\n') {	// 입력된 str의 index 번 문자가 NULL이 아니고, 개행문자가 아니면
		return 1 + recur_strlen(str, index + 1);	// 그 다음 문자를 검사한 함수값 + 1 을 return
	}
	else {
		return 0;	// NULL 혹은 \n이면 0 리턴
	}
}