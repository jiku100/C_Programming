#include <stdio.h>
#include <stdarg.h>
#include <string.h>

double vafunc(char* type, int count, ...);

int main(void) {
	printf("평균 %.2f\n\n", vafunc("d", 5, 172, 21, 36, 43, 58));
	printf("평균 %.2f\n\n", vafunc("f", 5, 5.8, 17.3, 2.8, 31.8, 45.9, 5.9));
	return 0;
}


double vafunc(char* type, int count, ...)
{
	va_list argp;

	va_start(argp, count);
	double result = 0;
	if (strcmp(type, "d") == 0) {
		printf("정수 데이터 ");
		int total = 0;
		int temp;
		for (int i = 0; i < count; i++) {
			temp = va_arg(argp, int);
			total += temp;
			printf("%4d ", temp);
		}
		result = ((float)total) / count;
	}
	else if (strcmp(type, "f") == 0) {
		printf("실수 데이터 ");
		float total = 0;
		float temp;
		for (int i = 0; i < count; i++) {
			temp = va_arg(argp, double);
			total += temp;
			printf("%6.2f ", temp);
		}
		result = total / count;
	}
	else {
		printf("알맞은 타입이 아닙니다.");
	}
	printf("\n");
	return result;
}