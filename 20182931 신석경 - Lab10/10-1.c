#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct fraction {
	int numerator;
	int denominator;
};


int main(void) {
	struct fraction one;
	struct fraction two;

	printf("ù��° �м�<fraction>�� �и�� ���ڸ� ���ʷ� �Է��Ͻÿ� >> ");
	scanf("%d %d", &one.numerator, &one.denominator);
	printf("ù��° �м�<fraction>�� �и�� ���ڸ� ���ʷ� �Է��Ͻÿ� >> ");
	scanf("%d %d", &two.numerator, &two.denominator);

	printf("%d/%d + %d/%d = %d/%d\n", one.denominator, one.numerator, two.denominator, two.numerator, one.denominator + two.denominator, one.numerator + two.numerator);
	printf("%d/%d * %d/%d = %d/%d\n", one.denominator, one.numerator, two.denominator, two.numerator, one.denominator * two.denominator, one.numerator * two.numerator);
	return 0;
}