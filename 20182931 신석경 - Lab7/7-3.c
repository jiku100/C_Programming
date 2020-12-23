/*
* 표준입력으로 받은 문자열에서 특정 문자를 삭제하는 함수 delchar()를 구현하시오. 
* 그리고 함수 delchar()를 호출하여 수행하고 결과를 출력하는 프로그램
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void delchar(char str[], const char ch);

int main(void) {
	char str[64];
	char ch;
	printf("문자열을 입력하시오 >> ");
	fgets(str, 64, stdin);
	printf("삭제할 문자를 입력하시오 >> ");
	scanf(" %c", &ch);
	delchar(str, ch);	// 문자열에서 ch에 해당하는 모든 문자 제거
	printf("delchar<> 호출 이후 결과: %s\n", str);
	return 0;
}

void delchar(char str[], const char ch) {
	char* temp = NULL;	// 삭제 위치 저장하기 위한 변수
	while (*str != '\0') {	// null이 아닌 경우
		if (*str == ch) {	// 삭제할 문자이면
			temp = str;		// 삭제할 위치 저장
			while (*str) {	// null 문자 전까지
				*str = *(str + 1);	// 다음 문자를 앞으로 땡김
				str++;	// 문자열 위치 증가
			}
			str = temp;	// 삭제한 위치 복구
		}
		else {	// 아니면
			str++;	// 그 다음 문자부터 검사
		}	
	}
}