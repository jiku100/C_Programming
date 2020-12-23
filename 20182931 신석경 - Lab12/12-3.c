#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <stdarg.h>

void vstrcat(char* str, ...);  // 가변인자를 가지는 문자열  연결 함수

int main(void) {
	char str[50] = { NULL };
	char* words[] = { "C", " programming", " course", " in", " Chung", " Ang", " University" };
	vstrcat(str, 1, words[0]);	// 가변 인자 개수와 그에 해당하는 개수의 문자열 전달
	printf("%s\n", str);
	vstrcat(str, 2, words[1], words[2]);
	printf("%s\n", str);
	vstrcat(str, 1, words[3]);
	printf("%s\n", str);
	vstrcat(str, 3, words[4], words[5], words[6]);
	printf("%s\n", str);
	return 0;
}

void vstrcat(char* str, ...) {
	va_list argp;

	va_start(argp, str);
	int count = va_arg(argp, int);	// 가변 인자 개수를 알기 위해서 가변 인자 개수를 전달해줘야 함
	for (int i = 0; i < count; i++) {
		strcat(str, va_arg(argp, char*));
	}
	va_end(argp);
}