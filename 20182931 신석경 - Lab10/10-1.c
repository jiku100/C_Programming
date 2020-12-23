#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct fraction {
	int numerator;
	int denominator;
};


int main(void) {
	struct fraction one;
	struct fraction two;

	printf("첫번째 분수<fraction>의 분모와 분자를 차례로 입력하시오 >> ");
	scanf("%d %d", &one.numerator, &one.denominator);
	printf("첫번째 분수<fraction>의 분모와 분자를 차례로 입력하시오 >> ");
	scanf("%d %d", &two.numerator, &two.denominator);

	printf("%d/%d + %d/%d = %d/%d\n", one.denominator, one.numerator, two.denominator, two.numerator, one.denominator + two.denominator, one.numerator + two.numerator);
	printf("%d/%d * %d/%d = %d/%d\n", one.denominator, one.numerator, two.denominator, two.numerator, one.denominator * two.denominator, one.numerator * two.numerator);
	return 0;
}