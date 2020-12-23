#include <stdio.h>

void selectionSort(int* ary, int arysize);
void printAry(int* ary, int arysize);

int main(void) {
	int ary[] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };
	int arysize = sizeof(ary) / sizeof(ary[0]);
	printf("선택 정렬<Selection Sorting> ....\n");
	printf("정렬 전 순서\n");
	printAry(ary, arysize);
	selectionSort(ary, arysize);
	printf("\n정렬 후 순서\n");
	printAry(ary, arysize);
	return 0;
}

void selectionSort(int* ary, int arysize) {
	for (int i = 0; i < arysize - 1; i++) {
		int min = i;
		for (int j = i + 1; j < arysize; j++) {
			if (ary[j] < ary[min]) {
				min = j;
			}
		}
		int temp = ary[i];
		ary[i] = ary[min];
		ary[min] = temp;
	}
}

void printAry(int* ary, int arysize) {
	for (int i = 0; i < arysize; i++) {
		printf("%4d", ary[i]);
	}
	printf("\n");
}