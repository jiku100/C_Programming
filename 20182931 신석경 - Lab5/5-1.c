/*
* 임의의 실수와 정수, m 과 n을 입력 받아 다음과 같은 mypow() 함수를 작성하여
* mn의 결과를 출력하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double mypow(double m, int n);	// 제곱 함수정의

int main(void) {
	printf("실수 m을 n번 제곱합니다.\n\n");

	double m;
	int n;	// 변수 저장 

	printf("실수와 정수를 차례로 입력하시오. >> ");
	scanf("%lf %d", &m, &n);
	printf("pow<%.2f, %d> 호출 : %.2f의 %d 제곱은 %.2f\n", m, n, m, n, pow(m, n));
	printf("mypow<%.2f, %d> 호출 : %.2f의 %d 제곱은 %.2f\n", m, n, m, n, mypow(m, n));

	return 0;
}

double mypow(double m, int n) {
	double temp = 1;
	for (int i = 0; i < n; i++) {	// m의 n제곱
		temp *= m;
	}
	return temp;
}