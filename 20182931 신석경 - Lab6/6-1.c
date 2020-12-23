/*
* 일차원 배열의 동등함을 검사하여 그 결과를 알아보는 프로그램
*/

#include <stdio.h>

void displayarray(int ary[], int size);	//display array elemnet
int isequalarray(int a[], int b[], int asize, int bsize);  // compare array a with b, return 1 or 0

int main(void) {
	int a[] = { 4, 7, 9, 3, 6 };
	int b1[] = { 4, 7, 9, 3, 6 };   // 같은 경우
	int b2[] = { 4, 7, 9, 3, 7 };   // 마지막 원소가 다른 경우
	int b3[] = { 4, 7, 9, 3, 6, 8 }; // 원소의 개수가 다른 경우

	printf("a[]   : ");
	displayarray(a, sizeof(a) / sizeof(int));	// 행렬 출력
	printf("b1[]  : ");
	displayarray(b1, sizeof(b1) / sizeof(int));	// 행렬 출력
	isequalarray(a, b1, sizeof(a) / sizeof(int), sizeof(b1) / sizeof(int));	// 비교

	printf("a[]   : ");
	displayarray(a, sizeof(a) / sizeof(int));	// 행렬 출력
	printf("b2[]  : ");
	displayarray(b2, sizeof(b2) / sizeof(int));	// 행렬 출력
	isequalarray(a, b2, sizeof(a) / sizeof(int), sizeof(b2) / sizeof(int));	// 비교

	printf("a[]   : ");
	displayarray(a, sizeof(a) / sizeof(int));	// 행렬 출력
	printf("b3[]  : ");
	displayarray(b3, sizeof(b3) / sizeof(int));	// 행렬 출력
	isequalarray(a, b3, sizeof(a) / sizeof(int), sizeof(b3) / sizeof(int));	// 비교
	return 0;
}


void displayarray(int ary[], int size) {	// 행렬 출력
	for (int i = 0; i < size; i++)
		printf("%3d", ary[i]);
	printf("\n");
}

int isequalarray(int a[], int b[], int asize, int bsize) {
	if (asize != bsize) {	// 길이가 다르면 다름
		printf("두 배열은 다르다.\n\n");
		return -1;
	}
	else {	// 배열의 길이가 같을 때
		for (int i = 0; i < asize; i++) {
			if (a[i] != b[i]) {	 // 같은 index의 원소가 다르면 다름
				printf("두 배열은 다르다.\n\n");
				return -1;
			}
		}
	}

	printf("두 배열은 같다.\n\n");
	return 0;
}