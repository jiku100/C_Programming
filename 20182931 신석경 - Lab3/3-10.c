/*
* 주어진 문자열에 대문자, 소문자, 숫자, 특수문자가 각각 몇개인지 구하는 프로그램
*/

#include <stdio.h>

int main(void) {
	printf("라이브러리를 사용하지 않고 주어진 문자열의 구성을 파악\n\n");

	char* str = "abC*12dE3%4";	// 문자열 정의
	int upper = 0, lower = 0, number = 0, special = 0; 
	// 각각 대문자, 소문자, 숫자, 특수 문자에 대한 개수 초기화
	char temp;	// 하나의 문자를 저장하기 위한 임시 변수

	printf("문자열 %s\n\n", str);
	int i = 0;
	while (*(str + i) != NULL) {	
		// 문자가 NULL이 아니면 (문자열 마지막에 NULL이 있으므로 NULL전까지 검사)

		temp = *(str + i);	// 하나의 문자 저장

		if (temp >= 'A' && temp <= 'Z') {	// 대문자이면
			upper++;	// upper 개수 1 증가
		}
		else if (temp >= 'a' && temp <= 'z') {	// 소문자이면
			lower++;	// lowere 개수 1 증가
		}
		else if (temp >= '0' && temp <= '9') {	// 숫자이면
			number++;	// number 개수 1 증가
		}
		else {		// 나머지 즉 특수 문자이면
			special++;	// special 개수 1 증가
		}

		i++;	// 그 다음 문자로 이동
	}

	printf("대문자는 %d개\n", upper);	// 대문자 개수 출력
	printf("소문자는 %d개\n", lower);	// 소문자 개수 출력
	printf("숫자는 %d개\n", number);	// 숫자 개수 출력
	printf("특수문자는 %d개\n", special);	// 특수문자 개수 출력

	printf(">>> 전체 문자수는 %d개 입니다.\n\n", upper + lower + number + special);	// 전체 개수 출력
	return 0;

}