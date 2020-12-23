/*
* 이자 계산방식을 참고로 각각에 해당하는 함수를 만들어, 표준입력으로 원금, 이자율, 기간(년)을 입력하면 
* 총액이 각각 출력되는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double mypow(double m, int n);	// 제곱 함수정의
double simpleRate(int money, int years, double rate);	// 단리 계산
double compoundRate(int money, int years, double rate);	// 복리 계산


int main(void) {
	int money;	// 원금
	int years;		// 년수
	double rate;		// 이율

	while (1) {
		printf("이자를 계산할 다음 세 항목을 입력하세요.\n");
		printf("1. 원금 -> "); scanf("%d", &money);
		printf("2. 년 -> "); scanf("%d", &years);
		printf("3. 이율<%%> -> "); scanf("%lf", &rate);

		printf("단리 계산 총액은 %.2lf 입니다.\n", simpleRate(money, years, rate));
		printf("복리 계산 총액은 %.2lf 입니다.\n\n", compoundRate(money, years, rate));
	}
}

double mypow(double m, int n) {
	double temp = 1;
	for (int i = 0; i < n; i++) {	// m의 n제곱
		temp *= m;
	}
	return temp;
}

double simpleRate(int money, int years, double rate) {	// 단리 일 경우
	return money * (1 + (rate/100.) * years);
}
double compoundRate(int money, int years, double rate) {	// 복리 일 경우
	return money * mypow((1 + (rate / 100.)), years);
}
