/*
* 표준입력으로 받은 int형의 두 정수의 사칙 연산을 수행하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	printf("double 형 변수에 int 2개를 저장하여 사칙연산 수행\n\n");

	double input;	// double 형 8바이트 변수 선언
	int* p = (int*)&input;	// 형변환을 통해 input을 int형 포인터로 접근


	printf("두 정수 입력: ");
	scanf("%d %d", p, p+1);	// int* 이므로 p + 1은 4바이트 이동한 구간에 저장

	// 각각의 사칙연산을 수행
	// *p 는 앞의 4바이트 정수, *(p+1)은 뒤의 4바이트 정수를 참조함
	printf("%d + %d = %d\n", *p, *(p+1), *p + *(p + 1));
	printf("%d - %d = %d\n", *p, *(p + 1), *p - *(p + 1));
	printf("%d * %d = %d\n", *p, *(p + 1), *p * *(p + 1));
	printf("%d / %d = %d\n\n", *p, *(p + 1), *p / *(p + 1));

	return 0;
}