/*
* 함수의 기능을 이해하기 위하여 각각 함수의 사용하는 예제를 프로그램
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[] = "C Code & C++ code";
	char str1[20];
	char str2[] = "&+";
	char str3[] = "code";
	char ch = 'd';

	printf("예제에 사용된 문자열\n");
	printf("str1 = %s\n", str);
	printf("str2 = %s\n", str2);
	printf("str3 = %s\n", str3);
	printf("ch = %c\n\n\n", ch);

	strcpy(str1, str);	// 매 string 연산 전마다 str1을 초기화
	// 'strlwr': The POSIX name for this item is deprecated.
	// Instead, use the ISO C and C++ conformant name: _strlwer.
	// 위의 Error 메세지로 인해 strlwr을 _strlwr로 대신해서 사용
	printf("strlwer<str1>\n   반환된 문자열 : %s\n\n\n", _strlwr(str1));

	strcpy(str1, str);	// 매 string 연산 전마다 str1을 초기화
	printf("strpbrk<str1, str2>\n    반환된 문자열 : %s\n\n\n", strpbrk(str1, str2));

	strcpy(str1, str);	// 매 string 연산 전마다 str1을 초기화
	printf("strstr<str1, str3>\n    반환된 문자열 : %s\n\n\n", strstr(str1, str3));

	strcpy(str1, str);	// 매 string 연산 전마다 str1을 초기화
	printf("strchr<str1, ch>\n    반환된 문자열 : %s\n\n\n", strchr(str1, ch));

	return 0;
}