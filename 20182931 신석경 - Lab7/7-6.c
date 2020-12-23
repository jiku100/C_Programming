/*
* 5번 문제에서 직접 구현한 함수 myatoi()를 이용하여 명령행에 입력된 두 정수를 더한 
* 결과를 출력하는 프로그램
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int myatoi(const char* str);	// myatoi

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("다음과 같이 실행 파일과 두개의 정수를 입력하시오.\n");
		printf("C:\> 실행파일 100 200\n");
		return 0;
	}
	else {
		int num1 = myatoi(argv[1]);	// 첫번째 인자 숫자로 변경
		int num2 = myatoi(argv[2]);	// 두번째 인자 숫자로 변경

		int sum = num1 + num2;

		printf("\n입력한 두 수의 덧셈 결과 : %d + %d = %d\n\n", num1, num2, sum);
	}
	return 0;
}

int myatoi(const char* str) {
	int n = strlen(str);	// 문자열 길이 구함
	int sum = 0;
	for (int i = 0; str[i]; i++) {
		if (isdigit(str[i])) {	// 문자가 숫자이면	
			sum += (str[i] - 48) * pow(10, (n - i - 1));	// 숫자로 바꾸고 10의 제곱수를 곱해 알맞은 자릿수로 바꿈
		}
	}
	return sum;
}