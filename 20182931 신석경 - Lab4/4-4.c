/*
* 배열을 사용하여 배열의 총합과 평균을 구하여 출력하는 프로그램을 
*/

#include <stdio.h>

int main(void) {
	printf("배열을 사용하여 배열의 총합과 평균을 구하여 출력\n\n");

	float a[] = { 98.56, 78.62, 78.69, 89.32, 95.29 };

	float sum = 0, mean = 0;	// 총합과 평균 초기화
	printf("배열의 원소 :  ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%.2f ", a[i]);		// a원소 출력
		sum += a[i];	// 총합에 원소값 추가
	}

	mean = sum / (sizeof(a) / sizeof(a[0]));	// 총합을 원소 개수로 나눠 평균 구하기
	printf("\n배열의 합 = %.2f", sum);
	printf("\n평균 = %.2f\n\n", mean);
	
	return 0;
}