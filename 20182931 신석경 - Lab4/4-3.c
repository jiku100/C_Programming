/*
* 일차원 배열의 동등함을 검사하여 그 결과를 알아보는 프로그램
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	printf("일차원 배열의 동등함을 검사하여 결과 출력\n\n");

	int a[] = { 4, 7, 9, 3, 6 };
	int b1[] = { 4, 7, 9, 3, 6 };   // 같은 경우
	int b2[] = { 4, 7, 9, 3, 7 };   // 마지막 원소가 다른 경우
	int b3[] = { 4, 7, 9, 3, 6, 8 }; // 원소의 개수가 다른 경우

	int size = sizeof(a) / sizeof(a[0]);	// a 배열의 길이 저장

	int isequal = TRUE;	// 배열의 동등함을 저장하는 변수 

	printf("a[]  : ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d  ", a[i]);	// a원소 출력

	printf("\nb1[] : ");
	for (int i = 0; i < sizeof(b1) / sizeof(b1[0]); i++)
		printf("%d  ", b1[i]);	// b1원소 출력

	if(size != (sizeof(b1)/sizeof(b1[0])))
		isequal = FALSE;	// 두 배열의 길이가 다르면 FALSE

	if (isequal) {	// 두 배열의 길이가 같으면
		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			// a를 기준으로 b1의 동등함을 확인하는 과정
			if (b1[i] != a[i])	// 두 원소가 다르면
				isequal = FALSE;	// isequal == FALSE
		}
	}
	if (isequal == FALSE)
		printf("\n두 배열은 다르다.\n\n");
	else
		printf("\n두 배열은 같다.\n\n");

	isequal = TRUE;	// 다시 초기화




	printf("a[]  : ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d  ", a[i]);	// a원소 출력

	printf("\nb2[] : ");
	for (int i = 0; i < sizeof(b2) / sizeof(b2[0]); i++)
		printf("%d  ", b2[i]);	// b2원소 출력

	if (size != (sizeof(b2) / sizeof(b2[0])))
		isequal = FALSE;	// 두 배열의 길이가 다르면 FALSE

	if (isequal) {	// 두 배열의 길이가 같으면
		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			// a를 기준으로 b2의 동등함을 확인하는 과정
			if (b2[i] != a[i])	// 두 원소가 다르면
				isequal = FALSE;	// isequal == FALSE
		}
	}
	if (isequal == FALSE)
		printf("\n두 배열은 다르다.\n\n");
	else
		printf("\n두 배열은 같다.\n\n");

	isequal = TRUE;	// 다시 초기화



	printf("a[]  : ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d  ", a[i]);	// a원소 출력

	printf("\nb3[] : ");
	for (int i = 0; i < sizeof(b3) / sizeof(b3[0]); i++)
		printf("%d  ", b3[i]);	// b3원소 출력
	
	if (size != (sizeof(b3) / sizeof(b3[0])))
		isequal = FALSE;	// 두 배열의 길이가 다르면 FALSE

	if (isequal) {	// 두 배열의 길이가 같으면
		for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
			// a를 기준으로 b3의 동등함을 확인하는 과정
			if (b3[i] != a[i])	// 두 원소가 다르면
				isequal = FALSE;	// isequal == FALSE
		}
	}
	if (isequal == FALSE)
		printf("\n두 배열은 다르다.\n\n");
	else
		printf("\n두 배열은 같다.\n\n");

	return 0;
}