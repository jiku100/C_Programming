#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

double add(double, double);
double subtract(double, double);
double multiply(double, double);
double devide(double, double);

int main(void) {
	double (*fp[4])(double, double) = { add, subtract, multiply, devide };

	float input1, input2;
	char op;

	do
	{
		printf("사칙연산을 수행할 수식을 입력하시오<예: 4.5 + 3.7> >> ");
		scanf("%f %c %f", &input1, &op, &input2);
		if (op == '+') {
			printf("%.2f %c %.2f = %.2f\n", input1, op, input2, (*fp[0])(input1, input2));
		}
		else if (op == '-') {
			printf("%.2f %c %.2f = %.2f\n", input1, op, input2, (*fp[1])(input1, input2));
		}
		else if (op == '*') {
			printf("%.2f %c %.2f = %.2f\n", input1, op, input2, (*fp[2])(input1, input2));
		}
		else if (op == '/') {
			printf("%.2f %c %.2f = %.2f\n", input1, op, input2, (*fp[3])(input1, input2));
		}
		else {
			printf("?? 연산자 오류: %c\n", op);
		}
	} while (1);
	return 0;
}

double add(double a, double b) {
	return a + b;
}
double subtract(double a, double b) {
	return a - b;
}
double multiply(double a, double b) {
	return a * b;
}
double devide(double a, double b) {
	if (b == 0) {
		return 0;
	}
	else {
		return a / b;
	}
}