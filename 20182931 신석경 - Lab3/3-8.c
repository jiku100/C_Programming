/*
* 변수와 포인터를 사용하여 표준 입력을 받고 그에 대한 사칙연산을 수행하는 프로그램 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	printf("변수와 포인터를 사용하여 표준 입력을 받고 그에 대한 사칙연산을 수행\n\n");

	double x, y;	// 두 변수 선언
	double* px = &x;	// x를 가리킬 포인터 변수 선언
	double* py = &y;	// y를 가리킬 포인터 변수 선언

	printf("두 실수 입력: ");
	scanf("%lf %lf", px, py);		// px, py의 값은 x, y의 주소값이므로 x, y에 해당 실수 저장

	// 각각의 사칙연산을 수행

	printf("%.2f + %.2f = %.2f\n", *px, *py, *px + *py);
	printf("%.2f - %.2f = %.2f\n", *px, *py, *px - *py);
	printf("%.2f * %.2f = %.2f\n", *px, *py, *px * *py);
	printf("%.2f / %.2f = %.2f\n\n", *px, *py, *px / *py);

	return 0;
}