/*
* 의 문자열에 뒤 문자열을 연결하는 함수 mystrcat()를 구현하여 
* 라이브러리 함수 strcat() 과 결과를 비교
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void mystrcat(char s1[], const char s2[]);	// mystrcat

int main(void) {
	char s1[50] = "C ";
	char s2[50] = "C ";
	char* s3 = "programming language";
	

	printf("첫번째 문자열 : %s\n", s1);
	printf("두번째 문자열 : %s\n", s3);
	strcat(s1, s3);		// s1에 s3를 strcat 실행
	mystrcat(s2, s3);	// s2에 s3를 mystrcat 실행
	printf("문자열 연결 결과\n");
	printf("strcat<> : %s\n", s1);	// s1 출력
	printf("mystrcat<> : %s\n", s2);	// s2 출력
	return 0;
}

void mystrcat(char s1[], const char s2[]) {
	while (*s1)	// null 문자까지 s1 포인터 증가
		s1++;
	// s1의 null문자부터
	while ((*s1++ = *s2++) != '\0');	// s2의 값을 s1으로 복사 -> 복사한 값이 null이면 종료
}