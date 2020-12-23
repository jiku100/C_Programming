/*
* 일차원 배열을 복사하여 결과를 알아보는 프로그램
*/
#include <stdio.h>

int main(void) {
	printf("일차원 배열을 복사\n\n");

	int a[] = { 4, 7, 9, 3, 6 };
	int b[] = { 10, 20, 30, 40, 50, 60 };

	printf("배열 a[] : ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)	// a의 원소 출력
		printf("%d ", a[i]);

	printf("\n배열 b[] : ");
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)	// b의 원소 출력
		printf("%d ", b[i]);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)	// a의 원소 b로 복사
		b[i] = a[i];	// a[i]의 원소를 b[i] 원소로 복사

	printf("\n복사 후 배열 b[] : ");
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)	// b의 원소 출력
		printf("%d ", b[i]);
	printf("\n");
	return 0;

}