/*
* 한 줄의 문자열을 표준입력으로 입력 받아 영문자의 대문자는 소문자로, 
* 소문자는 대문자로 변환하여 출력하는 프로그램
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[128];
	printf("영문 문장을 입력하시오\n");
	fgets(str, 128, stdin);
	printf("\n입력한 문자열에서 대문자와 소문자를 반대로 변환...\n");

	for (int i = 0; str[i]; i++) {
		if (islower(str[i]))	// 소문자이면
		{
			str[i] = toupper(str[i]);	// 대문자로 바꿈
		}
		else if (isupper(str[i]))	// 대문자이면
		{
			str[i] = tolower(str[i]);	// 소문자로 바꿈
		}
	}
	printf("%s\n", str);
	return 0;
}
