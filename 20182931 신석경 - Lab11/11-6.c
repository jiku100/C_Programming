#include <stdio.h>
#include <stdarg.h>

double vcountsum(int numagrs, ...);

int main(void) {
	printf("데이타들의 합 : %.2f\n\n", vcountsum(3, 12.3, 23.67, 10.5));
	printf("데이타들의 합 : %.2f\n\n", vcountsum(5, 20.75, 51.3, 21.9, 5.56, 12.34));
	return 0;
}
double vcountsum(int numagrs, ...)
{
	va_list argp;

	va_start(argp, numagrs);
	printf("가변 데이터 : ");

	double total = 0; 
	double temp;
	for (int i = 0; i < numagrs; i++) {
		temp = va_arg(argp, double);
		total += temp;
		printf("%6.2f ", temp);
	}
	printf("\n");

	va_end(argp);

	return total;
}