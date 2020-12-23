/*
* 주어진 문장으로부터 단어를 추출하여 배열에 저장하고, 배열에 저장된 단어를 출력하는 프로그램
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[] = "C and C++ languages are good!, Java and python languages are best?";
	char des[] = " ,!?";
	char* token[64];	// 토큰을 저장할 포인터 배열

	printf("문자열을 구분자를 이용하여 토큰 추출...\n");
	printf(" 문자열 : \"%s\"\n", str);
	printf(" 구분자 : \"%s\"\n", des);

	char* ptr = strtok(str, des);	// des에 있는 구분자로 첫 토큰 분리
	int i = 0;
	while (ptr != NULL) {	// 분리한 것이 있으면
		token[i] = ptr;	// token[i]에 저장
		ptr = strtok(NULL, des);	// 그 다음부터 토큰 분리
		i++;
	}
	token[i] = '\0';	// 토큰 분리 마지막에 NULL문자 추가
	i = 0;

	while (token[i]) {	// NULL문자 전까지
		printf("%s\n", token[i]);	// 토큰 출력
		i++;
	}
	return 0;
}