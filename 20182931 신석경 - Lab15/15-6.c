#include <stdio.h>

void insertionSort(int* ary, int arysize);
void printAry(int* ary, int arysize);

int main(void) {
	int ary[] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };
	int arysize = sizeof(ary) / sizeof(ary[0]);
	printf("선택 정렬<Insertion Sorting> ....\n");
	printf("정렬 전 순서\n");
	printAry(ary, arysize);
	insertionSort(ary, arysize);
	printf("\n정렬 후 순서\n");
	printAry(ary, arysize);
	return 0;
}

void insertionSort(int* ary, int arysize) {
	for (int i = 1; i < arysize; i++) {
		int cur = ary[i];
		int j = i - 1;
		while (j >= 0 && ary[j] > cur) {
			ary[j + 1] = ary[j];
			j--;
		}
		ary[j + 1] = cur;
	}
}

void printAry(int* ary, int arysize) {
	for (int i = 0; i < arysize; i++) {
		printf("%4d", ary[i]);
	}
	printf("\n");
}