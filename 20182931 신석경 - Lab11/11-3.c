#include <stdio.h>

void print(double* x, int size);
double findmin(double* a, int size);
double findmax(double* a, int size);
double diffminmax(double* a, int size);


int main(void) {
	double a[5] = { 3.12, 5.14, 7.25, 7.48, 5.91 };
	int size = sizeof(a)/sizeof(double);
	printf("�迭 a�� ����\n");
	print(a, size);
	printf("\n\n�迭 a ������ �ִ밪 %.2f�� �ּҰ� %.2f�� ���̴� %.2f.\n", findmax(a, size), findmin(a, size), diffminmax(a, size));
	return 0;
}


void print(double* x, int size) {
	for (int i = 0; i < size; i++) {
		printf("%6.2f", x[i]);
	}
}

double findmin(double* a, int size) {
	double min = a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

double findmax(double* a, int size) {
	double max = a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

double diffminmax(double* a, int size) {
	double min = a[0], max = a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] < min) {
			min = a[i];
		}
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max - min;
}



